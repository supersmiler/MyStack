#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
    void *data;
    struct element *next;
} ELEMENT;

void ShowList(ELEMENT *list);
void CleanList(ELEMENT *list);
ELEMENT *CreateNewElement(void *data, size_t dataSize, ELEMENT *nextElement);
void PushElementAfter(ELEMENT *currentElement, ELEMENT *elementToAdd);
void PushElementBefore(ELEMENT *beginningElement, ELEMENT *currentElement, ELEMENT *prevElement, ELEMENT *elementToAdd);
void RemoveElement(ELEMENT *beginningElement, ELEMENT *elementToRemove, ELEMENT *prevElement);

#endif
