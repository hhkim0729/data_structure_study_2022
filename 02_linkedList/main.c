#include "linkedlist.h"

/* TEST: linkedlist 추가 삭제 */
void	func1()
{
	LinkedList	*list;
	ListNode	node;
	int			i;

	list = createLinkedList();
	for (i = 0; i < 5; i++)
	{
		node.data = i + 10;
		addLLElement(list, i, node);
		displayLinkedList(list);
	}

	removeLLElement(list, 4);
	displayLinkedList(list);

	removeLLElement(list, 0);
	displayLinkedList(list);

	removeLLElement(list, 1);
	displayLinkedList(list);

	clearLinkedList(list);
	displayLinkedList(list);

	deleteLinkedList(list);
}

/* TEST: linkedlist reverse */
// void func2(void)
// {
// 	LinkedList*	list;
// 	ListNode	node;
// 	int			i;

// 	list = createLinkedList();
// 	for (i = 0; i < 32; i++)
// 	{
// 		node.data = i + 1;
// 		addLLElement(list, i, node);
// 	}
// 	displayLinkedList(list);

// 	reverseLinkedList(list);
// 	displayLinkedList(list);

// 	deleteLinkedList(list);
// }

int main(void)
{
	func1();
	// system("leaks linkedlist");
	return (0);
}
