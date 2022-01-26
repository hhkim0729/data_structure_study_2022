#include "doublylist.h"

void	func()
{
	DoublyList	*list;
	DoublyListNode	node;
	
	list = createDoublyList();
	displayDoublyList(list);

	node.data = 10;
	addDLElement(list, 0, node);
	displayDoublyList(list);

	node.data = 15;
	addDLElement(list, 0, node);
	displayDoublyList(list);

	node.data = 20;
	addDLElement(list, 1, node);
	displayDoublyList(list);

	node.data = 30;
	addDLElement(list, 2, node);
	displayDoublyList(list);

	node.data = 40;
	addDLElement(list, 3, node);
	displayDoublyList(list);

	removeDLElement(list, 3);
	displayDoublyList(list);

	removeDLElement(list, 0);
	displayDoublyList(list);

	clearDoublyList(list);
	displayDoublyList(list);
	deleteDoublyList(list);
}

int main(void)
{
	func();
	// system("leaks a.out");
	return (0);
}
