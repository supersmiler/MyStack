#include "mystack.h"
#include "logging.h"

/* The stack is an abstract data type.
 * this means that the internal structures are
 * never exposed to the users of the library.
 */

/* Note: the stacks have no knowledge of what types
 * they are storing. This is not a concern of the stack
 */

//typedef struct stackMEta *pStackMeta_t;
typedef struct stackMEta
{
	ELEMENT *list;
	size_t objsize;
	int numelem;
	int handle;
	struct stackMEta *next;
} StackMeta_t;

static StackMeta_t *gStackList = NULL;

int mystack_create(size_t objsize)
{
	if (objsize == 0)
	{
		return -1;
	}

	int handle = 1;
	StackMeta_t *currentStackList = gStackList;
	StackMeta_t *newStackList = malloc(sizeof(StackMeta_t));

	newStackList->handle = handle;
	newStackList->objsize = objsize;
	newStackList->numelem = 0;
	newStackList->list = NULL;
	newStackList->next = NULL;

	if (currentStackList != NULL)
	{
		while (currentStackList->next != NULL)
		{
			currentStackList = currentStackList->next;
		}
		newStackList->handle = (currentStackList->handle + 1);
		currentStackList->next = newStackList;
	}
	else
	{
		gStackList = newStackList;
	}
	DBG_PRINTF("Created stack with handle: %d and objsize %zu bytes\n", newStackList->handle, objsize);
	return newStackList->handle;
}

int mystack_push(int handle, void *obj)
{
	if (gStackList == NULL || obj == NULL)
	{
		return -1;
	}

	StackMeta_t *currentStackList = gStackList;
	while (currentStackList != NULL && currentStackList->handle != handle)
	{
		currentStackList = currentStackList->next;
		if (currentStackList == NULL)
		{
			return -1;
		}
	}
	if(currentStackList->list == NULL)
	{
		currentStackList->list = (ELEMENT *)malloc(sizeof(ELEMENT));
		currentStackList->list = NULL;
	}
	PushElementBefore(&currentStackList->list, currentStackList->list, NULL, CreateNewElement(obj, currentStackList->objsize, NULL));
	currentStackList->numelem += 1;
	DBG_PRINTF("handle: %d\n, obj: %p\n", handle, obj);
	return 0;
}

int mystack_pop(int handle, void *obj)
{
	if (handle == 0 || gStackList == NULL || obj == NULL)
	{
		return -1;
	}
	StackMeta_t *currentStackList = gStackList;
	while (currentStackList != NULL && currentStackList->handle != handle)
	{
		currentStackList = currentStackList->next;
		if (currentStackList == NULL)
		{
			return -1;
		}
	}
	if(currentStackList->list == NULL)
	{
		return -1;
	}
	memcpy(obj, currentStackList->list->data, currentStackList->objsize);
	RemoveElement(&currentStackList->list, currentStackList->list, NULL);
	currentStackList->numelem -= 1;
	DBG_PRINTF("handle: %d\n, obj: %p\n", handle, obj);
	return 0;
}

int mystack_destroy(int handle)
{
	StackMeta_t *currentStackList = gStackList;
	StackMeta_t *prevStackList = NULL;
	if (currentStackList == NULL)
	{
		return -1;
	}
	while (currentStackList != NULL)
	{
		if (currentStackList->handle == handle)
		{
			CleanList(&currentStackList->list);
			StackMeta_t *stackToRemove = currentStackList;
			if (prevStackList != NULL)
			{
				StackMeta_t *nextStackList = stackToRemove->next;
				prevStackList->next = nextStackList;
			}
			else
			{
				gStackList = stackToRemove->next;
			}
			free(stackToRemove);
			stackToRemove = NULL;
			DBG_PRINTF("handle: %d\n", handle);
			return 0;
		}
		prevStackList = currentStackList;
		currentStackList = currentStackList->next;
		if (currentStackList == NULL)
		{
			return -1;
		}
	}
	return 0;
}

int mystack_nofelem(int handle)
{
	StackMeta_t *currentStackList = gStackList;
	while (currentStackList != NULL && currentStackList->handle != handle)
	{
		currentStackList = currentStackList->next;
		if (currentStackList == NULL)
		{
			return -1;
		}
	}
	DBG_PRINTF("handle: %d\n", handle);
	return currentStackList->numelem;
}

void destroy_stack()
{
	free(gStackList);
	gStackList = NULL;
}