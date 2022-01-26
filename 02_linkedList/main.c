#include "linkedlist.h"

void	func()
{
	LinkedList	*linkedlist;
	linkedlist = createLinkedList();

	ListNode	node;
	node.data = 10;
	node.pLink = NULL;
	addLLElement(linkedlist, 0, node);
	displayLinkedList(linkedlist);

	node.data = 20;
	node.pLink = NULL;
	addLLElement(linkedlist, 1, node);
	displayLinkedList(linkedlist);

	node.data = 30;
	node.pLink = NULL;
	addLLElement(linkedlist, 2, node);
	displayLinkedList(linkedlist);

	node.data = 40;
	node.pLink = NULL;
	addLLElement(linkedlist, 3, node);
	displayLinkedList(linkedlist);

	removeLLElement(linkedlist, 3);
	displayLinkedList(linkedlist);

	removeLLElement(linkedlist, 0);
	displayLinkedList(linkedlist);

	clearLinkedList(linkedlist);
	displayLinkedList(linkedlist);
	deleteLinkedList(linkedlist);
}

int main(void)
{
	func();
	// system("leaks a.out");
	return (0);
}
