// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t* list_alloc() { 
  list_t* l = malloc(sizeof(list_t));

  l->head = NULL;

  return l;
}

void free_nodes(node_t* node_ptr) {

  if(!node_ptr) {
    return;
  }

  if(node_ptr->next) {
    free_nodes(node_ptr->next);
  }

  free(node_ptr);
}

void list_free(list_t *l) {

  node_t* head = l->head;

  free_nodes(head);

  free(l);
}



char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

void list_print(list_t *l) {
  char* listStringP = listToString(l);
  printf("Linked List: %s\n", listStringP);
}

int list_length(list_t *l) {
  node_t* cur_node = l->head;
  int length = 0;

  while (cur_node != NULL) {
    length += 1;
    cur_node = cur_node->next;
  } 

  return length;
}

void list_add_to_back(list_t *l, elem value) {
  node_t* cur_node = l->head;

  node_t* add_node = malloc(sizeof(node_t));

  add_node->value = value;

  if (cur_node == NULL) {
    l->head = add_node;
    return;
  }

  while (cur_node->next != NULL) {
    cur_node = cur_node->next;
  }
  cur_node->next = add_node;
  return;
}

void list_add_to_front(list_t *l, elem value) {
  node_t* prev_head = l->head;

  node_t* add_node = malloc(sizeof(node_t));
  add_node->value = value;
  add_node->next = prev_head;

  l->head = add_node;
  return;
}

void list_add_at_index(list_t *l, elem value, int index) {
  node_t*  cur_node = l->head;

  if (index == 0) {
    list_add_to_front(l, value);
  }
  else if (index >= list_length(l)) {
    list_add_to_back(l, value);
  }
  else {
    node_t* add_node = malloc(sizeof(node_t));
    add_node->value = value;

    for (int i = 0; i < index - 1; i += 1) {
      cur_node = cur_node->next;
    }
    add_node->next = cur_node->next;
    cur_node->next = add_node;
  }

}

elem list_remove_from_back(list_t *l) {
  if(!l->head) {
    return -1;
  }
  node_t* cur_node = l->head;

  node_t* prev_node = NULL;

  while (cur_node->next != NULL) {
    prev_node = cur_node;
    cur_node = cur_node->next;
  } 

  elem value = cur_node->value;
  free(cur_node);

  prev_node->next = NULL;
 
  return value;
}
elem list_remove_from_front(list_t *l) { 
  if(!l->head) {
    return -1;
  }

  node_t* cur_node = l->head;

  elem value = cur_node->value;
  node_t* next_node = cur_node->next;

  l->head = next_node;

  free(cur_node);

  return value;
}
elem list_remove_at_index(list_t *l, int index) { 
     if(!l->head) {
      return -1;
    } 

  if (index == 0) {
    return list_remove_from_front(l);
  }
  else if (index >= list_length(l)) {
    return list_remove_from_back(l);
  }
  else {
    node_t* prev_node = NULL;
    node_t*  cur_node = l->head;
    for (int i = 0; i < index ; i += 1) {
      prev_node = cur_node;
      cur_node = cur_node->next;
    }
    prev_node->next = cur_node->next;
    elem value = cur_node->value;
    free(cur_node);
    return value;
  } 
}

bool list_is_in(list_t *l, elem value) { 
  node_t* cur_node = l->head;

  while (cur_node) {
    if (cur_node->value == value) {
      return true;
    }
    cur_node = cur_node->next;
  }

  return false;

}
elem list_get_elem_at(list_t *l, int index) { 
  if(!l->head) {
    return -1;
  }
  node_t* cur_node = l->head;
  
  for (int i = 0; i < index; i += 1) {
    if (cur_node->next) {
      cur_node = cur_node->next;
    }
  }

  return cur_node->value;
}
int list_get_index_of(list_t *l, elem value) { 
  node_t* cur_node = l->head;
  int index = 0;

  while (cur_node) {
    if (cur_node->value == value) {
      return index;
    }
    cur_node = cur_node->next;
    index += 1;
  }

  return -1;
}

