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
#ifndef PHG_H_
#define PHG_H_
#include "typedef.h"

#define PNG_MAGIC_HEAD 0x89504E47
#define PNG_MAGIC_IHDR "IHDR"
#define PNG_MAGIC_cHRM "cHRM"
#define PNG_MAGIC_gAMA "gAMA"
#define PNG_MAGIC_sBIT "sBIT"
#define PNG_MAGIC_PLTE "PLTE"
#define PNG_MAGIC_bKGD "bKGD"
#define PNG_MAGIC_hIST "hIST"
#define PNG_MAGIC_tRNS "tRNS"
#define PNG_MAGIC_oFFs "oFFs"
#define PNG_MAGIC_pHYs "pHYs"
#define PNG_MAGIC_sCAL "sCAL"
#define PNG_MAGIC_IDAT "IDAT"
#define PNG_MAGIC_tIME "tIME"
#define PNG_MAGIC_tEXt "tEXt"
#define PNG_MAGIC_zTXt "zTXt"
#define PNG_MAGIC_fRAc "fRAc"
#define PNG_MAGIC_gIFg "gIFg"
#define PNG_MAGIC_gIFt "gIFt"
#define PNG_MAGIC_gIFx "gIFx"
#define PNG_MAGIC_IEND 0x49454E44

typedef enum png_flag {
  PNG_FLAG_HEAD = 1 << 0,
  PNG_FLAG_IHDR = 1 << 1,
  PNG_FLAG_cHRM = 1 << 2,
  PNG_FLAG_gAMA = 1 << 3,
  PNG_FLAG_sBIT = 1 << 4,
  PNG_FLAG_PLTE = 1 << 5,
  PNG_FLAG_bKGD = 1 << 6,
  PNG_FLAG_hIST = 1 << 7,
  PNG_FLAG_tRNS = 1 << 8,
  PNG_FLAG_oFFs = 1 << 9,
  PNG_FLAG_pHYs = 1 << 10,
  PNG_FLAG_sCAL = 1 << 11,
  PNG_FLAG_IDAT = 1 << 12,
  PNG_FLAG_tIME = 1 << 13,
  PNG_FLAG_tEXt = 1 << 14,
  PNG_FLAG_fRAc = 1 << 15,
  PNG_FLAG_gIFg = 1 << 16,
  PNG_FLAG_gIFt = 1 << 17,
  PNG_FLAG_gIFx = 1 << 18,
  PNG_FLAG_IEND = 1 << 19,
} png_flag_e;

typedef struct data_seg {
  uint32_t length;
  uint32_t magic;
  uint8_t *data;
  uint32_t crc;
  uint8_t crc_ret;
  png_flag_e flag;
} data_seg_t;

typedef struct ihdr_info {
  uint32_t width;
  uint32_t height;
  uint8_t depth;
  uint8_t cType;
  uint8_t cpsType;
  uint8_t fType;
  uint8_t iType;
} ihdr_info_t;

#endif
