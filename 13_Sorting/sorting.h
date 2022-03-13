#ifndef _SORTING_H
# define _SORTING_H

#include <stdio.h>
#include <stdlib.h>

void	selectionSort(int arr[], int cnt);
void	bubbleSort(int arr[], int cnt);
void	quickSort(int arr[], int startIdx, int endIdx);
void	insertionSort(int arr[], int cnt);
void	shellSort(int arr[]);
void	mergeSort(int arr[]);
void	radixSort(int arr[]);
void	heapSort(int arr[]);

void	print(int arr[], int cnt, char *title);

# define CNT	8
# define TRUE	1
# define FALSE	0

#endif
