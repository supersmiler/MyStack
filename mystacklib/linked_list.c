
#include "linked_list.h"

void ShowList(ELEMENT *list)
{
    int i = 0;

    if (list == NULL)
    {
        printf("  <empty>\n");
    }
    else
    {
        ELEMENT *current = list;
        while (current != NULL)
        {
            printf("%d", *(int *)current->data);
            current = current->next;
            i++;
        }
    }
}

void CleanList(ELEMENT **list)
{
    if (list != NULL && *list != NULL)
    {
        ELEMENT *current = NULL;
        current = (*list);
        ELEMENT *toRemove = NULL;
        while (current != NULL)
        {
            toRemove = current;
            current = current->next;
            if (toRemove->data != NULL)
            {
                free(toRemove->data);
                toRemove->data = NULL;
            }
            free(toRemove);
            toRemove = NULL;
        }
    }
}

ELEMENT *CreateNewElement(void *data, size_t dataSize, ELEMENT *nextElement)
{
    ELEMENT *newElement = (ELEMENT *)malloc(sizeof(ELEMENT));
    newElement->data = malloc(dataSize);
    memcpy(newElement->data, data, dataSize);
    newElement->next = nextElement;
    return newElement;
}

void PushElementAfter(ELEMENT *currentElement, ELEMENT *elementToAdd)
{
    ELEMENT *nextElement = currentElement->next;
    ELEMENT *newElement = elementToAdd;
    newElement->next = nextElement;

    currentElement->next = newElement;
}

void PushElementBefore(ELEMENT **beginningElement, ELEMENT *currentElement, ELEMENT *prevElement, ELEMENT *elementToAdd)
{
    ELEMENT *nextElement = currentElement;
    ELEMENT *newElement = elementToAdd;
    newElement->next = nextElement;
    if (prevElement == NULL)
    {
        *beginningElement = newElement;
    }
    else
    {
        prevElement->next = newElement;
    }
}

void RemoveElement(ELEMENT **beginningElement, ELEMENT *elementToRemove, ELEMENT *prevElement)
{
    if (beginningElement == NULL || elementToRemove == NULL)
    {
        return;
    }
    if (prevElement != NULL)
    {
        ELEMENT *nextElement = elementToRemove->next;
        prevElement->next = nextElement;
    }
    else
    {
        *beginningElement = elementToRemove->next;
    }
    if (elementToRemove->data != NULL)
    {
        free(elementToRemove->data);
        elementToRemove->data = NULL;
    }
    free(elementToRemove);
    elementToRemove = NULL;
}