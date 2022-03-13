#include "sorting.h"

void	print(int arr[], int cnt, char *title)
{
	printf("===== %s =====\n", title);
	for (int i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}

void	selectionSort(int arr[], int cnt)
{
	int	min_idx;
	int	temp;

	for (int i = 0; i < cnt; i++)
	{
		min_idx = i;
		for (int j = i; j < cnt; j++)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
	print(arr, cnt, "Selection Sort");
}

void	bubbleSort(int arr[], int cnt)
{
	int	i;
	int	j;
	int	tmp;

	for (i = 0; i < cnt; i++)
	{
		for (j = 0; j < cnt- i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	print(arr, cnt, "Bubble Sort");
}

static int	getMedianIdx(int arr[], int startIdx, int endIdx)
{
	int middle;

	// printf("startIdx: %d | endIdx: %d\n", startIdx, endIdx);
	middle = startIdx + ((endIdx - startIdx) / 2);
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

void	quickSort(int arr[], int startIdx, int endIdx)
{
	int	mIdx;
	int	left;
	int	right;
	int	direction;
	int	temp;

	if (startIdx >= endIdx)
		return ;
	// 1. 피봇 선택
	mIdx = getMedianIdx(arr, startIdx, endIdx);
	printf("pivot: %d\n", arr[mIdx]);
	// 5. `i`가 `j`보다 작거나 같은 동안(인덱스 탐색이 엇갈릴 때까지) 2~4 반복
	left = startIdx;
	right = endIdx;
	while (left < right)
	{
		// 2. 왼쪽에서 시작해서 피봇보다 큰 값을 찾을 때까지 인덱스 `i` 증가
		while (left < endIdx && arr[left] <= arr[mIdx])
			left++;
		// 3. 오른쪽에서 시작해서 피봇보다 작은 값을 찾을 때까지 인덱스 `j` 감소
		while (right > startIdx && arr[right] >= arr[mIdx])
			right--;
		// printf("left: %d, right: %d\n", arr[left], arr[right]);
		// printf("leftIdx: %d, rightIdx: %d\n", left, right);
		// 4. `i`와 `j`의 값 교환
		if (left < right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			print(arr, CNT, "while trial");
		}
	}
	// 6. `i`의 값과 피봇 인덱스의 값 교환 (첫 번째 피봇 정렬 완료)
	direction = right < mIdx ? left : right;
	if (mIdx > right && mIdx < left)
		direction = mIdx;
	temp = arr[direction];
	arr[direction] = arr[mIdx];
	arr[mIdx] = temp;
	print(arr, CNT, "pivot change trial");
	// 7. 피봇의 좌우 리스트에 대해 리스트의 길이가 1 이하가 될 때까지 1~6을 재귀적으로 반복
	quickSort(arr, startIdx, direction - 1);
	quickSort(arr, direction + 1, endIdx);
}

void	insertionSort(int arr[], int cnt)
{
	int	tmp;
	int	i;
	int	j;

	// 1. 두 번째 자료인 인덱스 `1`부터 시작해서 마지막 자료까지 반복 (`i`)
	for (i = 1; i < cnt; i++)
	{
		// 2. `i` 위치의 비교 중인 자료를 `tmp`에 임시로 저장
		tmp = arr[i];
		// 3. `j`는 비교 중인 자료의 인덱스 왼쪽부터 시작해서 `j` 위치의 값이 `tmp`보다 큰 동안 자료의 위치를 하나 뒤로 이동시키고 `j` 감소
		j = i;
		while (--j >= 0 && arr[j] > tmp)
			arr[j + 1] = arr[j];
		// 4. 3의 반복이 끝나면 `j` 위치에 `tmp` 저장
		arr[j + 1] = tmp;
	}
	print(arr, cnt, "Insertion Sort");
}
