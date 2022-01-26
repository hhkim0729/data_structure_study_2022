#include "doublylist.h"

DoublyList*	createDoublyList()		// list 생성
{
	DoublyList* list;

	list = (DoublyList *)malloc(sizeof(DoublyList));
	if (list == NULL)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.pLLink = &list->headerNode;
	list->headerNode.pRLink = &list->headerNode;
	return (list);
}

int	addDLElement(DoublyList* pList, int position, DoublyListNode element)		// 노드 추가
{
	DoublyListNode	*new;
	DoublyListNode	*prev;
	int	i;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	new = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (new == NULL)
		return (FALSE);
	*new = element;
	prev = &pList->headerNode;
	for (i = 0; i < position; i++)
		prev = prev->pRLink;
	new->pLLink = prev;
	new->pRLink = prev->pRLink;
	prev->pRLink = new;
	new->pRLink->pLLink = new;
	pList->currentElementCount++;
	return (TRUE);
}

int	removeDLElement(DoublyList* pList, int position)		// 노드 제거
{
	DoublyListNode	*prev;
	DoublyListNode	*temp;
	int	i;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	prev = &pList->headerNode;
	for (i = 0; i < position; i++)
		prev = prev->pRLink;
	temp = prev->pRLink;
	prev->pRLink = temp->pRLink;
	temp->pRLink->pLLink = prev;
	free(temp);
	temp = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

DoublyListNode*	getDLElement(DoublyList* pList, int position) 		// 노드 가져오기
{
	int	i;
	DoublyListNode	*curr;

	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	curr = pList->headerNode.pRLink;
	for (i = 0; i < position; i++)
		curr = curr->pRLink;
	return (curr);
}

void	displayDoublyList(DoublyList* pList)
{
	DoublyListNode	*curr;
	int	i;

	curr = pList->headerNode.pRLink;
	if (curr == &pList->headerNode)
		printf("empty list");
	else{
		for (i = 0; i <= pList->currentElementCount; i++)
		{
			if (curr == &pList->headerNode)
			{
				printf("header\t");
				i--;
			}
			else
				printf("(%d) %d\t", i % pList->currentElementCount, curr->data);
			curr = curr->pRLink;
		}
	}
	printf("\n");
}

void	clearDoublyList(DoublyList* pList) 		// list 초기화
{
	DoublyListNode	*curr;
	DoublyListNode	*next;

	curr = pList->headerNode.pRLink;
	while (pList->currentElementCount)
	{
		next = curr->pRLink;
		free(curr);
		curr = next;
		pList->currentElementCount--;
	}
	pList->headerNode.pLLink = &pList->headerNode;
	pList->headerNode.pRLink = &pList->headerNode;
}

int	getDoublyListLength(DoublyList* pList) 		// list 노드의 개수 확인
{
	return (pList->currentElementCount);
}

void	deleteDoublyList(DoublyList* pList) 	// list free
{
	clearDoublyList(pList);
	free(pList);
	pList = NULL;
}
