
#include "arrayqueue.h"

static void	check()
{
	ArrayQueue		*pQueue;
	ArrayQueueNode	element;
	ArrayQueueNode	*get;

	pQueue = createArrayQueue(5);

	printf("is Empty?: %s\n", isArrayQueueEmpty(pQueue) ? "true" : "false");	// true
	displayArrayQueue(pQueue);	// empty queue

	element.data = '0';
	for (int i = 0; i < 5; i++)
	{
		enqueueAQ(pQueue, element);
		element.data++;
	}
	printf("is Full?: %s\n", isArrayQueueFull(pQueue) ? "true" : "false");	// true

	displayArrayQueue(pQueue);	// 0 1 2 3 4

	for (int i = 0; i < 2; i++)
	{
		get = dequeueAQ(pQueue);
		printf("deque: %c\n", get->data);	// 0 1
		free(get);
	}

	printf("is Empty?: %s\n", isArrayQueueEmpty(pQueue) ? "true" : "false");	// false

	for (int i = 0; i < 2; i++)
	{
		enqueueAQ(pQueue, element);
		element.data++;
	}

	displayArrayQueue(pQueue);	// 2 3 4 5 6

	for (int i = 0; i < 5; i++)
	{
		get = dequeueAQ(pQueue);
		printf("deque: %c\n", get->data);	// 2 3 4 5 6
		free(get);
	}

	for (int i = 0; i < 2; i++)
	{
		enqueueAQ(pQueue, element);	// 7 8
		element.data++;
	}

	displayArrayQueue(pQueue);

	deleteArrayQueue(&pQueue);
}

void	sim_test(void)
{
	ArrayQueue		*pWaitQueue;
	ArrayQueue		*pArrivalQueue;
	ArrayQueueNode	*customer;
	int				time;
	int				serviceUserCount;
	int				totalWaitTime;

	pWaitQueue = createArrayQueue(10);
	pArrivalQueue = createArrayQueue(10);
	customer = NULL;
	for (int i = 0; i < 10; i++)
		insertCustomer(i, i + 1, pArrivalQueue);
	time = 0;
	while (time <= 10)
	{
		processArrival(time, pArrivalQueue, pWaitQueue);
		customer = processServiceNodeEnd(time, customer, &serviceUserCount, &totalWaitTime);
		if (customer == NULL)	// 서비스 중인 고객이 없는 경우
			customer = processServiceNodeStart(time, pWaitQueue);
		printWaitQueueStatus(time, pWaitQueue);
		time++;
	}
	printReport(pWaitQueue, serviceUserCount, totalWaitTime);
	free(customer);
	deleteArrayQueue(&pArrivalQueue);
	deleteArrayQueue(&pWaitQueue);
}

int main(void)
{
	sim_test();
	// check();
	// system("leaks arrayqueue");

	return (0);
}
