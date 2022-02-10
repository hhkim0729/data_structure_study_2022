#include "arrayqueue.h"

ArrayQueue*	createArrayQueue(int maxElementCount)
{
	ArrayQueue	*queue;

	queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
	if (queue == NULL)
		return (NULL);
	queue->maxElementCount = maxElementCount;
	queue->currentElementCount = 0;
	queue->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (queue->pElement == NULL)
	{
		free(queue);
		queue = NULL;
		return (NULL);
	}
	return (queue);
}

int	enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	int	index;

	if (isArrayQueueFull(pQueue) == TRUE)
		return (FALSE);
	if (isArrayQueueEmpty(pQueue) == TRUE)
	{
		pQueue->front = 0;
		pQueue->rear = 0;
		(pQueue->pElement)[0] = element;
	}
	else
	{
		index = (pQueue->rear + 1) % pQueue->maxElementCount;
		(pQueue->pElement)[index] = element;
		pQueue->rear = index;
	}
	pQueue->currentElementCount++;
	return (TRUE);
}

ArrayQueueNode	*dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode	*new;

	if (isArrayQueueEmpty(pQueue) == TRUE)
		return (NULL);
	new = peekAQ(pQueue);
	if (new == NULL)
		return (NULL);
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (new);
}

ArrayQueueNode	*peekAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode	*new;

	if (isArrayQueueEmpty(pQueue) == TRUE)
		return (NULL);
	new = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
	if (new == NULL)
		return (NULL);
	*new = (pQueue->pElement)[pQueue->front];
	return (new);
}

void	deleteArrayQueue(ArrayQueue** pQueue)
{
	free((*pQueue)->pElement);
	free(*pQueue);
	*pQueue = NULL;
}

int	isArrayQueueFull(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == pQueue->maxElementCount);
}

int	isArrayQueueEmpty(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == 0);
}

void	displayArrayQueue(ArrayQueue *pQueue)
{
	int	index;

	if (pQueue->currentElementCount == 0)
	{
		printf("empty queue\n");
		return ;
	}
	index = pQueue->front;
	while (index != pQueue->rear)
	{
		printf("[%d]: %c, ", index, (pQueue->pElement)[index].data);
		index = (index + 1) % pQueue->maxElementCount;
	}
	printf("[%d]: %c\n", index, (pQueue->pElement)[index].data);
}
