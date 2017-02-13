#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define S_OK 0
#define S_FAIL 1

#define true 1
#define false 0

int CreateStack(int **pStack, int iMaxNumStack)
{
	if (*pStack != NULL)
	{
		printf("[Error] The stack is already existed.\n");
		return S_FAIL;
	}

	*pStack = calloc (iMaxNumStack, sizeof (int));
	if (!pStack)
	{
		printf ("[Error] The Stack create failed\n");
		return S_FAIL;
	}

	return S_OK;
}

int Push(int *pStack, int idata, int iMaxNumStack, int *pTop)
{
	if (isFull(iMaxNumStack, pTop))
	{
		printf ("[Info] The stack is full\n");
		return S_FAIL;
	}

	(*pTop)++;

	pStack[*pTop] = idata;
	return S_OK;
}

int Pop(int *pStack, int *pTop, int *pStatus)
{
	if (isEmpty(*pTop))
	{
		printf ("[Info] The stack is empty\n");
		*pStatus = S_FAIL;
		return S_FAIL;
	}

	int iTemp = pStack[*pTop];
	(*pTop)--;

	*pStatus = S_OK;
	return iTemp;
}

int Peek(int *pStack, int pTop, int *pStatus) // Get the value of stack top
{
	if (isEmpty(pTop))
	{
		printf ("[Info] The stack is empty\n");
		*pStatus = S_FAIL;
		return S_FAIL;
	}

	*pStatus = S_OK;
	return pStack[pTop];
}
int isFull(int iMaxNumStack, int *pTop)
{
	if (iMaxNumStack == *pTop)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int isEmpty(int pTop)
{
	if (pTop == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ReleaseStack(int **ppStack, int *Top)
{
	if (*ppStack == NULL || ppStack == NULL)
	{
		printf ("[Error] The stack is no address\n");
		return S_FAIL;
	}

	free(*ppStack);
	*ppStack = NULL;
	*Top = -1;
	return S_OK;
}

int main()
{
	int Top = -1;
	int *pStack = NULL;
	int iMaxNumStack = 0;
	int iRet = 0;
	int iTopValue = 0;
	int iPopValue = 0;
	printf ("The maximun stack depth\n?");
	scanf("%d", &iMaxNumStack);

	CreateStack(&pStack, iMaxNumStack);
	Push(pStack, 5, iMaxNumStack, &Top);
	Push(pStack, 4, iMaxNumStack, &Top);
	Push(pStack, 1, iMaxNumStack, &Top);
	Push(pStack, 2, iMaxNumStack, &Top);

	iTopValue = Peek(pStack, Top, &iRet);
	if (iRet != S_FAIL)
	{
		printf("Peek: %d\n", iTopValue);
	}

	iPopValue = Pop(pStack, &Top, &iRet);
	if (iRet != S_FAIL)
	{
		printf ("Pop value: %d\n", iPopValue);
	}

	ReleaseStack (&pStack, &Top);
	return S_OK;
}
