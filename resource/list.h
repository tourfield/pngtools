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
#ifndef LIST_H_
#define LIST_H_

#include "png.h"

typedef struct node {
  data_seg_t *data;
  struct node *next;
  struct node *prev;
} node_t;

typedef enum list_return {
  LIST_RETURN_OK = 0,
  LIST_RETURN_CRTERR = -1, // create error
  LIST_RETURN_ISTERR = -2, // insert error
  LIST_RETURN_DLTERR = -3, // delete error
  LIST_RETURN_CHKERR = -4, // chech error
  LIST_RETURN_FTHERR = -5, // fetch error
} list_return_e;

node_t *gen_list(void);
node_t *get_empty(node_t *plist);
node_t *find_byname(node_t *plist, char_t *name);
int listadd_tail(node_t *plist, node_t *iterm);
int insert_node(node_t *plist, node_t *iterm, char_t *name);
int delete_node(node_t *plist, char_t *name);

#endif
