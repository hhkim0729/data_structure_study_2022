#include "linkedstack.h"

LinkedStack*	createLinkedStack()							// 스택 생성
{
	LinkedStack	*stack;

	stack = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (stack == NULL)
		return (NULL);
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

int	pushLS(LinkedStack* pStack, StackNode element)	// 노드 추가
{
	StackNode	*new;
	StackNode	*prev;

	if (pStack == NULL)
		return (FALSE);
	new = (StackNode *)malloc(sizeof(StackNode));
	if (new == NULL)
		return (FALSE);
	*new = element;
	prev = peekLS(pStack);
	new->pLink = prev;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode*	popLS(LinkedStack* pStack)						// 노드 제거
{
	StackNode	*element;

	element = peekLS(pStack);
	if (element == NULL)
		return (NULL);
	if (pStack->currentElementCount == 1)
		pStack->pTopElement = NULL;
	else
		pStack->pTopElement = element->pLink;
	pStack->currentElementCount--;
	return (element);
}

StackNode*	peekLS(LinkedStack* pStack)					// 노드 반환
{
	if (pStack == NULL)
		return (NULL);
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	return (pStack->pTopElement);
}

void	deleteLinkedStack(LinkedStack** pStack)			// 스택 제거
{
	StackNode	*curr;
	StackNode	*next;

	if (pStack == NULL || *pStack == NULL)
		return ;
	curr = (*pStack)->pTopElement;
	while ((*pStack)->currentElementCount)
	{
		next = curr->pLink;
		free(curr);
		curr = next;
		(*pStack)->currentElementCount--;
	}
	free(*pStack);
	*pStack = NULL;
}

int	isLinkedStackEmpty(LinkedStack* pStack)		// 스택이 비었는지 확인
{
	if (pStack == NULL)
		return (ERROR);
	if (pStack->currentElementCount == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	displayLinkedStack(LinkedStack* pStack)
{
	StackNode	*curr;

	if (pStack == NULL)
		return ;
	curr = pStack->pTopElement;
	if (curr == NULL)
		printf("empty stack");
	while (curr)
	{
		printf("%c ", curr->data);
		curr = curr->pLink;
	}
	printf("\n");
}

// 미로 찾기
// 비정상 종료 (w/ memory free)
void	exitError(char *message, LinkedStack *pStack)
{
	fprintf(stderr, "%s\n", message);
	deleteLinkedStack(&pStack);
	// system("leaks linkedstack");
	exit(EXIT_FAILURE);
}

// 정상 종료 (w/ memory free)
void	exitSuccess(char *message, LinkedStack *pStack)
{
	printf("%s\n", message);
	deleteLinkedStack(&pStack);
	// system("leaks linkedstack");
	exit(EXIT_SUCCESS);
}

// START 위치 저장
int	findStartPosition(int mazeArray[HEIGHT][WIDTH], StackNode *position)
{
	int	i;
	int	j;

	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			if (mazeArray[i][j] == START)
			{
				position->h = i;
				position->w = j;
				position->direction = RIGHT;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

// 출구까지의 최단 경로 발자국으로 출력
void	showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode	*current;
	int			i;
	int			j;
	char		footprint;
	char		map[HEIGHT][WIDTH];

	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
			map[i][j] = ' ';
	}
	current = peekLS(pStack);
	if (current == NULL)
		return ;
	while (current)
	{
		if (current->direction == RIGHT)
			footprint = '>';
		else if (current->direction == DOWN)
			footprint = 'v';
		else if (current->direction == LEFT)
			footprint = '<';
		else if (current->direction == UP)
			footprint = '^';
		map[current->h][current->w] = footprint;
		current = current->pLink;
	}
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			if (mazeArray[i][j] == WALL)
				map[i][j] = '*';
			else if (mazeArray[i][j] == START)
				map[i][j] = 'S';
			else if (mazeArray[i][j] == END)
				map[i][j] = 'E';
		}
	}
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
			printf("%c ", map[i][j]);
		printf("\n");
	}
}

// 맵 출력
void	printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int	i;
	int	j;

	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
			printf("%i ", mazeArray[i][j]);
		printf("\n");
	}
}

int	findDirection(int mazeArray[HEIGHT][WIDTH], StackNode *top)
{
	int	h;
	int	w;

	while (top->direction <= UP)
	{
		h = top->h + DIRECTION_OFFSETS[top->direction][0];
		w = top->w + DIRECTION_OFFSETS[top->direction][1];
		if (h >= HEIGHT || w >= WIDTH)
		{
			top->direction++;
			continue ;
		}
		if (mazeArray[h][w] == NOT_VISITED || mazeArray[h][w] == END)
			return (TRUE);
		top->direction++;
	}
	return (FALSE);
}

// 미로 길찾기
void	findPath(int mazeArray[HEIGHT][WIDTH], LinkedStack *pStack)
{
	StackNode	player;
	int			result;
	StackNode	*top;
	StackNode	new;
	StackNode	*tmp;

	result = findStartPosition(mazeArray, &player);
	if (result == FALSE)
		exitError("Failed to find start position", pStack);
	result = pushLS(pStack, player);
	if (result == FALSE)
		exitError("Failed to push map position into stack", pStack);
	while (1)
	{
		top = peekLS(pStack);
		if (top == NULL)
			exitError("Failed to find top node", pStack);
		if (mazeArray[top->h][top->w] == END)
			break ;
		result = findDirection(mazeArray, top);
		if (result)
		{
			new.h = top->h + DIRECTION_OFFSETS[top->direction][0];
			new.w = top->w + DIRECTION_OFFSETS[top->direction][1];
			new.direction = RIGHT;
			pushLS(pStack, new);
			if (mazeArray[new.h][new.w] == NOT_VISITED)
				mazeArray[new.h][new.w] = VISITED;
		}
		else
		{
			if (mazeArray[top->h][top->w] == START)
			{
				printMaze(mazeArray);
				exitSuccess("Invalid path to wayout!", pStack);
			}
			else
			{
				tmp = popLS(pStack);
				free(tmp);
				tmp = NULL;
			}
		}
	}
	showPath(pStack, mazeArray);
	exitSuccess("Success!", pStack);
}
