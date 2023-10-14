#include <stdio.h>
#include <stdlib.h>
#include "StdTypes.h"
#include "LinkedList.h"

const u16 x = 10;



int main (void)
{
    Node_t* head = NULL_PTR;
    Node_t* temp = NULL_PTR;
    LinkedList_Print(head); // Empty
    temp = LinkedList_InsertLast(&head, 10);
    LinkedList_Print(head); // 10
    LinkedList_InsertLast(&head, 5);
    LinkedList_Print(head); // 10 5
    LinkedList_InsertFirst(&head, 7);
    LinkedList_Print(head); // 7 10 5
    LinkedList_InsertLast(&head, 2);
    LinkedList_Print(head); // 7 10 5 2
    LinkedList_InsertLast(&head, 1);
    LinkedList_Print(head); // 7 10 5 2 1
    LinkedList_InsertAtIndex(&head, 8, 3);
    LinkedList_Print(head); // 7 10 5 8 2 1
    LinkedList_InsertAtIndex(&head, 2, 0);
    LinkedList_Print(head); // 2 7 10 5 8 2 1
    LinkedList_DeleteNode(&head, temp);
    LinkedList_Print(head); // 2 7 5 8 2 1
    LinkedList_DeleteAllNodes(&head);
    LinkedList_Print(head); // Empty



    /*const u16 y = 5;
    u16* ptrX = &x;
    u16* ptrY = &y;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    *ptrY = 2;
    printf("y = %d\n", y);
    *ptrX = 2;
    printf("x = %d\n", x);*/
    /*u32 n, i;
    u32* ptr = (u32*)malloc(4);
    printf("Please enter numbers count: ");
    scanf("%d", &n);
    ptr = (u32*)realloc(ptr, n*sizeof(u32));
    if (NULL_PTR != ptr) 
    {
        printf("Please enter numbers: ");
        for (i=0; i<n; i++)
        {
            scanf("%d", &ptr[i]);
        }
        printf("You entered: ");
        for (i=0; i<n; i++)
        {
            printf("%d, ", ptr[i]);
        }
        free(ptr);
    }
    else
    {
        printf("Couldn't reserve space for ptr");
    }*/






}