#include "sorting.h"

static void	resetArr(int  *arr)
{
	int	nums[] = {80, 50, 70, 10, 60, 20, 40, 30};
	int	i;

	for (i = 0; i < CNT; i++)
		arr[i] = nums[i];
}

static void	rResetArr(int  *arr)
{
	int	nums[] = {10, 40, 20, 60, 30, 70, 50, 80};
	int	i;

	for (i = 0; i < CNT; i++)
		arr[i] = nums[i];
}

void	test(void)
{
	// int	input[CNT] = {80, 50, 70, 10, 60, 20, 40, 30};
	int	*arr = malloc(sizeof(int) * CNT);
	if (!arr)
		return ;
	resetArr(arr);
	print(arr, CNT, "init");
	// selectionSort(arr, CNT);
	// bubbleSort(arr, CNT);
	quickSort(arr, 0, CNT - 1);
	// insertionSort(arr, CNT);
	free(arr);
}

int	main(void)
{
	test();
	// system("leaks sorting");
	return (0);
}
