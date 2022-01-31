#include "doublylist.h"

void	func()
{
	DoublyList		*pList;
	DoublyListNode	*temp;
	DoublyListNode	node;
	int				number;
	int				position;
	int				is_exit;

	pList = createDoublyList();
	is_exit = 0;
	while (1)
	{
		if (is_exit)
			break ;
		printf("1: Add\n2: Remove\n3: Get\n4: Clear\n5: Display\n6: Exit\n");
		scanf("%d", &number);
		getchar();
		switch (number)
		{
		case 1:
			printf("{data, position} : ");
			scanf("%d %d", &node.data, &position);
			addDLElement(pList, position, node);
			printf("\n");
			displayDoublyList(pList);
			printf("\n");
			break;
		case 2:
			printf("position : ");
			scanf("%d", &position);
			removeDLElement(pList, position);
			printf("\n");
			displayDoublyList(pList);
			printf("\n");
			break;
		case 3:
			printf("position : ");
			scanf("%d", &position);
			temp = getDLElement(pList, position);
			if (temp)
			{
				printf("\n");
				printf("%d\n\n", temp->data);
			}
			break;
		case 4:
			clearDoublyList(pList);
			printf("\n");
			displayDoublyList(pList);
			printf("\n");
			break;
		case 5:
			printf("\n");
			displayDoublyList(pList);
			printf("\n");
			break;
		case 6:
			is_exit = 1;
			break;
		default:
			break;
		}
	}
	deleteDoublyList(&pList);
}

int main(void)
{
	func();
	// system("leaks doublylist");
	return (0);
}
