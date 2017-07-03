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

#ifndef PNGTOOLS_H_
#define PNGTOOLS_H_

#include "list.h"
#include "png.h"
#include "resource.h"
class PNGTools {

private:
  node_t *png_list;
  int32_t get_pngdata(char_t *name);
  int32_t check_png();

public:
  PNGTools();
  ~PNGTools();
  uint32_t merge_png(char_t *name, uint8_t frames);
  uint32_t parse_png(char_t *name, uint8_t frames);
  uint32_t insert_data(char_t *buffer);
  void create_png(int8_t *data, uint32_t length);
};

#endif
