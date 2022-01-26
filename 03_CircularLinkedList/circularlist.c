#include "circularlist.h"

CircularList*	createCircularList()		// list 생성
{
	CircularList* list;

	list = (CircularList*)malloc(sizeof(CircularList));
	if (list == NULL)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.pLink = NULL;
	return (list);
}

int	addCLElement(CircularList* pList, int position, CircularListNode element)		// 노드 추가
{
	CircularListNode	*curr;
	CircularListNode	*new;
	CircularListNode	*last;
	int	i;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	new = (CircularListNode *)malloc(sizeof(CircularListNode));
	if (new == NULL)
		return (FALSE);
	*new = element;
	if (position == 0)
	{
		new->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = new;
		pList->currentElementCount++;
		last = getLastCLElement(pList);
		last->pLink = new;
	}
	else
	{
		curr = pList->headerNode.pLink;
		for (i = 0; i < position - 1; i++)
			curr = curr->pLink;
		new->pLink = curr->pLink;
		curr->pLink = new;
		pList->currentElementCount++;
	}
	return (TRUE);
}

int	removeCLElement(CircularList* pList, int position)		// 노드 제거
{
	CircularListNode	*curr;
	CircularListNode	*temp;
	CircularListNode	*last;
	int	i;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	curr = pList->headerNode.pLink;
	if (position == 0)
	{
		temp = curr;
		if (pList->currentElementCount == 1)
			pList->headerNode.pLink = NULL;
		else
		{
			last = getLastCLElement(pList);
			last->pLink = curr->pLink;
			pList->headerNode.pLink = curr->pLink;
		}
	}
	else
	{
		for (i = 0; i < position - 1; i++)
			curr = curr->pLink;
		temp = curr->pLink;
		curr->pLink = curr->pLink->pLink;
	}
	free(temp);
	temp = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

CircularListNode*	getCLElement(CircularList* pList, int position) 		// 노드 가져오기
{
	int	i;
	CircularListNode	*curr;

	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	curr = pList->headerNode.pLink;
	for (i = 0; i < position; i++)
		curr = curr->pLink;
	return (curr);
}

CircularListNode*	getLastCLElement(CircularList* pList)
{
	return (getCLElement(pList, pList->currentElementCount - 1));
}

void	displayCircularList(CircularList *pList)
{
	CircularListNode	*curr;
	int	i;

	curr = pList->headerNode.pLink;
	if (!curr)
		printf("empty list");
	else{
		for (i = 0; i <= pList->currentElementCount; i++)
		{
			printf("(%d) %d\t", i % pList->currentElementCount, curr->data);
			curr = curr->pLink;
		}
	}
	printf("\n");
}

void	clearCircularList(CircularList* pList) 		// list 초기화
{
	CircularListNode	*curr;
	CircularListNode	*next;

	curr = pList->headerNode.pLink;
	while (pList->currentElementCount)
	{
		next = curr->pLink;
		free(curr);
		curr = next;
		pList->currentElementCount--;
	}
	pList->headerNode.pLink = NULL;
}

int	getCircularListLength(CircularList* pList) 		// list 노드의 개수 확인
{
	return (pList->currentElementCount);
}

void	deleteCircularList(CircularList* pList) 	// list free
{
	clearCircularList(pList);
	free(pList);
	pList = NULL;
}
