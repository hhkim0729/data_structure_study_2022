#include "linkedstack.h"

LinkedStack*	createLinkedStack()							// 스택 생성
{
	LinkedStack	*stack;

	stack = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (stack == NULL)
		return (NULL);
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

int	pushLS(LinkedStack* pStack, StackNode element)	// 노드 추가
{
	StackNode	*new;
	StackNode	*prev;

	if (pStack == NULL)
		return (FALSE);
	new = (StackNode *)malloc(sizeof(StackNode));
	if (new == NULL)
		return (FALSE);
	*new = element;
	prev = peekLS(pStack);
	new->pLink = prev;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode*	popLS(LinkedStack* pStack)						// 노드 제거
{
	StackNode	*element;

	element = peekLS(pStack);
	if (element == NULL)
		return (NULL);
	if (pStack->currentElementCount == 1)
		pStack->pTopElement = NULL;
	else
		pStack->pTopElement = element->pLink;
	pStack->currentElementCount--;
	return (element);
}

StackNode*	peekLS(LinkedStack* pStack)					// 노드 반환
{
	if (pStack == NULL)
		return (NULL);
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	return (pStack->pTopElement);
}

void	deleteLinkedStack(LinkedStack** pStack)			// 스택 제거
{
	StackNode	*curr;
	StackNode	*next;

	if (pStack == NULL || *pStack == NULL)
		return ;
	curr = (*pStack)->pTopElement;
	while ((*pStack)->currentElementCount)
	{
		next = curr->pLink;
		free(curr);
		curr = next;
		(*pStack)->currentElementCount--;
	}
	free(*pStack);
	*pStack = NULL;
}

// int	isLinkedStackFull(LinkedStack* pStack)			// 스택이 찼는지 확인
// {}

int	isLinkedStackEmpty(LinkedStack* pStack)		// 스택이 비었는지 확인
{
	if (pStack == NULL)
		return (ERROR);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	displayLinkedStack(LinkedStack* pStack)
{
	StackNode	*curr;

	if (pStack == NULL)
		return ;
	curr = pStack->pTopElement;
	if (curr == NULL)
		printf("empty stack");
	else
	{
		while (curr)
		{
			printf("%c ", curr->data);
			curr = curr->pLink;
		}
	}
	printf("\n");
}
