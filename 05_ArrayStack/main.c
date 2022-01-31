#include "arraystack.h"

void	test(void)
{
	ArrayStack		*stack;
	ArrayStackNode	element;
	ArrayStackNode	*result;

	stack = createArrayStack(3);
	element.data = 'a';
	pushAS(stack, element);
	element.data = 'b';
	pushAS(stack, element);
	element.data = 'c';
	pushAS(stack, element);
	element.data = 'd';
	pushAS(stack, element);
	displayArrayStack(stack);

	result = peekAS(stack);
	printf("peek: %c\n", result->data);

	result = popAS(stack);
	printf("pop: %c\n", result->data);
	result = popAS(stack);
	printf("pop: %c\n", result->data);
	result = popAS(stack);
	printf("pop: %c\n", result->data);
	result = popAS(stack);
	if (result)
		printf("pop: %c\n", result->data);
	displayArrayStack(stack);

	deleteArrayStack(&stack);
	displayArrayStack(stack);
}

int	main(void)
{
	test();
	// system("leaks arraystack");
	return (0);
}
