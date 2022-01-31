#include "arraystack.h"

ArrayStack*	createArrayStack(int maxElementCount)				// 스택 생성
{
	ArrayStack *stack;

	if (maxElementCount < 0)
		return (NULL);
	stack = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (stack == NULL)
		return (NULL);
	stack->maxElementCount = maxElementCount;
	stack->currentElementCount = 0;
	stack->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode) * maxElementCount);
	if (stack->pElement == NULL)
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	return (stack);
}

int	pushAS(ArrayStack* pStack, ArrayStackNode element)	// 노드 추가
{
	if (pStack == NULL)
		return (FALSE);
	if (isArrayStackFull(pStack))
		return (FALSE);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

ArrayStackNode*	popAS(ArrayStack* pStack)							// 노드 제거
{
	ArrayStackNode	*element;

	element = peekAS(pStack);
	if (element == NULL)
		return (NULL);
	pStack->currentElementCount--;
	return (element);
}

ArrayStackNode*	peekAS(ArrayStack* pStack)							// 노드 반환
{
	if (pStack == NULL)
		return (NULL);
	if (isArrayStackEmpty(pStack))
		return (NULL);
	return (&pStack->pElement[pStack->currentElementCount - 1]);
}

void	deleteArrayStack(ArrayStack** pStack)				// 스택 제거
{
	if (pStack == NULL || *pStack == NULL)
		return ;
	free((*pStack)->pElement);
	free(*pStack);
	*pStack = NULL;
}

int	isArrayStackFull(ArrayStack* pStack)				// 스택이 찼는지 확인
{
	if (pStack == NULL)
		return (ERROR);
	if (pStack->maxElementCount == pStack->currentElementCount)
		return (TRUE);
	else
		return (FALSE);
}

int	isArrayStackEmpty(ArrayStack* pStack)				// 스택이 비었는지 확인
{
	if (pStack == NULL)
		return (ERROR);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	displayArrayStack(ArrayStack* pStack)
{
	int	i;

	if (pStack == NULL)
		return ;
	if (pStack->currentElementCount == 0)
		printf("empty stack");
	else
	{
		for (i = pStack->currentElementCount - 1; i >= 0 ; i--)
			printf("%c ", pStack->pElement[i].data);
	}
	printf("\n");
}
