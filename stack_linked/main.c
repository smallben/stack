#include <stdio.h>
#include <stdlib.h>

#define S_OK 0
#define S_FAIL 1

typedef struct linkedstack {
	int data;
	struct linkedstack *pNext;
} TLinkedStack;

int Create (TLinkedStack **pTop)
{
	if (*pTop != NULL)
	{
		printf ("[Error] The Address is already existed\n");
		return S_FAIL;
	}
	*pTop = malloc(sizeof (TLinkedStack));
	if (*pTop == NULL)
	{
		printf ("[Error] cannot allocate the memory space\n");
		return S_FAIL;
	}

	(*pTop)->pNext = NULL;
	(*pTop)->data = -1;

	return S_OK;
}

int Peek(TLinkedStack *pTop, int *Value)
{
	*Value = pTop->data;
	return S_OK;
}

int Stack_count(TLinkedStack *pTop)
{
	return S_OK;
}

int push(TLinkedStack **pTop, int iData)
{
	if ((*pTop) == NULL || pTop == NULL)
	{
		printf ("[Error] Address empty\n");
		return S_FAIL;
	}
	TLinkedStack *pTemp = malloc (sizeof(TLinkedStack));
	if (pTemp == NULL)
	{
		printf ("[Error] Address is malloc failed\n");
		return S_FAIL;
	}

	pTemp->data = iData;
	pTemp->pNext = (*pTop);

	*pTop = pTemp;
	return S_OK;
}

int pop(TLinkedStack **pTop)
{
	return S_OK;
}

int main()
{
	TLinkedStack *pTop = NULL;
	int iShow;
	Create (&pTop);
	push(&pTop, 5);
	Peek(pTop, &iShow);
	printf ("%d\n", iShow);
	return S_OK;
}
