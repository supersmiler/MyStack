#include "ReverseList.h"

int printArray()
{
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d", array[i]);
    }

    return 0;
}

int reverseArray()
{
    int stackHandle = mystack_create(sizeof(int));
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        mystack_push(stackHandle, &array[i]);
    }
    int data;
    int j = 0;
    while (mystack_pop(stackHandle, &data) == 0)
    {
        array[j] = data;
        j++;
    }
    mystack_destroy(stackHandle);
}

void reverseList()
{
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        array[i] = i;
    }


    printf("Normal list:\n");
    printArray();
    reverseArray();
    printf("Reverse list:\n");
    printArray();
    destroy_stack();
    return;
}