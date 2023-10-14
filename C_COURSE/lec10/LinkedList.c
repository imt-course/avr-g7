#include <stdio.h>
#include <stdlib.h>
#include "StdTypes.h"
#include "LinkedList.h"

void LinkedList_Print(Node_t* head)
{
    if (NULL_PTR == head)
    {
        printf("Linked List is Empty");
    }
    while (NULL_PTR != head)
    {
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node_t* LinkedList_InsertLast(Node_t** head, u32 data)
{
    Node_t* currentNode = *head;
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    newNode->next = NULL_PTR;
    newNode->data = data;
    if (NULL_PTR == *head)
    {
        *head = newNode;
    }
    else
    {
        while(1)
        {
            if (currentNode->next == NULL_PTR)
            {
                currentNode->next = newNode;
                break;
            }
            else
            {
                currentNode = currentNode->next;
            }
        }
    }
    return newNode;
}

Node_t* LinkedList_InsertFirst(Node_t** head, u32 data)
{
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return newNode;
}

Node_t* LinkedList_InsertAtIndex(Node_t** head, u32 data, u32 index)
{
    Node_t* currentNode = *head;
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    newNode->data = data;
    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else 
    {
        index--;
        while (index > 0)
        {
            currentNode = currentNode->next;
            index--;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    return newNode;
}

void LinkedList_DeleteNode(Node_t** head, Node_t* node)
{
    Node_t* currentNode = *head;
    if (node == *head)
    {
        *head = (*head)->next;
    }
    else
    {
        while (1)
        {
            if (currentNode->next == node)
            {
                currentNode->next = (currentNode->next)->next;
                break;
            }
            currentNode = currentNode->next;
        }
    }
    free(node);
}

void LinkedList_DeleteAllNodes(Node_t** head)
{
    Node_t* currentNode = *head;
    while (currentNode != NULL_PTR)
    {
        currentNode = currentNode->next;
        free(*head);
        *head = currentNode;
    }
}