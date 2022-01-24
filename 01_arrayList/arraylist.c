#include "arraylist.h"

ArrayList*	createArrayList(int maxElementCount)	// arraylist 할당 및 생성
{
	ArrayList *arrayList;

	if (maxElementCount < 0)
		return (NULL);
	arrayList = (ArrayList*)malloc(sizeof(ArrayList));
	if (arrayList == NULL)
		return (NULL);
	arrayList->maxElementCount = maxElementCount;
	arrayList->currentElementCount = 0;
	arrayList->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (arrayList->pElement == NULL)
	{
		free(arrayList);
		arrayList = NULL;
		return (NULL);
	}
	return (arrayList);
}

void	deleteArrayList(ArrayList* pList)		// arraylist free
{
	free(pList->pElement);
	pList->pElement = NULL;
	free(pList);
	pList = NULL;
}
int	isArrayListFull(ArrayList* pList)		// arraylist가 가득 찼는지 확인
{
	if (pList->maxElementCount == pList->currentElementCount)
		return (TRUE);
	else
		return (FALSE);
}

int	addALElement(ArrayList* pList, int position, ArrayListNode element)	// arraylist node 추가
{
	int	i;

	if (isArrayListFull(pList) || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	i = pList->currentElementCount - 1;
	while (i >= position)
	{
		pList->pElement[i + 1] = pList->pElement[i];
		i--;
	}
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (TRUE);
}

int	removeALElement(ArrayList* pList, int position)	// arraylist node 제거
{
	int	i;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	i = position;
	while (i < pList->currentElementCount - 1)
	{
		pList->pElement[i] = pList->pElement[i + 1];
		i++;
	}
	pList->currentElementCount--;
	return (TRUE);
}

ArrayListNode*	getALElement(ArrayList* pList, int position)		// arraylist node 가져오기
{
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	return (&pList->pElement[position]);
}

void	displayArrayList(ArrayList* pList)		// arraylist 출력
{
	int	i;

	i = 0;
	while (i < pList->currentElementCount)
	{
		printf("%d ", pList->pElement[i].data);
		i++;
	}
	printf("\n");
}

void	clearArrayList(ArrayList* pList)		// arraylist 초기화
{
	pList->currentElementCount = 0;
}

int	getArrayListLength(ArrayList* pList)	// arraylist에 들어가있는 element의 길이 확인
{
	return (pList->currentElementCount);
}
