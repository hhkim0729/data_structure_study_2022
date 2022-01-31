#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_
#include <stdlib.h>
#include <stdio.h>

typedef struct CircularListNodeType
{
	int								data;
	struct CircularListNodeType*	pLink;
}	CircularListNode;

typedef struct CircularListType
{
	int					currentElementCount;	// 현재 저장된 원소의 개수
	CircularListNode	headerNode;				// 헤더 노드(Header Node)
}	CircularList;

CircularList*		createCircularList();														// list 생성
int					addCLElement(CircularList* pList, int position, CircularListNode element);	// 노드 추가
int					removeCLElement(CircularList* pList, int position);							// 노드 제거
CircularListNode*	getCLElement(CircularList* pList, int position);							// 노드 가져오기
CircularListNode*	getLastCLElement(CircularList* pList);										// 마지막 노드 가져오기

void				displayCircularList(CircularList *lst);										// list 출력
void				clearCircularList(CircularList* pList);										// list 초기화
int					getCircularListLength(CircularList* pList);									// list 노드의 개수 확인
void				deleteCircularList(CircularList** pList);									// list free
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
