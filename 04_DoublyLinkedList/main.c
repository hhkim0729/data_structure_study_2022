#include "circularlinkedlist.h"

void	func()
{
	CircularList	*list;
	CircularListNode	node;
	
	list = createCircularList();
	node.pLink = NULL;

	node.data = 10;
	addCLElement(list, 0, node);
	displayCircularList(list);

	node.data = 15;
	addCLElement(list, 0, node);
	displayCircularList(list);

	node.data = 20;
	addCLElement(list, 1, node);
	displayCircularList(list);

	node.data = 30;
	addCLElement(list, 2, node);
	displayCircularList(list);

	node.data = 40;
	addCLElement(list, 3, node);
	displayCircularList(list);

	removeCLElement(list, 3);
	displayCircularList(list);

	removeCLElement(list, 0);
	displayCircularList(list);

	clearCircularList(list);
	displayCircularList(list);
	deleteCircularList(list);
}

int main(void)
{
	func();
	// system("leaks a.out");
	return (0);
}
