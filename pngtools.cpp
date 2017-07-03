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
#include "pngtools.h"
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern uint8_t *pngimg;
extern uint32_t pnglen;
extern FILE *fd;
PNGTools::PNGTools() {}

int32_t PNGTools::check_png() {}

int32_t PNGTools::get_pngdata(char_t *name) {
  node_t *node = null;
  if (name == null) {
    printf("No choose PNG file！\n");
    return 0;
  }
  png_open((char *)name);
  png_read();
  png_list = gen_list();
  png_list->data->length = 0;
  png_list->data->magic = read_4byte();
  png_list->data->data = null;
  png_list->data->crc = read_4byte();
  png_list->data->flag = PNG_FLAG_HEAD;
  do {
    node->data->length = read_4byte();
    node->data->magic = read_4byte();
    node->data->data = read_data(node->data->length);
    node->data->crc = read_4byte();
    listadd_tail(png_list, node);
  } while (node->data->length != 0 && node->data->data != null);
  if (!this->check_png(png_list)) {
    printf("png format error!\n");
    return 0;
  }
}

uint32_t PNGTools::merge_png(char_t *name, uint8_t frames) {
  uint8_t *buffer = null;
}

uint32_t PNGTools::parse_png(char_t *name, uint8_t frames) {
  uint8_t *buffer = null;
  if (name == null) {
    printf("No choose PNG file！\n");
    return 0;
  }
  png_open((char *)name);
}

PNGTools::~PNGTools() {}
