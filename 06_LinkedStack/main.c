#include "linkedstack.h"

void	test(void)
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

int	main(void)
{
	test();
	// system("leaks linkedstack");
	return (0);
}
