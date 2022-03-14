#include "sorting.h"

static void	resetArr(int *arr)
{
	int	nums[CNT] = {80, 50, 70, 10, 60, 20, 40, 30};
	int	i;

	for (i = 0; i < CNT; i++)
		arr[i] = nums[i];
}

static void	rResetArr(int *arr)
{
	int	nums[CNT] = {10, 40, 20, 60, 30, 70, 50, 80};
	int	i;

	for (i = 0; i < CNT; i++)
		arr[i] = nums[i];
}

void	test(void)
{
	int	*arr = malloc(sizeof(int) * CNT);
	if (arr == NULL)
		return ;
	resetArr(arr);
	print(arr, CNT, "init");
	// selectionSort(arr, CNT);
	// bubbleSort(arr, CNT);
	// quickSort(arr, 0, CNT - 1);
	// insertionSort(arr, CNT);
	// shellSort(arr, CNT);
	// mergeSort(arr, CNT);
	// radixSort(arr, CNT);
	heapSort(arr, CNT);
	print(arr, CNT, "result");
	free(arr);
}

void	ppt_test(void)
{
	int	*arr;
	int	input;
	int	i;

	arr = malloc(sizeof(int) * CNT);
	if (arr == NULL)
		return ;
	while (1)
	{
		printf("Select Menu : 1. Reset Array 2. Quick Sort 3. Insertion Sort 4. Display Array 5. Exit\n\n");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				resetArr(arr);
				break ;
			case 2:
				quickSort(arr, 0, CNT - 1);
				print(arr, CNT, "Quick Sort");
				break ;
			case 3:
				insertionSort(arr, CNT);
				print(arr, CNT, "Insertion Sort");
				break ;
			case 4:
				print(arr, CNT, "Display Array");
				break ;
			case 5:
				free(arr);
				exit(0);
			default:
				break ;
		}
	}
	free(arr);
}

int	main(void)
{

	// test();
	ppt_test();
	// system("leaks sorting");
	return (0);
}
