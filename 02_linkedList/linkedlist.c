#include "linkedlist.h"

LinkedList	*createLinkedList() // linkedlist 생성
{
	LinkedList	*list;

	list = (LinkedList *)malloc(sizeof(LinkedList));
	if (list == NULL)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.pLink = NULL;
	return (list);
}

int	addLLElement(LinkedList *pList, int position, ListNode element) // 노드 추가
{
	ListNode	*prev;
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
		prev = getLLElement(pList, position - 1);
		new->pLink = prev->pLink;
		prev->pLink = new;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int	removeLLElement(LinkedList *pList, int position) // 노드 제거
{
	ListNode	*prev;
	ListNode	*temp;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	if (position == 0)
	{
		temp = pList->headerNode.pLink;
		pList->headerNode.pLink = temp->pLink;
	}
	else
	{
		prev = getLLElement(pList, position - 1);
		temp = prev->pLink;
		prev->pLink = prev->pLink->pLink;
	}
	free(temp);
	temp = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

ListNode	*getLLElement(LinkedList *pList, int position) // 노드 가져오기
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

	if (pList == NULL)
		return;
	curr = pList->headerNode.pLink;
	if (curr == NULL)
		printf("empty list");
	while (curr)
	{
		printf("%d ", curr->data);
		curr = curr->pLink;
	}
	printf("\n");
}

void	clearLinkedList(LinkedList *pList) // linkedlist 초기화
{
	ListNode	*curr;
	ListNode	*next;

	if (pList == NULL)
		return;
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

int	getLinkedListLength(LinkedList *pList) // linkedlist 노드의 개수 확인
{
	if (pList == NULL)
		return (ERROR);
	return (pList->currentElementCount);
}

void	deleteLinkedList(LinkedList **pList) // linkedlist free
{
	if (pList == NULL || *pList == NULL)
		return;
	clearLinkedList(*pList);
	free(*pList);
	*pList = NULL;
}

void	reverseLinkedList(LinkedList* pList)
{
	ListNode	*prev;
	ListNode	*curr;
	ListNode	*next;

	if (pList == NULL)
		return ;
	prev = NULL;
	curr = pList->headerNode.pLink;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		next = curr->pLink;
		curr->pLink = prev;
		prev = curr;
		curr = next;
	}
	pList->headerNode.pLink = prev;
}

int	addPolyElement(LinkedList* pList, ListNode element)
{
	ListNode	*curr;
	int			position;

	if (pList == NULL)
		return (FALSE);
	curr = pList->headerNode.pLink;
	position = 0;
	while (curr)
	{
		if (element.degree > curr->degree)
			break ;
		if (element.degree == curr->degree)
		{
			element.coef += curr->coef;
			removeLLElement(pList, position);
			break ;
		}
		position++;
		curr = curr->pLink;
	}
	return (addLLElement(pList, position, element));
}

LinkedList	*addPolyLists(LinkedList *list1, LinkedList *list2)
{
	LinkedList	*new_list;
	ListNode	element;
	ListNode	*ptr1;
	ListNode	*ptr2;

	if (list1 == NULL || list2 == NULL)
		return (NULL);
	new_list = (LinkedList *)malloc(sizeof(LinkedList));
	if (new_list == NULL)
		return (NULL);
	ptr1 = list1->headerNode.pLink;
	ptr2 = list2->headerNode.pLink;
	while (ptr1 && ptr2)
	{
		element = *ptr1;
		if (ptr1->degree > ptr2->degree)
			ptr1 = ptr1->pLink;
		else if (ptr1->degree == ptr2->degree)
		{
			element.coef += ptr2->coef;
			ptr1 = ptr1->pLink;
			ptr2 = ptr2->pLink;
		}
		else
		{
			element = *ptr2;
			ptr2 = ptr2->pLink;
		}
		addLLElement(new_list, new_list->currentElementCount, element);
	}
	while (ptr1)
	{
		element = *ptr1;
		addLLElement(new_list, new_list->currentElementCount, element);
		ptr1 = ptr1->pLink;
	}
	while (ptr2)
	{
		element = *ptr2;
		addLLElement(new_list, new_list->currentElementCount, element);
		ptr2 = ptr2->pLink;
	}
	return (new_list);
}

void	displayPolyList(LinkedList *list)
{
	ListNode	*curr;

	if (list == NULL)
		return ;
	curr = list->headerNode.pLink;
	if (curr == NULL)
		printf("empty list");
	while (curr)
	{
		printf("%.1f", curr->coef);
		if (curr->degree)
			printf("x^%i", curr->degree);
		curr = curr->pLink;
		if (curr)
			printf(" + ");
	}
	printf("\n");
}
