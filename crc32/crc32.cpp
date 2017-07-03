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

#include "crc32.h"

#include <stdio.h>
static uint32_t CRC32[256];
static bool init = false;

static void gen_crc32() {
  uint32_t i, j;
  uint32_t crc;
  for (i = 0; i < 256; i++) {
    crc = i;
    for (j = 0; j < 8; j++) {
      if (crc & 1) {
        crc = (crc >> 1) ^ 0xEDB88320;
      } else {
        crc = crc >> 1;
      }
    }
    CRC32[i] = crc;
  }
}

uint32_t crc32(uchar_t *buf, uint32_t len) {
  uint32_t ret = 0xFFFFFFFF;
  uint32_t i;
  if (!init) {
    gen_crc32();
    init = true;
  }
  for (i = 0; i < len; i++) {
    ret = CRC32[((ret & 0xFF) ^ buf[i])] ^ (ret >> 8);
  }
  ret = ~ret;
  return ret;
}
