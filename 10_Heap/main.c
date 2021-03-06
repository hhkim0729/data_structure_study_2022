#include "heap.h"

void	test(void)
{
	Heap		*pHeap;
	HeapNode	element;

	pHeap = createHeap(7);
	element.key = 20;
	insertMaxHeap(pHeap, element);
	element.key = 6;
	insertMaxHeap(pHeap, element);
	element.key = 12;
	insertMaxHeap(pHeap, element);
	element.key = 2;
	insertMaxHeap(pHeap, element);
	element.key = 4;
	insertMaxHeap(pHeap, element);
	displayHeap(pHeap);

	element.key = 30;
	insertMaxHeap(pHeap, element);
	displayHeap(pHeap);

	deleteMaxHeapNode(pHeap);
	displayHeap(pHeap);

	deleteMaxHeapNode(pHeap);
	deleteMaxHeapNode(pHeap);
	deleteMaxHeapNode(pHeap);
	deleteMaxHeapNode(pHeap);
	if (deleteMaxHeapNode(pHeap))
		printf("yes\n");
	else
		printf("no\n");
	if (deleteMaxHeapNode(pHeap))
		printf("yes\n");
	else
		printf("no\n");

	displayHeap(pHeap);
	deleteHeap(&pHeap);
}

int main(void)
{
	test();
	// system("leaks heap");
	return (0);
}
