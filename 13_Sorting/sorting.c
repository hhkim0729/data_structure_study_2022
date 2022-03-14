#include "sorting.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	print(int *arr, int cnt, char *title)
{
	printf("===== %s =====\n", title);
	for (int i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}

void	selectionSort(int *arr, int cnt)
{
	int	i;
	int	j;
	int	min_idx;

	for (i = 0; i < cnt; i++)
	{
		min_idx = i;
		for (j = i; j < cnt; j++)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(&arr[min_idx], &arr[i]);
	}
}

void	bubbleSort(int *arr, int cnt)
{
	int	i;
	int	j;

	for (i = 0; i < cnt; i++)
		for (j = 0; j < cnt- i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

static int	getMedianIdx(int *arr, int startIdx, int endIdx)
{
	int	middle;

	middle = (startIdx + endIdx) / 2;
	if (arr[startIdx] > arr[endIdx])
	{
		if (arr[endIdx] > arr[middle])
			return (endIdx);
		else
		{
			if (arr[startIdx] > arr[middle])
				return (middle);
			else
				return (startIdx);
		}
	}
	else
	{
		if (arr[middle] > arr[endIdx])
			return (endIdx);
		else
		{
			if (arr[startIdx] > arr[middle])
				return (startIdx);
			else
				return (middle);
		}
	}
}

void	quickSort(int *arr, int startIdx, int endIdx)
{
	int	mIdx;
	int	left;
	int	right;
	int	direction;

	if (startIdx >= endIdx)
		return ;
	mIdx = getMedianIdx(arr, startIdx, endIdx);
	left = startIdx;
	right = endIdx;
	while (left < right)
	{
		while (left < endIdx && arr[left] <= arr[mIdx])
			left++;
		while (right > startIdx && arr[right] >= arr[mIdx])
			right--;
		if (left < right)
			swap(&arr[left], &arr[right]);
	}
	direction = right < mIdx ? left : right;
	if (mIdx <= right || mIdx >= left)
		swap(&arr[direction], &arr[mIdx]);
	quickSort(arr, startIdx, direction - 1);
	quickSort(arr, direction + 1, endIdx);
}

void	insertionSort(int *arr, int cnt)
{
	int	tmp;
	int	i;
	int	j;

	for (i = 1; i < cnt; i++)
	{
		tmp = arr[i];
		j = i;
		while (--j >= 0 && arr[j] > tmp)
			arr[j + 1] = arr[j];
		arr[j + 1] = tmp;
	}
}

void	shellSort(int *arr, int cnt)
{
	int	gap;
	int	tmp;
	int	i;
	int	j;
	int	k;

	for (gap = cnt / 2; gap >= 1; gap /= 2)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i + gap; j < cnt; j += gap)
			{
				tmp = arr[j];
				k = j - gap;
				for (k = j - gap; k >= i && arr[k] > tmp; k -= gap)
					arr[k + gap] = arr[k];
				arr[k + gap] = tmp;
			}
		}
	}
}

static void	mergeArray(int *arr, int *tmpArr, int startIdx, int endIdx)
{
	int	middle;
	int	i;
	int	j;
	int	k;

	middle = (startIdx + endIdx) / 2;
	i = startIdx;
	j = middle + 1;
	k = startIdx;
	while (i <= middle && j <= endIdx)
	{
		if (arr[i] < arr[j])
			tmpArr[k++] = arr[i++];
		else
			tmpArr[k++] = arr[j++];
	}
	while (i <= middle)
		tmpArr[k++] = arr[i++];
	while (j <= endIdx)
		tmpArr[k++] = arr[j++];
	for (i = startIdx; i <= endIdx; i++)
		arr[i] = tmpArr[i];
}

static void	splitArray(int *arr, int *tmpArr, int startIdx, int endIdx)
{
	int	middle;

	middle = (startIdx + endIdx) / 2;
	if (endIdx - startIdx > 0)
	{
		splitArray(arr, tmpArr, startIdx, middle);
		splitArray(arr, tmpArr, middle + 1, endIdx);
		mergeArray(arr, tmpArr, startIdx, endIdx);
	}
}

void	mergeSort(int *arr, int cnt)
{
	int	*tmpArr;

	tmpArr = malloc(sizeof(int) * cnt);
	if (tmpArr == NULL)
		return ;
	splitArray(arr, tmpArr, 0, cnt - 1);
	free(tmpArr);
}

static int	getMaxLength(int *arr, int cnt)
{
	int	max;
	int	i;

	max = arr[0];
	for (i = 0; i < cnt; i++)
		if (arr[i] > max)
			max = arr[i];
	for (i = 0; max > 0; i++)
		max /= 10;
	return (i);
}

void	radixSort(int *arr, int cnt)
{
	int			maxLength;
	int			mod;
	int			i;
	int			j;
	int			k;
	int			tenPow;
	LinkedDeque *pDequeArr[10];
	DequeNode	*pNode;
	DequeNode	node;

	for (i = 0; i < 10; i++)
	{
		pDequeArr[i] = createLinkedDeque();
		if (pDequeArr[i] == NULL)
		{
			while (--i >= 0)
				deleteLinkedDeque(pDequeArr[i]);
			return ;
		}
	}
	maxLength = getMaxLength(arr, cnt);
	tenPow = 1;
	for (i = 0; i < maxLength; i++)
	{
		for (j = 0; j < cnt; j++)
		{
			node.data = arr[j];
			mod = (arr[j] % (tenPow * 10)) / tenPow;
			insertRearLD(pDequeArr[mod], node);
		}
		k = 0;
		for (j = 0; j < 10; j++)
		{
			while (isLinkedDequeEmpty(pDequeArr[j]) == FALSE)
			{
				pNode = deleteFrontLD(pDequeArr[j]);
				arr[k++] = pNode->data;
				free(pNode);
			}
		}
		tenPow *= 10;
	}
	for (i = 0; i < 10; i++)
		deleteLinkedDeque(pDequeArr[i]);
}

void heapSort(int *arr, int cnt)
{
	Heap		*pHeap;
	int			i;
	HeapNode	node;
	HeapNode	*pNode;

	pHeap = createHeap(cnt);
	if (pHeap == NULL)
		return ;
	for (i = 0; i < cnt; i++)
	{
		node.key = arr[i];
		insertMinHeap(pHeap, node);
	}
	for (i = 0; i < cnt; i++)
	{
		pNode = getMinHeapNode(pHeap);
		arr[i] = pNode->key;
		free(pNode);
	}
	deleteHeap(&pHeap);
}
