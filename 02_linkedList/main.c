#include "linkedlist.h"

void	list_print(LinkedList *lst)
{
	ListNode	*curr;

	curr = lst->headerNode.pLink;
	// printf("%d\n",curr->data);
	// printf("%d\n",curr->pLink->data);
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->pLink;
	}
	printf("\n");
}

int	func()
{
	LinkedList	*linkedlist;
	linkedlist = createLinkedList();

	ListNode	node;
	node.data = 10;
	node.pLink = NULL;
	addLLElement(linkedlist, 0, node);
	list_print(linkedlist);

	node.data = 20;
	node.pLink = NULL;
	addLLElement(linkedlist, 1, node);
	list_print(linkedlist);

	node.data = 30;
	node.pLink = NULL;
	addLLElement(linkedlist, 2, node);
	list_print(linkedlist);

	node.data = 40;
	node.pLink = NULL;
	addLLElement(linkedlist, 3, node);
	list_print(linkedlist);

	removeLLElement(linkedlist, 3);
	list_print(linkedlist);

	removeLLElement(linkedlist, 0);
	list_print(linkedlist);

	clearLinkedList(linkedlist);
	list_print(linkedlist);
	deleteLinkedList(linkedlist);
}

int main(void)
{
	func();
	system("leaks a.out");
	return (0);
}