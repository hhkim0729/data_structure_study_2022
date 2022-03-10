#ifndef HEAP_H
# define HEAP_H

#include <stdio.h>
#include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct HeapNodeType
{
	int	key;
	int	vertexId;
}	HeapNode;

typedef struct HeapType
{
	int			maxCount;
	int			currentCount;
	HeapNode	*pElement;
}	Heap;

Heap*		createHeap(int maxCount);
void		deleteHeap(Heap **pHeap);
int			insertMaxHeap(Heap *pHeap, HeapNode element);
int			insertMinHeap(Heap *pHeap, HeapNode element);
int			deleteMaxHeapNode(Heap *pHeap);
int			deleteMinHeapNode(Heap *pHeap);
HeapNode	*getMaxHeapNode(Heap *pHeap);
HeapNode	*getMinHeapNode(Heap *pHeap);

int		isHeapFull(Heap *pHeap);
int		isHeapEmpty(Heap *pHeap);
void	displayHeap(Heap *pHeap);

#endif
