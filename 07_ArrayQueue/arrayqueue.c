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


// 시뮬레이션
// 새로운 고객을 도착 큐에 추가 -> 도착시간 설정 & 서비스 시간 설정 : 시뮬레이션 실행 전에 미리 셋팅을 위한 함수
void	insertCustomer(int arrivalTime, int serviceTime, ArrayQueue *pArrivalQueue)
{
	ArrayQueueNode	new;

	new.arrivalTime = arrivalTime;
	new.serviceTime = serviceTime;
	enqueueAQ(pArrivalQueue, new);
}

// 현재 시각 == 도착 시각이 같은 고객을 대기 큐로 이동 : 시스템 시각이 증가할 때마다 실행
void	processArrival(int currentTime, ArrayQueue *pArrivalQueue, ArrayQueue *pWaitQueue)
{
	ArrayQueueNode	*peek;

	peek = peekAQ(pArrivalQueue);
	if (peek != NULL && peek->arrivalTime == currentTime)
	{
		enqueueAQ(pWaitQueue, *peek);
		free(dequeueAQ(pArrivalQueue));
		free(peek);
	}
}

// 서비스 중인 고객이 없는 경우 대기 큐에서 고객 디큐
ArrayQueueNode*	processServiceNodeStart(int currentTime, ArrayQueue *pWaitQueue)
{
	ArrayQueueNode	*ret;

	ret = dequeueAQ(pWaitQueue);
	if (ret != NULL)
	{
		ret->startTime = currentTime;
		ret->endTime = ret->serviceTime + ret->startTime;
	}
	return (ret);
}

// 현재 서비스 중이던 고객의 서비스가 완료된 경우 메모리 해제, 서비스 고객 수와 대기 시간 증가
ArrayQueueNode*	processServiceNodeEnd(int currentTime, ArrayQueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	if (pServiceNode == NULL)
		return (NULL);
	if (pServiceNode->endTime == currentTime)
	{
		*pServiceUserCount += 1;
		*pTotalWaitTime += pServiceNode->startTime - pServiceNode->arrivalTime;
		free(pServiceNode);
		return (NULL);
	}
	else
		return (pServiceNode);
}

// 고객 정보 출력
void	printSimCustomer(ArrayQueueNode customer)
{
	printf("Arrival Time: %d\nService Time: %d\n\n", customer.arrivalTime, customer.serviceTime);
}

// 현재 시각 기준 대기 큐 고객 목록 상태 출력
void	printWaitQueueStatus(int currentTime, ArrayQueue *pWaitQueue)
{
	int	i;

	printf("----- Current time: %d -----\n", currentTime);
	if (isArrayQueueEmpty(pWaitQueue) == TRUE)
		return ;
	i = pWaitQueue->front;
	while (i != pWaitQueue->rear)
	{
		printSimCustomer(pWaitQueue->pElement[i]);
		i = (i + 1) % pWaitQueue->maxElementCount;
	}
	printSimCustomer(pWaitQueue->pElement[i]);
}

// 종료 시각 기준으로 남은 고객 목록이랑, 서비스 완료한 고객 + 총 대기 시간 출력
void	printReport(ArrayQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	int	i;

	printf("===== Bank Closed =====\n");
	printf("Service User Count: %d, Total Wait Time: %d\n", serviceUserCount, totalWaitTime);
	if (isArrayQueueEmpty(pWaitQueue) == TRUE)
		return ;
	printf("----- List of Clients Not Serviced -----\n");
	i = pWaitQueue->front;
	while (i != pWaitQueue->rear)
	{
		printSimCustomer(pWaitQueue->pElement[i]);
		i = (i + 1) % pWaitQueue->maxElementCount;
	}
	printSimCustomer(pWaitQueue->pElement[i]);
}

