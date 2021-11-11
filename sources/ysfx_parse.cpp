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

#include "ysfx_parse.hpp"
#include "ysfx_utils.hpp"
#include <cstring>

bool ysfx_parse_toplevel(ysfx::text_reader &reader, ysfx_toplevel_t &toplevel, ysfx_parse_error *error)
{
    toplevel = ysfx_toplevel_t{};

    ysfx_section_t *current = new ysfx_section_t;
    toplevel.header.reset(current);

    std::string line;
    uint32_t lineno = 0;

    line.reserve(256);

    while (reader.read_next_line(line)) {
        const char *linep = line.c_str();

        if (linep[0] == '@') {
            // a new section starts
            ysfx::string_list tokens = ysfx::split_strings_noempty(linep, &ysfx::ascii_isspace);

            current = new ysfx_section_t;

            if (tokens[0] == "@init")
                toplevel.init.reset(current);
            else if (tokens[0] == "@slider")
                toplevel.slider.reset(current);
            else if (tokens[0] == "@block")
                toplevel.block.reset(current);
            else if (tokens[0] == "@sample")
                toplevel.sample.reset(current);
            else if (tokens[0] == "@serialize")
                toplevel.serialize.reset(current);
            else if (tokens[0] == "@gfx") {
                toplevel.gfx.reset(current);
                long gfx_w = 0;
                long gfx_h = 0;
                if (tokens.size() > 1)
                    gfx_w = (long)ysfx::dot_atof(tokens[1].c_str());
                if (tokens.size() > 2)
                    gfx_h = (long)ysfx::dot_atof(tokens[2].c_str());
                toplevel.gfx_w = (gfx_w > 0) ? (uint32_t)gfx_w : 0;
                toplevel.gfx_h = (gfx_h > 0) ? (uint32_t)gfx_h : 0;
            }
            else {
                delete current;
                if (error) {
                    error->line = lineno;
                    error->message = std::string("Invalid section: ") + line;
                }
                return false;
            }
            current->line_offset = lineno + 1;
        }
        else {
            current->text.append(line);
            current->text.push_back('\n');
        }

        ++lineno;
    }

    return true;
}

void ysfx_parse_header(ysfx_section_t *section, ysfx_header_t &header)
{
    header = ysfx_header_t{};

    ysfx::string_text_reader reader(section->text.c_str());

    std::string line;
    //uint32_t lineno = section->line_offset;

    line.reserve(256);

    while (reader.read_next_line(line)) {
        const char *linep = line.c_str();

        ysfx_slider_t slider;
        ysfx_parsed_filename_t filename;

        if (!strncmp(linep, "desc:", 5))
            header.desc = ysfx::trim(linep + 5, &ysfx::ascii_isspace);
        else if (!strncmp(linep, "in_pin:", 7))
            header.in_pins.push_back(ysfx::trim(linep + 7, &ysfx::ascii_isspace));
        else if (!strncmp(linep, "out_pin:", 8))
            header.out_pins.push_back(ysfx::trim(linep + 8, &ysfx::ascii_isspace));
        else if (!strncmp(linep, "import", 6) && ysfx::ascii_isspace(linep[6]))
            header.imports.push_back(ysfx::trim(linep + 7, &ysfx::ascii_isspace));
        else if (ysfx_parse_slider(linep, slider)) {
            if (slider.id >= ysfx_max_sliders)
                continue;
            slider.exists = true;
            header.sliders[slider.id] = slider;
        }
        else if (ysfx_parse_filename(linep, filename)) {
            if (filename.index != header.filenames.size())
                continue;
            header.filenames.push_back(std::move(filename.filename));
        }

        //++lineno;
    }

    if (header.in_pins.size() == 1 && !ysfx::ascii_strcmp(header.in_pins.front().c_str(), "none"))
        header.in_pins.clear();
    if (header.out_pins.size() == 1 && !ysfx::ascii_strcmp(header.out_pins.front().c_str(), "none"))
        header.out_pins.clear();

    if (header.in_pins.size() > ysfx_max_channels)
        header.in_pins.resize(ysfx_max_channels);
    if (header.out_pins.size() > ysfx_max_channels)
        header.out_pins.resize(ysfx_max_channels);
}
