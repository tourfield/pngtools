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
#include "typedef.h"
#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char help_info[] = {"\
                   ----pngtools help----\n\n \
                   pngtools <file.png> [-mpn:i:d:o:fhD?] \n \
                   -m merge mutli frames png pictures \n \
                   -p parse mutli png picture into mutli pictures \n \
                   -n point out some info,ex.frames \n \
                   -i insert a segment data \n \
                   -d delete a segment data \n \
                   -o output file \n \
                   -f force run \n \
                   -D debug info \n \
                   -? help info \n \
                   "};

const char shortOptions[] = "mpn:i:d:o:fhD?";

const struct option longOptions[] = {
    /* name     has_arg         flag    val */
    {"merge", no_argument, NULL, 'm'},
    {"parse", no_argument, NULL, 'p'},
    {"frames", required_argument, NULL, 'n'},
    {"insert", required_argument, NULL, 'i'},
    {"delete", required_argument, NULL, 'd'},
    {"output", required_argument, NULL, 'o'},
    {"debug", no_argument, NULL, 'D'},
    {"force", no_argument, NULL, 'f'},
    {"help", no_argument, NULL, 'h'},
    {0, 0, 0, 0}};

int main(int argc, char **argv) {
  int32_t opt, i = 0;
  uint8_t flag = 0;
  uint8_t debug = 0;
  uint8_t force = 0;
  uint8_t frames = 0;
  char input[256] = {0};
  char output[256] = {0};
  char name[256] = {0};
  if (argc < 3) {
    printf("Please \"pngtools --help\" or \"pngtools -?\" to look for help\
 informent! \n");
    return -1;
  }
  printf("%s\n", argv[1]);
  while (argv[1][i] != '\0') {
    name[i] = tolower(argv[1][i]);
    i++;
  }
  printf("%s\n", name);
  if (strstr(name, "png") == null) {
    printf("Please choose a png file\n %s\n", help_info);
    return -1;
  }
  memset(name, 0, 256);
  strcpy(name, argv[1]);
  while ((opt = getopt_long(argc, argv, shortOptions, longOptions, null)) !=
         -1) {
    switch (opt) {
    case 'm':
      flag |= CMD_MERGE_PNG;
      break;
    case 'p':
      flag |= CMD_PARSE_PNG;
      break;
    case 'n':
      if (optarg != null) {
        frames = atoi(optarg);
      } else {
        printf("frames params error !\n %s\n", help_info);
        return -1;
      }
      break;
    case 'i':
      if (optarg != null) {
        strcpy(input, optarg);
        flag |= CMD_ISTDT_PNG;
      } else {
        printf("inster params error !\n %s\n", help_info);
        return -1;
      }
      break;
    case 'd':
      if (optarg != null) {
        strcpy(input, optarg);
        flag |= CMD_DLTDT_PNG;
      } else {
        printf("delete params error !\n %s\n", help_info);
        return -1;
      }
      break;
    case 'o':
      if (optarg != null) {
        strcpy(output, optarg);
      } else {
        printf("output params error !\n %s\n", help_info);
        return -1;
      }
      break;
    case 'D':
      debug = 1;
      break;
    case 'f':
      force = 1;
      break;
    case 'h':
    case '?':
    default:
      printf("%s\n", help_info);
      return 0;
    }
  }

  PNGTools *tools;
  if (CMD_MERGE_PNG == (flag & CMD_MERGE_PNG)) {
    printf("CMD_MERGE_PNG\n");
    tools->merge_png((char_t *)name, frames);
  } else if (CMD_PARSE_PNG == (flag & CMD_PARSE_PNG)) {
    printf("CMD_PARSE_PNG\n");
    tools->parse_png((char_t *)name, frames);
  }
  if (CMD_ISTDT_PNG == (flag & CMD_ISTDT_PNG)) {
    printf("CMD_ISTDT_PNG\n");
  }
  if (CMD_DLTDT_PNG == (flag & CMD_DLTDT_PNG)) {
    printf("CMD_DLTDT_PNG\n");
  }

  return 0;
}
