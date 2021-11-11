// Copyright 2021 Jean Pierre Cimalando
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0
//

#include "ysfx_test_utils.hpp"
#include <sys/stat.h>
#include <unistd.h>
#include <system_error>
#include <cstdio>
#include <cstring>

std::string tests_root_path = "ysfx-test-tmp." + std::to_string(getpid());

static std::string resolve_path(const std::string &input)
{
    if (input.size() >= 7 && !memcmp(input.data(), "${root}", 7))
        return tests_root_path + '/' + input.substr(7);
    return input;
}

//------------------------------------------------------------------------------
scoped_new_dir::scoped_new_dir(const std::string &path_)
    : m_path(resolve_path(path_))
{
    if (mkdir(m_path.c_str(), 0755) != 0)
        throw std::system_error(errno, std::generic_category(), "mkdir");
}

scoped_new_dir::~scoped_new_dir()
{
    rmdir(m_path.c_str());
}

//------------------------------------------------------------------------------
scoped_new_txt::scoped_new_txt(const std::string &path_, const char *text, size_t size)
    : m_path(resolve_path(path_))
{
    FILE *stream = fopen(m_path.c_str(), "wb");
    if (size == ~(size_t)0)
        size = strlen(text);
    if (!stream)
        throw std::system_error(errno, std::generic_category(), "fopen");
    if (fwrite(text, 1, size, stream) != size) {
        fclose(stream);
        throw std::system_error(errno, std::generic_category(), "fputs");
    }
    if (fflush(stream) != 0) {
        fclose(stream);
        throw std::system_error(errno, std::generic_category(), "fflush");
    }
    fclose(stream);
}

scoped_new_txt::~scoped_new_txt()
{
    unlink(m_path.c_str());
}
