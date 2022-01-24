#include "linkedlist.h"

LinkedList*	createLinkedList()		// linkedlist 생성
{
	LinkedList* linkedlist;

	linkedlist = (LinkedList*)malloc(sizeof(LinkedList));
	if (linkedlist == NULL)
		return (NULL);
	linkedlist->currentElementCount = 0;
	return (linkedlist);
}

int	addLLElement(LinkedList* pList, int position, ListNode element)		// 노드 추가
{
	ListNode	*curr;
	ListNode	*addNode;
	int	i;

	addNode = (ListNode *)malloc(sizeof(ListNode));
	if (addNode == NULL)
		return (FALSE);
	*addNode = element;
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (position == 0)
	{
		addNode->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = addNode;
		pList->currentElementCount++;
	}
	else
	{
		curr = pList->headerNode.pLink;
		for (i = 0; i < position - 1; i++)
			curr = curr->pLink;
		addNode->pLink = curr->pLink;
		curr->pLink = addNode;
		pList->currentElementCount++;
	}
	return (TRUE);
}

int	removeLLElement(LinkedList* pList, int position)		// 노드 제거
{
	ListNode *curr;
	ListNode *temp;
	int	i;

	curr = pList->headerNode.pLink;
	if (position < 0 || position >= pList->currentElementCount || pList->currentElementCount == 0)
		return (FALSE);
	if (position == 0)
	{
		temp = curr;
		pList->headerNode.pLink = curr->pLink;
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

ListNode*	getLLElement(LinkedList* pList, int position) 		// 노드 가져오기
{
	int	i;
	ListNode	*curr;

	if (position < 0 || position >= pList->currentElementCount || pList->currentElementCount == 0)
		return (NULL);
	curr = pList->headerNode.pLink;
	for (i = 0; i < position; i++)
		curr = curr->pLink;
	return (curr);
}

void	clearLinkedList(LinkedList* pList) 		// linkedlist 초기화
{
	while (pList->currentElementCount)
		removeLLElement(pList, 0);
}

int	getLinkedListLength(LinkedList* pList) 		// linkedlist 노드의 개수 확인
{
	return (pList->currentElementCount);
}
void	deleteLinkedList(LinkedList* pList) 	// linkedlist free
{
	clearLinkedList(pList);
	free(pList);
	pList = NULL;
}
