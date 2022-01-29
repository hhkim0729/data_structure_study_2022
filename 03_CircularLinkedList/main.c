#include "circularlist.h"

void	func()
{
	CircularList		*pList;
	CircularListNode	*temp;
	CircularListNode	node;
	int					number;
	int					position;
	int					is_exit;

	pList = createCircularList();
	is_exit = 0;
	while (1)
	{
		if (is_exit)
			break ;
		printf("1: Add\n2: Remove\n3: Get\n4: Clear\n5: Display\n6: Exit\n");
		scanf(" %d", &number);
		switch (number)
		{
		case 1:
			printf("{data, position} : ");
			scanf("%d %d", &node.data, &position);
			addCLElement(pList, position, node);
			printf("\n");
			displayCircularList(pList);
			printf("\n");
			break;
		case 2:
			printf("position : ");
			scanf("%d", &position);
			removeCLElement(pList, position);
			printf("\n");
			displayCircularList(pList);
			printf("\n");
			break;
		case 3:
			printf("position : ");
			scanf("%d", &position);
			temp = getCLElement(pList, position);
			if (temp)
			{
				printf("\n");
				printf("%d\n\n", temp->data);
			}
			break;
		case 4:
			clearCircularList(pList);
			printf("\n");
			displayCircularList(pList);
			printf("\n");
			break;
		case 5:
			printf("\n");
			displayCircularList(pList);
			printf("\n");
			break;
		case 6:
			is_exit = 1;
			break;
		default:
			break;
		}
	}
	deleteCircularList(pList);
}

int main(void)
{
	func();
	// system("leaks circularlist");
	return (0);
}
