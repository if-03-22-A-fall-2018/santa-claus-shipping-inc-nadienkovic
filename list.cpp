#include <stdlib.h>
#include "list.h"

struct _node{
  void* data;
  Node* next;
};
struct _list{
   Node* _head;
};

List* list_create(){
  return (List*)malloc(sizeof(struct _list));
}
/**
 * Used to free all memory the supplied list allocated
 * (hint: list structure, including the list itself, but not the data!)
 */
void list_delete(List *list){
  free(list);
}

/**
 * Adds a new node with the supplied data to the start of the list
 */
void list_add(List *list, void *data){
  Node* newNode = (struct _node*)malloc(sizeof(struct _node));
  newNode->data = data;
  newNode->next = 0;
  if (list->_head == 0) {
    list->_head = newNode;
  }else{
    newNode->next = list->_head;
    list->_head = newNode;
  }
}

/**
 * Adds a new node with the supplied data after the supplied node
 */
void list_insert_after(Node *node, void *data){
  Node* newNode = (struct _node*)malloc(sizeof(struct _node));
  newNode->data = data;
  newNode->next= node->next;
  node->next= newNode;
}
/**
 * Return the head of the list
 */
Node* list_get_first(List *list){
  return list->_head;
}
/**
 * Returns the next node in the list
 * (hint: be careful if the last node in the list is supplied)
 */
Node* list_get_next(Node *node){
  return node->next;
}
/**
 * Retrieves the data stored in the supplied node
 * (hint: you'll probably won't be able to use this void* without casting)
 */
void* list_get_data(Node *node){
    return node->data;
}
