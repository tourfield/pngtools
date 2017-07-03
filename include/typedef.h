/*
 * Copyright (C) 2016 The PNGTOOLS Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TYPEDEF_H_
#define TYPEDEF_H_

typedef signed char char_t;
typedef unsigned char uchar_t;

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef signed short int16_t;
typedef unsigned short uint16_t;

typedef signed int int32_t;
typedef unsigned int uint32_t;

// typedef unsigned char bool;
#ifndef null
#define null 0
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#define CMD_PARSE_PNG 1 << 0
#define CMD_MERGE_PNG 1 << 1
#define CMD_ISTDT_PNG 1 << 2
#define CMD_DLTDT_PNG 1 << 3

#endif
