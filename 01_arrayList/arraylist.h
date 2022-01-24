#ifndef _ARRAYLIST_
#define _ARRAYLIST_
#include <stdlib.h>
#include <stdio.h>

typedef struct ArrayListNodeType
{
	int	data;
} ArrayListNode;

typedef struct ArrayListType
{
	int				maxElementCount;		// 최대 원소 개수
	int				currentElementCount;	// 현재 원소의 개수
	ArrayListNode*	pElement;				// 원소 저장을 위한 1차원 배열
} ArrayList;

ArrayList*		createArrayList(int maxElementCount);	// arraylist 할당 및 생성
void			deleteArrayList(ArrayList* pList);		// arraylist free
int				isArrayListFull(ArrayList* pList);		// arraylist가 가득 찼는지 확인

int				addALElement(ArrayList* pList, int position, ArrayListNode element);	// arraylist node 추가
int				removeALElement(ArrayList* pList, int position);	// arraylist node 제거
ArrayListNode*	getALElement(ArrayList* pList, int position);		// arraylist node 가져오기

void			displayArrayList(ArrayList* pList);		// arraylist 출력
void			clearArrayList(ArrayList* pList);		// arraylist 초기화
int				getArrayListLength(ArrayList* pList);	// arraylist에 들어가있는 element의 길이 확인

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif