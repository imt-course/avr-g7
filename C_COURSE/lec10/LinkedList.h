#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "StdTypes.h"

typedef struct Node
{
    u32 data;
    struct Node* next;
} Node_t;

void LinkedList_Print(Node_t* head);
Node_t* LinkedList_InsertLast(Node_t** head, u32 data);
Node_t* LinkedList_InsertFirst(Node_t** head, u32 data);
Node_t* LinkedList_InsertAtIndex(Node_t** head, u32 data, u32 index);
void LinkedList_DeleteNode(Node_t** head, Node_t* node);
void LinkedList_DeleteAllNodes(Node_t** head);

#endif