/* Generated by re2c 2.2 on Wed Nov 10 19:06:23 2021 */
#line 1 "/home/jpc/documents/projects/ysfx/sources/ysfx_parse_filename.cpp.re"
/* -*- mode: c++; -*- */
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
#include <string>

bool ysfx_parse_filename(const char *line, ysfx_parsed_filename_t &filename)
{
    filename = ysfx_parsed_filename_t{};

    #line 31 "/home/jpc/documents/projects/ysfx/sources/ysfx_parse_filename.cpp.re"


    const char *YYCURSOR;
    const char *YYMARKER;

    
#line 37 "/home/jpc/documents/projects/ysfx/sources/ysfx_parse_filename.cpp"
const char* yyt1; const char* yyt2; 
#line 36 "/home/jpc/documents/projects/ysfx/sources/ysfx_parse_filename.cpp.re"


    //NOTE(jpc): parser intensionally very permissive

    #line 43 "/home/jpc/documents/projects/ysfx/sources/ysfx_parse_filename.cpp.re"


    YYCURSOR = line;

    //--------------------------------------------------------------------------
    // Parse Filename

    {
        const char *idx1, *idx2, *path1;

        
#line 56 "/home/jpc/documents/projects/ysfx/sources/ysfx_parse_filename.cpp"
{
	char yych;
	yych = *YYCURSOR;
	switch (yych) {
	case 'f':	goto yy4;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
yy3:
#line 64 "/home/jpc/documents/projects/ysfx/sources/ysfx_parse_filename.cpp.re"
	{
            return false;
        }
#line 71 "/home/jpc/documents/projects/ysfx/sources/ysfx_parse_filename.cpp"
yy4:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'i':	goto yy5;
	default:	goto yy3;
	}
yy5:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'l':	goto yy7;
	default:	goto yy6;
	}
yy6:
	YYCURSOR = YYMARKER;
	goto yy3;
yy7:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy8;
	default:	goto yy6;
	}
yy8:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'n':	goto yy9;
	default:	goto yy6;
	}
yy9:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'a':	goto yy10;
	default:	goto yy6;
	}
yy10:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'm':	goto yy11;
	default:	goto yy6;
	}
yy11:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy12;
	default:	goto yy6;
	}
yy12:
	yych = *++YYCURSOR;
	switch (yych) {
	case ':':	goto yy13;
	default:	goto yy6;
	}
yy13:
	yych = *++YYCURSOR;
	switch (yych) {
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
		yyt1 = YYCURSOR;
		goto yy14;
	default:	goto yy6;
	}
yy14:
	yych = *++YYCURSOR;
	switch (yych) {
	case '+':
	case '-':
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy14;
	case ',':	goto yy16;
	default:	goto yy6;
	}
yy16:
	yych = *++YYCURSOR;
	yyt2 = YYCURSOR;
	goto yy19;
yy17:
	idx1 = yyt1;
	path1 = yyt2;
	idx2 = yyt2 - 1;
#line 55 "/home/jpc/documents/projects/ysfx/sources/ysfx_parse_filename.cpp.re"
	{
             int64_t index = (int64_t)ysfx::dot_atof(std::string(idx1, idx2).c_str());
             if (index < 0 || index > ~(uint32_t)0)
                 return false;
             filename.index = (uint32_t)index;
             filename.filename = ysfx::trim(path1, &ysfx::ascii_isspace);
             goto end_filename;
        }
#line 283 "/home/jpc/documents/projects/ysfx/sources/ysfx_parse_filename.cpp"
yy18:
	yych = *++YYCURSOR;
yy19:
	if (yych <= 0x00) goto yy17;
	goto yy18;
}
#line 67 "/home/jpc/documents/projects/ysfx/sources/ysfx_parse_filename.cpp.re"


        end_filename: ;
    }

    return true;
}
