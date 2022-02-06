#include "linkedstack.h"

void	stack_test(void)
{
	LinkedStack		*stack;
	StackNode		element;
	StackNode		*result;

	stack = createLinkedStack();
	element.data = 'a';
	pushLS(stack, element);
	element.data = 'b';
	pushLS(stack, element);
	element.data = 'c';
	pushLS(stack, element);
	displayLinkedStack(stack);

	result = peekLS(stack);
	printf("peek: %c\n", result->data);

	result = popLS(stack);
	printf("pop: %c\n", result->data);
	free(result);
	result = popLS(stack);
	printf("pop: %c\n", result->data);
	free(result);
	result = popLS(stack);
	printf("pop: %c\n", result->data);
	free(result);
	result = popLS(stack);
	if (result)
		printf("pop: %c\n", result->data);
	displayLinkedStack(stack);

	deleteLinkedStack(&stack);
	displayLinkedStack(stack);
}

void	maze_test(void)
{
	StackNode	startPos;
	LinkedStack	*stack;
	int			result;
	// int			map[HEIGHT][WIDTH] = {
	// 				{3, 0, 1, 1, 1, 1, 1, 1},
	// 				{1, 0, 0, 0, 0, 0, 0, 1},
	// 				{1, 1, 1, 0, 1, 1, 1, 1},
	// 				{1, 1, 1, 0, 1, 1, 1, 1},
	// 				{1, 0, 0, 0, 0, 0, 0, 1},
	// 				{1, 0, 1, 1, 1, 1, 1, 1},
	// 				{1, 0, 0, 0, 0, 0, 0, 0},
	// 				{1, 1, 1, 1, 1, 1, 1, 4},
	// 			};

	// int			map[HEIGHT][WIDTH] = {
	// 				{4, 0, 1, 1, 1, 1, 1, 1},
	// 				{1, 0, 0, 0, 0, 0, 0, 1},
	// 				{1, 1, 1, 0, 1, 1, 1, 1},
	// 				{1, 1, 1, 0, 1, 1, 1, 1},
	// 				{1, 0, 0, 0, 0, 0, 0, 1},
	// 				{1, 0, 1, 1, 1, 1, 1, 1},
	// 				{1, 0, 0, 0, 0, 0, 0, 0},
	// 				{1, 1, 1, 1, 1, 1, 1, 3},
	// 			};

	int			map[HEIGHT][WIDTH] = {
					{4, 0, 1, 1, 1, 1, 1, 1},
					{1, 0, 0, 0, 0, 0, 0, 1},
					{1, 1, 1, 0, 1, 1, 1, 1},
					{1, 1, 1, 0, 1, 1, 1, 1},
					{1, 0, 0, 3, 0, 0, 0, 1},
					{1, 0, 1, 1, 1, 1, 1, 1},
					{1, 0, 0, 0, 0, 0, 0, 0},
					{1, 1, 1, 1, 1, 1, 1, 1},
				};
	
	result = findPosition(map, &startPos, START);
	if (result == FALSE)
		exitError("Failed to find start position", NULL);
	stack = createLinkedStack();
	if (stack == NULL)
		exitError("Failed to create stack", stack);
	findPath(map, startPos, stack);
}

int	main(void)
{
	// stack_test();
	maze_test();
	// system("leaks linkedstack");
	return (0);
}
