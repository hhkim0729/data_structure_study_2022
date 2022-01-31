#include "arraylist.h"

void	func()
{
	ArrayList		*arrayList;
	ArrayListNode	node;
	ArrayListNode	*result;

	arrayList = createArrayList(10);
	node.data = 123;
	addALElement(arrayList, -1, node);
	node.data = 233;
	addALElement(arrayList, 1, node);
	displayArrayList(arrayList);

	clearArrayList(arrayList);
	node.data = 111;
	addALElement(arrayList, 0, node);
	node.data = 222;
	addALElement(arrayList, 0, node);
	displayArrayList(arrayList);

	result = getALElement(arrayList, 0);
	result->data = 23234;
	displayArrayList(arrayList);

	deleteArrayList(&arrayList);
}

int	main()
{
	func();
	// system("leaks arraylist");
	return (0);
}
