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

void	deleteArrayList(ArrayList** pList)		// arraylist free
{
	if (pList == NULL || *pList == NULL)
		return ;
	free((*pList)->pElement);
	free(*pList);
	*pList = NULL;
}
int	isArrayListFull(ArrayList* pList)		// arraylist가 가득 찼는지 확인
{
	if (pList == NULL)
		return (ERROR);
	if (pList->maxElementCount == pList->currentElementCount)
		return (TRUE);
	else
		return (FALSE);
}

int	addALElement(ArrayList* pList, int position, ArrayListNode element)	// arraylist node 추가
{
	int	i;

	if (pList == NULL || isArrayListFull(pList) || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	for (i = pList->currentElementCount - 1; i >= position; i--)
		pList->pElement[i + 1] = pList->pElement[i];
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (TRUE);
}

int	removeALElement(ArrayList* pList, int position)	// arraylist node 제거
{
	int	i;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	for (i = position; i < pList->currentElementCount - 1; i++)
		pList->pElement[i] = pList->pElement[i + 1];
	pList->currentElementCount--;
	return (TRUE);
}

ArrayListNode*	getALElement(ArrayList* pList, int position)		// arraylist node 가져오기
{
	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
		return (NULL);
	return (&pList->pElement[position]);
}

void	displayArrayList(ArrayList* pList)		// arraylist 출력
{
	int	i;

	if (pList == NULL)
		return ;
	if (pList->currentElementCount == 0)
		printf("empty list");
	for (i = 0; i < pList->currentElementCount; i++)
		printf("%d ", pList->pElement[i].data);
	printf("\n");
}

void	clearArrayList(ArrayList* pList)		// arraylist 초기화
{
	if (pList == NULL)
		return ;
	pList->currentElementCount = 0;
}

int	getArrayListLength(ArrayList* pList)	// arraylist에 들어가있는 element의 길이 확인
{
	if (pList == NULL)
		return (ERROR);
	return (pList->currentElementCount);
}
