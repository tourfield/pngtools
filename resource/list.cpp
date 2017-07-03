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

#include "list.h"
#include "typedef.h"
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node_t *gen_list(void) {
  node_t *head;
  head = (node_t *)malloc(sizeof(node_t));
  if (head == null) {
    printf("Create list head error, malloc error :%s\n", strerror(errno));
    return null;
  }
  head->data = null;
  head->next = null;
  head->prev = head;

  return head;
}

node_t *get_empty(node_t *plist) {
  node_t *iterm = plist;
  while (iterm->next != null) {
    iterm = plist->next;
  }
  return iterm;
}

node_t *find_byname(node_t *plist, char_t *name) {
  node_t *iterm = null;
  if (null == plist || null == name) {
    printf("Connt find (%s) in plist(%p)\n", name, plist);
    return null;
  }
  iterm = plist;
  while (iterm->next == null) {
    if (memcmp((char_t *)&iterm->data->magic, name, 4) == 0) {
      return iterm;
    }
  }
  return null;
}

int listadd_tail(node_t *plist, node_t *iterm) {
  node_t *tail = null;
  if (null == plist || null == iterm) {
    printf("insert_iterm error! plist(%p) iterm(%p)\n", plist, iterm);
    return LIST_RETURN_CRTERR;
  }
  tail = get_empty(plist);
  iterm->prev = tail;
  iterm->next = null;
  tail->next = iterm;
  return LIST_RETURN_OK;
}

int insert_node(node_t *plist, node_t *iterm, char_t *name) {
  node_t *pos_node = null;
  if (plist == null || iterm == null) {
    printf("Insert error, plist(%p) iterm(%p)\n", plist, iterm);
    return LIST_RETURN_ISTERR;
  }
  pos_node = find_byname(plist, name);
  if (pos_node == null) {
    listadd_tail(plist, iterm);
  } else {
    pos_node->next->prev = iterm;
    iterm->next = pos_node->next;
    iterm->prev = pos_node;
    pos_node->next = iterm;
  }
  return LIST_RETURN_OK;
}

int delete_node(node_t *plist, char_t *name) {
  node_t *pos_node = null;
  if (plist == null || name == null) {
    printf("delete node error plist(%p) name(%p)\n", plist, name);
    return LIST_RETURN_DLTERR;
  }
  pos_node = find_byname(plist, name);
  if (pos_node != null) {
    pos_node->next = pos_node->next->next;
    pos_node->next->prev = pos_node;
    free(pos_node);
    pos_node = null;
  }
  return LIST_RETURN_OK;
}

void free_list(node_t *plist) {
  node_t *pos_node = get_empty(plist);
  while (null != pos_node) {
    pos_node->prev->next = null;
    if (pos_node->data != null) {
      free(pos_node->data);
      pos_node->data = null;
    }
    free(pos_node);
    pos_node = get_empty(plist);
  }
}
