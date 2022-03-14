#ifndef _SORTING_H
# define _SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include "../08_LinkedDeque/linkeddeque.h"
#include "../10_Heap/heap.h"

void	selectionSort(int *arr, int cnt);
void	bubbleSort(int *arr, int cnt);
void	quickSort(int *arr, int startIdx, int endIdx);
void	insertionSort(int *arr, int cnt);
void	insertionSort(int *arr, int cnt);
void	shellSort(int *arr, int cnt);
void	mergeSort(int *arr, int cnt);
void	radixSort(int *arr, int cnt);
void	heapSort(int *arr, int cnt);

void	print(int *arr, int cnt, char *title);

# define CNT	8
# define TRUE	1
# define FALSE	0

#endif
