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
#include "resource.h"

uint8_t *pngimg = null;
uint32_t pnglen = 0;
FILE *fd = null;

FILE *png_open(const char *name) {

  if (null == name) {
    printf("open PNG file error\n");
    return null;
  }
  fd = fopen(name, "r");
  if (null == fd) {
    printf("fopen PNG file error! %s \n", strerror(errno));
    return null;
  }
  return fd;
}

uint32_t png_read() {
  uint32_t start, end;
  uint32_t length;
  uint8_t *buffer = null;
  if (null == fd) {
    printf("png_read error : fd = null\n");
    return -1;
  }
  start = fseek(fd, 0, SEEK_SET);
  end = fseek(fd, 0, SEEK_END);
  fseek(fd, 0, SEEK_SET);
  pnglen = end - start;

  buffer = (uint8_t *)malloc(pnglen);
  if (buffer == null) {
    printf("read error : %s\n", strerror(errno));
    return -1;
  }
  memset(buffer, 0, pnglen);
  length = fread(buffer, sizeof(char), pnglen, fd);
  if (length != pnglen) {
    printf("read data error :%s\n", strerror(errno));
    return -1;
  }
  pngimg = buffer;
  return 0;
}
uint32_t png_close() {
  fclose(fd);
  return 0;
}

void dump(uint8_t *buffer, uint32_t len) {
  if (null == buffer) {
    printf("%p\n", buffer);
    return;
  }
  for (size_t i = 0; i < len; i++) {
    if (i % 16 == 0) {
      printf("\n");
    }
    printf("%02x ", *(buffer + i));
  }
  printf("\n");
}

int32_t inverse_word(int32_t word) {
  int32_t result = 0;
  result |= (word & 0xFF000000) >> 24;
  result |= (word & 0x00FF0000) >> 8;
  result |= (word & 0x0000FF00) << 8;
  result |= (word & 0x000000FF) << 24;
  return result;
}

uint8_t read_byte() {
  if (fd == null) {
    printf("read_byte error! fd=%p\n", fd);
    return -1;
  }
  return getc(fd);
}

uint32_t read_4byte() {
  int value = 0;
  uint8_t len[4] = {0};
  if (fd == null) {
    printf("read_byte error! fd=%p\n", fd);
    return -1;
  }
  for (size_t i = 0; i < 4; i++) {
    char b = getc(fd);
    len[i] = (uint8_t)atoi(&b);
  }

  value |= (((uint32_t)len[0] << 24) & 0xff000000);
  value |= (((uint32_t)len[1] << 16) & 0x00ff0000);
  value |= (((uint32_t)len[2] << 8) & 0x0000ff00);
  value |= (((uint32_t)len[3]) & 0x000000ff);
  return value;
}

uint8_t *read_data(uint32_t len) {
  uint8_t *buffer = null;
  if (fd == null) {
    printf("read_byte error! fd=%p\n", fd);
    return null;
  }
  buffer = (uint8_t *)malloc(len);
  memset(buffer, 0, len);
  for (size_t i = 0; i < len; i++) {
    *(buffer + i) = (uint8_t)getc(fd);
  }
  return buffer;
}
// void buffer_to_list() {}
