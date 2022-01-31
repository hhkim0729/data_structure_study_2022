#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStackNodeType {
	char	data;
}	ArrayStackNode;

typedef struct ArrayStackType {
	int				maxElementCount;
	int				currentElementCount;
	ArrayStackNode	*pElement;
}	ArrayStack;

ArrayStack*		createArrayStack(int maxElementCount);				// 스택 생성
int				pushAS(ArrayStack* pStack, ArrayStackNode element);	// 노드 추가
ArrayStackNode*	popAS(ArrayStack* pStack);							// 노드 제거
ArrayStackNode*	peekAS(ArrayStack* pStack);							// 노드 반환
void			deleteArrayStack(ArrayStack** pStack);				// 스택 제거
int				isArrayStackFull(ArrayStack* pStack);				// 스택이 찼는지 확인
int				isArrayStackEmpty(ArrayStack* pStack);				// 스택이 비었는지 확인

void			displayArrayStack(ArrayStack* pStack);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
