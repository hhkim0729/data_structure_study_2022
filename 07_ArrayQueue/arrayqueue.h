#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayQueueNodeType
{
	char	data;
	int		arrivalTime;	// 도착 시각.
	int		serviceTime;	// 서비스 시간.
	int		startTime;		// 시작 시각.
	int		endTime;		// 종료 시각: 시작 시각 + 서비스 시간.
}	ArrayQueueNode;

typedef struct ArrayQueueType
{
	int				maxElementCount;		// 최대 원소 개수
	int				currentElementCount;	// 현재 원소의 개수
	int				front;					// front 위치
	int				rear;					// rear 위치
	ArrayQueueNode	*pElement;				// 노드 저장을 위한 1차원 배열 포인터
}	ArrayQueue;

ArrayQueue*		createArrayQueue(int maxElementCount);
int				enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element);
ArrayQueueNode	*dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode	*peekAQ(ArrayQueue* pQueue);
void			deleteArrayQueue(ArrayQueue** pQueue);
int				isArrayQueueFull(ArrayQueue* pQueue);
int				isArrayQueueEmpty(ArrayQueue* pQueue);

void			displayArrayQueue(ArrayQueue *pQueue);

// 은행 시뮬레이션
void			insertCustomer(int arrivalTime, int serviceTime, ArrayQueue *pArrivalQueue);	// 새로운 고객을 도착 큐에 추가 -> 도착시간 설정 & 서비스 시간 설정 : 시뮬레이션 실행 전에 미리 셋팅을 위한 함수
void			processArrival(int currentTime, ArrayQueue *pArrivalQueue, ArrayQueue *pWaitQueue);	// 현재 시각 == 도착 시각이 같은 고객을 대기 큐로 이동 : 시스템 시각이 증가할 때마다 실행
ArrayQueueNode*	processServiceNodeStart(int currentTime, ArrayQueue *pWaitQueue);	// 서비스 중인 고객이 없는 경우 대기 큐에서 고객 디큐
ArrayQueueNode*	processServiceNodeEnd(int currentTime, ArrayQueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);	// 현재 서비스 중이던 고객의 서비스가 완료된 경우 메모리 해제, 서비스 고객 수와 대기 시간 증가
void			printSimCustomer(ArrayQueueNode customer);	// 고객 정보 출력
void			printWaitQueueStatus(int currentTime, ArrayQueue *pWaitQueue);	// 현재 시각 기준 대기 큐 고객 목록 상태 출력
void			printReport(ArrayQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);	// 종료 시각 기준으로 남은 고객 목록이랑, 서비스 완료한 고객 + 총 대기 시간 출력

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif
