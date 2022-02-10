#include "linkeddeque.h"

static void check(void)
{
	LinkedDeque	*pDeque;
	DequeNode	element;
	DequeNode	*get;

	pDeque = createLinkedDeque();

	printf("is Empty?: %s\n", isLinkedDequeEmpty(pDeque) ? "true" : "false");	// true
	displayLinkedDeque(pDeque);	// empty deque

	element.data = '0';
	for (int i = 0; i < 3; i++)
	{
		insertFrontLD(pDeque, element);
		(element.data)++;
	}

	displayLinkedDeque(pDeque);	// 2 1 0

	for (int i = 0; i < 3; i++)
	{
		insertRearLD(pDeque, element);
		(element.data)++;
	}

	displayLinkedDeque(pDeque);	// 2 1 0 3 4 5

	for (int i = 0; i < 2; i++)
	{
		get = deleteFrontLD(pDeque);
		printf("deque: %c\n", get->data);	// 2 1
		free(get);
	}

	for (int i = 0; i < 2; i++)
	{
		get = deleteRearLD(pDeque);
		printf("deque: %c\n", get->data);	// 5 4
		free(get);
	}

	displayLinkedDeque(pDeque);	// 0 3

	deleteLinkedDeque(pDeque);
}

int main(void)
{
	check();
	// system("leaks linkeddeque");
	
	return (0);
}
