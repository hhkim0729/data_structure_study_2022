#ifndef _LINKED_STACK_
#define _LINKED_STACK_
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNodeType
{
	char					data;
	int						h;
	int						w;
	int						direction;
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
int				isLinkedStackEmpty(LinkedStack* pStack);		// 스택이 비었는지 확인

void			displayLinkedStack(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif

// 미로 찾기
#ifndef _MAP_DEF_
# define _MAP_DEF_

# define WIDTH 8
# define HEIGHT 8

# define NUM_DIRECTIONS 4

// offset: h, w
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, 1},			// 0: 오른쪽으로 이동
	{1, 0},			// 1: 아래로 이동
	{0, -1},		// 2: 왼쪽으로 이동
	{-1, 0}			// 3: 위로 이동
};

enum	PosStatus { NOT_VISITED = 0, WALL = 1, VISITED = 2, START = 3, END = 4 };
enum	PosDirection { RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3 };

void	findPath(int mazeArray[HEIGHT][WIDTH], LinkedStack *pStack);
void	showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void	printMaze(int mazeArray[HEIGHT][WIDTH]);

int		findStartPosition(int mazeArray[HEIGHT][WIDTH], StackNode *position);
int		findDirection(int mazeArray[HEIGHT][WIDTH], StackNode *top);
void	exitError(char *message, LinkedStack *pStack);
void	exitSuccess(char *message, LinkedStack *pStack);
#endif
