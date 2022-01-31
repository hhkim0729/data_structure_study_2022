#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include <stdlib.h>
#include <stdio.h>

typedef struct ListNodeType
{
	int					data;
	float				coef;
	int					degree;
	struct ListNodeType	*pLink;
}	ListNode;

typedef struct LinkedListType
{
	int			currentElementCount; // 현재 저장된 원소의 개수
	ListNode	headerNode;	 // 헤더 노드(Header Node)
}	LinkedList;

LinkedList	*createLinkedList();										 		// linkedlist 생성
int			addLLElement(LinkedList *pList, int position, ListNode element);	// 노드 추가
int			removeLLElement(LinkedList *pList, int position);					// 노드 제거
ListNode	*getLLElement(LinkedList *pList, int position);						 // 노드 가져오기

void		displayLinkedList(LinkedList *lst);		// linkedlist 출력
void		clearLinkedList(LinkedList *pList);		// linkedlist 초기화
int			getLinkedListLength(LinkedList *pList);	// linkedlist 노드의 개수 확인
void		deleteLinkedList(LinkedList **pList);	// linkedlist free

void		reverseLinkedList(LinkedList* pList);					// linkedlist 역순
int			addPolyElement(LinkedList* pList, ListNode element);	// 다항식 노드 추가
LinkedList	*addPolyLists(LinkedList *list1, LinkedList *list2);	// 다항식 덧셈
void		displayPolyList(LinkedList *list);						// 다항식 출력
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0
#define ERROR	-1

#endif
