#ifndef _LINKED_STACK_
#define _LINKED_STACK_
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNodeType
{
	char					data;
	struct StackNodeType*	pLink;
} StackNode;

typedef struct LinkedStackType
{
	int			currentElementCount;
	StackNode*	pTopElement;
}	LinkedStack;

LinkedStack*	createLinkedStack();							// 스택 생성
int				pushLS(LinkedStack* pStack, StackNode element);	// 노드 추가
StackNode*		popLS(LinkedStack* pStack);						// 노드 제거
StackNode*		peekLS(LinkedStack* pStack);					// 노드 반환
void			deleteLinkedStack(LinkedStack** pStack);			// 스택 제거
// int				isLinkedStackFull(LinkedStack* pStack);			// 스택이 찼는지 확인
int				isLinkedStackEmpty(LinkedStack* pStack);		// 스택이 비었는지 확인

void			displayLinkedStack(LinkedStack* pStack);
#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
