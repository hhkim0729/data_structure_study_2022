#include "heap.h"

// 힙 생성
Heap	*createHeap(int maxcount)
{
	Heap	*pHeap;

	pHeap = (Heap *)malloc(sizeof(Heap));
	if (pHeap == NULL)
		return (NULL);
	pHeap->maxCount = maxcount;
	pHeap->currentCount = 0;
	pHeap->pElement = (HeapNode *)malloc(sizeof(HeapNode) * (maxcount + 1));
	if (pHeap->pElement == NULL)
	{
		free(pHeap);
		return (NULL);
	}
	return (pHeap);
}

// 힙 삭제(=메모리 해제)
void	deleteHeap(Heap **pHeap)
{
	if (pHeap == NULL || *pHeap == NULL)
	{
		fprintf(stderr, "Error: Heap is NULL\n");
		return ;
	}
	free((*pHeap)->pElement);
	free(*pHeap);
	*pHeap = NULL;
}

// 자료 추가
int	insertMaxHeap(Heap *pHeap, HeapNode element)
{
	int	i;
	int	parent_i;

	if (pHeap == NULL || isHeapFull(pHeap))
		return (FALSE);
	pHeap->currentCount++;
	i = pHeap->currentCount;
	parent_i = i / 2;
	while (i > 1 && element.key >= pHeap->pElement[parent_i].key)
	{
		pHeap->pElement[i].key = pHeap->pElement[parent_i].key;
		i /= 2;
		parent_i = i / 2;
	}
	pHeap->pElement[i] = element;
	return (TRUE);
}

int	insertMinHeap(Heap *pHeap, HeapNode element)
{
	int	i;
	int	parent_i;

	if (pHeap == NULL || isHeapFull(pHeap))
		return (FALSE);
	pHeap->currentCount++;
	i = pHeap->currentCount;
	parent_i = i / 2;
	while (i > 1 && element.key <= pHeap->pElement[parent_i].key)
	{
		pHeap->pElement[i].key = pHeap->pElement[parent_i].key;
		i /= 2;
		parent_i = i / 2;
	}
	pHeap->pElement[i] = element;
	return (TRUE);
}

// 자료 제거: 루트 노드의 삭제, 트리의 구조는 유지
int	deleteMaxHeapNode(Heap *pHeap)
{
	int	index;
	int	left;
	int	right;
	int	big;
	int	tmp;

	if (pHeap == NULL || isHeapEmpty(pHeap))
		return (FALSE);
	index = 1;
	pHeap->pElement[index].key = pHeap->pElement[pHeap->currentCount].key;
	pHeap->currentCount--;
	while (index < pHeap->currentCount)
	{
		left = index * 2;
		right = index * 2 + 1;
		big = left;
		if (pHeap->pElement[left].key < pHeap->pElement[right].key)
			big = right;
		if (pHeap->pElement[index].key < pHeap->pElement[big].key)
		{
			tmp = pHeap->pElement[index].key;
			pHeap->pElement[index].key = pHeap->pElement[big].key;
			pHeap->pElement[big].key = tmp;
		}
		index = big;
	}
	return (TRUE);
}

int	deleteMinHeapNode(Heap *pHeap)
{
	int	index;
	int	left;
	int	right;
	int	small;
	int	tmp;

	if (pHeap == NULL || isHeapEmpty(pHeap))
		return (FALSE);
	index = 1;
	pHeap->pElement[index].key = pHeap->pElement[pHeap->currentCount].key;
	pHeap->currentCount--;
	while (index < pHeap->currentCount)
	{
		left = index * 2;
		right = index * 2 + 1;
		small = left;
		if (pHeap->pElement[left].key > pHeap->pElement[right].key)
			small = right;
		if (pHeap->pElement[index].key > pHeap->pElement[small].key)
		{
			tmp = pHeap->pElement[index].key;
			pHeap->pElement[index].key = pHeap->pElement[small].key;
			pHeap->pElement[small].key = tmp;
		}
		index = small;
	}
	return (TRUE);
}

HeapNode	*getMaxHeapNode(Heap *pHeap)
{
	int			index;
	int			left;
	int			right;
	int			big;
	int			tmp;
	HeapNode	*rootNode;

	if (pHeap == NULL || isHeapEmpty(pHeap))
		return (NULL);
	index = 1;
	rootNode = (HeapNode *)malloc(sizeof(HeapNode));
	*rootNode = pHeap->pElement[index];
	pHeap->pElement[index] = pHeap->pElement[pHeap->currentCount];
	pHeap->currentCount--;
	while (index < pHeap->currentCount)
	{
		left = index * 2;
		right = index * 2 + 1;
		big = left;
		if (pHeap->pElement[left].key < pHeap->pElement[right].key)
			big = right;
		if (pHeap->pElement[index].key < pHeap->pElement[big].key)
		{
			tmp = pHeap->pElement[index].key;
			pHeap->pElement[index].key = pHeap->pElement[big].key;
			pHeap->pElement[big].key = tmp;
		}
		index = big;
	}
	return (rootNode);
}

HeapNode	*getMinHeapNode(Heap *pHeap)
{
	int			index;
	int			left;
	int			right;
	int			small;
	int			tmp;
	HeapNode	*rootNode;

	if (pHeap == NULL || isHeapEmpty(pHeap))
		return (NULL);
	index = 1;
	rootNode = (HeapNode *)malloc(sizeof(HeapNode));
	*rootNode = pHeap->pElement[index];
	pHeap->pElement[index] = pHeap->pElement[pHeap->currentCount];
	pHeap->currentCount--;
	while (index < pHeap->currentCount)
	{
		left = index * 2;
		right = index * 2 + 1;
		small = left;
		if (pHeap->pElement[left].key > pHeap->pElement[right].key)
			small = right;
		if (pHeap->pElement[index].key > pHeap->pElement[small].key)
		{
			tmp = pHeap->pElement[index].key;
			pHeap->pElement[index].key = pHeap->pElement[small].key;
			pHeap->pElement[small].key = tmp;
		}
		index = small;
	}
	return (rootNode);
}


int	isHeapFull(Heap *pHeap)
{
	return (pHeap->currentCount == pHeap->maxCount);
}

int	isHeapEmpty(Heap *pHeap)
{
	return (pHeap->currentCount == 0);
}

void	displayHeap(Heap *pHeap)
{
	int	i;
	int	j;
	int	two;
	int	height;
	int	cnt;

	if (pHeap == NULL)
	{
		fprintf(stderr, "Error: Heap is NULL\n");
		return;
	}
	if (isHeapEmpty(pHeap))
	{
		printf("empty heap\n");
		return;
	}
	height = 0;
	cnt = pHeap->currentCount;
	while (cnt != 0)
	{
		cnt /= 2;
		height++;
	}
	two = 1;
	for (i = 0; i < height; i++)
	{
		for (j = two; j < two * 2 ; j++)
		{
			if (j > pHeap->currentCount)
				break ;
			printf("%d %d\t", pHeap->pElement[j].vertexId, pHeap->pElement[j].key);
		}
		printf("\n");
		two *= 2;
	}
	printf("\n");
}
