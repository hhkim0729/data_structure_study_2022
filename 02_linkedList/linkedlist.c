#include "linkedlist.h"

LinkedList*	createLinkedList()		// linkedlist 생성
{
	LinkedList* list;

	list = (LinkedList*)malloc(sizeof(LinkedList));
	if (list == NULL)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.pLink = NULL;
	return (list);
}

int	addLLElement(LinkedList* pList, int position, ListNode element)		// 노드 추가
{
	ListNode	*curr;
	ListNode	*new;

	if (pList == NULL || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	new = (ListNode *)malloc(sizeof(ListNode));
	if (new == NULL)
		return (FALSE);
	*new = element;
	if (position == 0)
	{
		new->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = new;
	}
	else
	{
		curr = getLLElement(pList, position - 1);
		new->pLink = curr->pLink;
		curr->pLink = new;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int	removeLLElement(LinkedList* pList, int position)		// 노드 제거
{
	ListNode *curr;
	ListNode *temp;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	if (position == 0)
	{
		curr = pList->headerNode.pLink;
		temp = curr;
		pList->headerNode.pLink = curr->pLink;
	}
	else
	{
		curr = getLLElement(pList, position - 1);
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
	int			i;
	ListNode	*curr;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
		return (NULL);
	curr = pList->headerNode.pLink;
	for (i = 0; i < position; i++)
		curr = curr->pLink;
	return (curr);
}

void	displayLinkedList(LinkedList *pList)
{
	ListNode	*curr;
	int			i;

	if (pList == NULL)
		return ;
	curr = pList->headerNode.pLink;
	if (!curr)
		printf("empty list");
	else{
		for (i = 0; i < pList->currentElementCount; i++)
		{
			printf("%d ", curr->data);
			curr = curr->pLink;
		}
	}
	printf("\n");
}

void	clearLinkedList(LinkedList* pList) 		// linkedlist 초기화
{
	ListNode	*curr;
	ListNode	*next;

	if (pList == NULL)
		return ;
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

int	getLinkedListLength(LinkedList* pList) 		// linkedlist 노드의 개수 확인
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void	deleteLinkedList(LinkedList* pList) 	// linkedlist free
{
	if (pList == NULL)
		return ;
	clearLinkedList(pList);
	free(pList);
	pList = NULL;
}
