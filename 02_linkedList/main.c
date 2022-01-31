#include "linkedlist.h"

/* TEST: linkedlist 추가 삭제 */
void	basic_test(void)
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
void	reverse_test(void)
{
	LinkedList*	list;
	ListNode	node;
	int			i;

	list = createLinkedList();
	for (i = 0; i < 32; i++)
	{
		node.data = i + 1;
		addLLElement(list, i, node);
	}
	displayLinkedList(list);

	reverseLinkedList(list);
	displayLinkedList(list);

	deleteLinkedList(list);
}

void	polynomial_test(void)
{
	LinkedList	*list1;
	LinkedList	*list2;
	ListNode	node;
	LinkedList	*new_list;

	// A 다항식 연결 리스트: 3x^6 + 2x^4 + 4x^2
	list1 = createLinkedList();
	if (!list1)
		return ;
	
	// x^4
	node.degree = 4;
	node.coef = 1;
	addPolyElement(list1, node);

	// 3x^6
	node.degree = 6;
	node.coef = 3;
	addPolyElement(list1, node);

	// 4x^2
	node.degree = 2;
	node.coef = 4;
	addPolyElement(list1, node);

	// x^4
	node.degree = 4;
	node.coef = 1;
	addPolyElement(list1, node);
	displayPolyList(list1);

	// B 다항식 연결 리스트: x^5 + 2x^4 + 3x^2 + 4
	list2 = createLinkedList();
	if (!list2)
		return ;
	
	// x^5
	node.degree = 5;
	node.coef = 1;
	addPolyElement(list2, node);

	// 2x^4
	node.degree = 4;
	node.coef = 2;
	addPolyElement(list2, node);

	// 3x^2
	node.degree = 2;
	node.coef = 3;
	addPolyElement(list2, node);

	// 4
	node.degree = 0;
	node.coef = 4;
	addPolyElement(list2, node);
	displayPolyList(list2);

	// A + B
	new_list = addPolyLists(list1, list2);
	displayPolyList(new_list);	// 3x^6 + x^5 + 4x^4 + 7x^2 + 4

	deleteLinkedList(list1);
	deleteLinkedList(list2);
	deleteLinkedList(new_list);
}

int main(void)
{
	polynomial_test();
	// system("leaks linkedlist");
	return (0);
}
