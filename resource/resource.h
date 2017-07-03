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
#ifndef RESOURCE_H_
#define RESOURCE_H_

#include "list.h"
#include "png.h"
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *png_open(const char *name);
uint32_t png_read();
uint32_t png_close();
void dump(uint8_t *buffer, uint32_t len);
int32_t inverse_word(int32_t word);
uint8_t read_byte();
uint32_t read_4byte();
uint8_t *read_data(uint32_t len);
#endif
