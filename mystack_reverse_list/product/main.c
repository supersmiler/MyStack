#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include "mystack.h"
#include "linked_list.h"

ELEMENT *list = NULL;


int printLinkedList(ELEMENT *listToPrint)
{
    ELEMENT *current = listToPrint;
    while (current != NULL && current->data != NULL)
    {
        printf("%d", *(int*)current->data);
        current = current->next;
    }

    return 0;
}

int reverseList(ELEMENT **listToReverse)
{
    ELEMENT *current = *listToReverse;
    //ELEMENT *prevCurrent = NULL;
    //ELEMENT *toRemove = NULL;
    int stackHandle = mystack_create(sizeof(int));
    while (current != NULL && current->data != NULL)
    {
        mystack_push(stackHandle, current->data);
        // toRemove = current;
        // prevCurrent = current;
        current = current->next;
        // RemoveElement(&list, toRemove, prevCurrent);
        
    }
    CleanList(listToReverse);
    // list = NULL;
    int data;
    mystack_pop(stackHandle, &data);
    //list = (ELEMENT *)malloc(sizeof(ELEMENT));
    *listToReverse = CreateNewElement(&data, sizeof(int), NULL);
    current = *listToReverse;
    while (mystack_pop(stackHandle, &data) == 0)
    {
        PushElementAfter(current, CreateNewElement(&data, sizeof(int), NULL));
        current = current->next;
    }

    mystack_destroy(stackHandle);
}

int main(int argc, char *argv[])
{
    list = (ELEMENT *)malloc(sizeof(ELEMENT));

    if (list == NULL)
    {
        return -1;
    }

    for (int i = 0; i < 2000; i++)
    {
        int obj = i;
        PushElementBefore(&list, list, NULL, CreateNewElement(&obj, sizeof(int), NULL));
    }
    printf("Normal list:\n");
    printLinkedList(list);
    reverseList(&list);
    printf("Reverse list:\n");
    printLinkedList(list);
    return 0;
}
