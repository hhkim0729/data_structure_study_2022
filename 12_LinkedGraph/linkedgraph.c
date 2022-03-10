#include "linkedgraph.h"

LinkedGraph*	createLinkedGraph(int maxVertexCount)
{
	LinkedGraph	*graph;
	int			*vertex;
	LinkedList	**edge;
	int			i;
	int			j;

	graph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	if (graph == NULL)
		return (NULL);
	vertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (vertex == NULL)
	{
		free(graph);
		return (NULL);
	}
	edge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);
	if (edge == NULL)
	{
		free(graph);
		free(vertex);
		return (NULL);
	}
	for (i = 0; i < maxVertexCount; i++)
	{
		edge[i] = createLinkedList();
		if (edge[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(edge[j]);
			free(graph);
			free(vertex);
			free(edge);
			return (NULL);
		}
	}
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->currentEdgeCount = 0;
	graph->graphType = GRAPH_UNDIRECTED;
	graph->ppAdjEdge = edge;
	graph->pVertex = vertex;
	return (graph);
}

LinkedGraph*	createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *graph;
	int			*vertex;
	LinkedList	**edge;
	int			i;
	int			j;

	graph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	if (graph == NULL)
		return (NULL);
	vertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (vertex == NULL)
	{
		free(graph);
		return (NULL);
	}
	edge = (LinkedList **)malloc(sizeof(LinkedList) * maxVertexCount);
	if (!edge)
	{
		free(graph);
		free(vertex);
		return (NULL);
	}
	for (i = 0; i < maxVertexCount; i++)
	{
		edge[i] = createLinkedList();
		if (edge[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(edge[j]);
			free(graph);
			free(vertex);
			free(edge);
			return (NULL);
		}
	}
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->currentEdgeCount = 0;
	graph->graphType = GRAPH_DIRECTED;
	graph->pVertex = vertex;
	graph->ppAdjEdge = edge;
	return (graph);
}

// 그래프 삭제
void	deleteLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->ppAdjEdge[i])
			deleteLinkedList(&(pGraph->ppAdjEdge[i]));
	}
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

// 공백 그래프 여부 판단
int	isEmptyLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount == 0);
}

// 노드 추가
int	addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	ListNode	node;

	if (vertexID < 0 || vertexID >= pGraph->maxVertexCount || checkVertexValid(pGraph, vertexID))
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	node.data = vertexID;
	if (addLLElement(pGraph->ppAdjEdge[vertexID], 0, node) == FAIL)
		return (FAIL);
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

// 간선 추가
int	addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	ListNode	node;

	if (checkVertexValid(pGraph, fromVertexID) == FAIL || checkVertexValid(pGraph, toVertexID) == FAIL)
		return (FAIL);
	node.data = toVertexID;
	node.weight = 1;
	if (addLLElement(pGraph->ppAdjEdge[fromVertexID], pGraph->ppAdjEdge[fromVertexID]->currentElementCount, node) == FAIL)
		return (FAIL);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		node.data = fromVertexID;
		if (addLLElement(pGraph->ppAdjEdge[toVertexID], pGraph->ppAdjEdge[toVertexID]->currentElementCount, node) == FAIL)
			return (FAIL);
	}
	pGraph->currentEdgeCount++;
	return (SUCCESS);
}

int	addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode	node;

	if (checkVertexValid(pGraph, fromVertexID) == FAIL || checkVertexValid(pGraph, toVertexID) == FAIL)
		return (FAIL);
	node.data = toVertexID;
	node.weight = weight;
	if (addLLElement(pGraph->ppAdjEdge[fromVertexID], pGraph->ppAdjEdge[fromVertexID]->currentElementCount, node) == FAIL)
		return (FAIL);
	if(pGraph->graphType == GRAPH_UNDIRECTED)
	{
		node.data = fromVertexID;
		if (addLLElement(pGraph->ppAdjEdge[toVertexID], pGraph->ppAdjEdge[toVertexID]->currentElementCount, node) == FAIL)
			return (FAIL);
	}
	pGraph->currentEdgeCount++;
	return (SUCCESS);
}

// 노드의 유효성 점검.
int	checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (vertexID < 0 || vertexID >= pGraph->maxVertexCount)
		return (FAIL);
	return (pGraph->pVertex[vertexID] == USED);
}

// 노드 제거
int	removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	int			i;
	ListNode	*node;

	if (checkVertexValid(pGraph, vertexID) == FAIL)
		return (FAIL);
	node = pGraph->ppAdjEdge[vertexID]->headerNode.pLink->pLink;
	while (node)
	{
		if (removeEdgeLG(pGraph, vertexID, node->data) == FAIL)
				return (FAIL);
		node = node->pLink;
	}
	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED && i != vertexID)
		{
			node = pGraph->ppAdjEdge[i]->headerNode.pLink->pLink;
			while (node)
			{
				if (node->data == vertexID)
				{
					if (removeEdgeLG(pGraph, i, vertexID) == FAIL)
							return (FAIL);
				}
				node = node->pLink;
			}
		}
	}
	clearLinkedList(pGraph->ppAdjEdge[vertexID]);
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

// 간선 제거
int	removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) == FAIL || checkVertexValid(pGraph, toVertexID) == FAIL)
		return (FALSE);
	deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
	pGraph->currentEdgeCount--;
	return (SUCCESS);
}

void	deleteGraphNode(LinkedList* pList, int delVertexID)
{
	int	position;

	position = findGraphNodePosition(pList, delVertexID);
	removeLLElement(pList, position);
}

int	findGraphNodePosition(LinkedList* pList, int vertexID)
{
	ListNode	*edge;
	int			i;

	i = 0;
	edge = pList->headerNode.pLink;
	while (edge)
	{
		if (edge->data == vertexID)
			break ;
		edge = edge->pLink;
		i++;
	}
	return (i);
}

// 간선 개수 반환
int	getEdgeCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount);
}

// 노드 개수 반환
int	getVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentEdgeCount);
}

// 최대 노드 개수 반환
int	getMaxVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->maxVertexCount);
}

int	getGraphTypeLG(LinkedGraph* pGraph)
{
	return (pGraph->graphType);
}

void	displayLinkedGraph(LinkedGraph* pGraph)
{
	char		*type;
	ListNode	*node;

	if (!pGraph)
	{
		printf("No graph\n\n");
		return ;
	}
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		type = "Undirected Graph";
	else
		type = "Directed Graph";
	printf("1. Graph type: %s\n", type);
	printf("2. Max vertex count: %d\n", pGraph->maxVertexCount);
	printf("3. Current vertex count: %d\n", pGraph->currentVertexCount);
	printf("4. Current edge count: %d\n", pGraph->currentEdgeCount);
	printf("5. Graph node\n");
	if (pGraph->currentVertexCount == 0)
	{
		printf("Empty graph\n\n");
		return ;
	}
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
		{
			node = pGraph->ppAdjEdge[i]->headerNode.pLink;
			printf("[%d]", node->data);
			node = node->pLink;
			while (node)
			{
				if (pGraph->graphType == GRAPH_DIRECTED)
					printf(" -> ");
				else
					printf(" - ");
				printf("[%d](%d)", node->data, node->weight);
				node = node->pLink;
			}
			printf("\n");
		}
		node = &(pGraph->ppAdjEdge[i]->headerNode);
	}
	printf("\n");
}

// DFS
void searchDFS(LinkedGraph* pGraph)
{
	LinkedDeque	*deque;
	DequeNode	node;
	DequeNode	*pop;
	ListNode	*curr;
	int			i;

	deque = createLinkedDeque();
	if (deque == NULL)
		return ;
	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
		{
			pGraph->ppAdjEdge[i]->headerNode.pLink->visited = TRUE;
			node.vertexId = i;
			break ;
		}
	}
	printf("===== DFS =====\n");
	insertFrontLD(deque, node);
	while (isLinkedDequeEmpty(deque) == FALSE)
	{
		pop = deleteFrontLD(deque);
		printf("%d ", pop->vertexId);
		curr = pGraph->ppAdjEdge[pop->vertexId]->headerNode.pLink->pLink;
		while (curr)
		{
			if (pGraph->ppAdjEdge[curr->data]->headerNode.pLink->visited == FALSE)
			{
				pGraph->ppAdjEdge[curr->data]->headerNode.pLink->visited = TRUE;
				node.vertexId = curr->data;
				insertFrontLD(deque, node);
			}
			curr = curr->pLink;
		}
		free(pop);
	}
	printf("\n\n");
	deleteLinkedDeque(deque);
}

// BFS
void searchBFS(LinkedGraph* pGraph)
{
	LinkedDeque	*deque;
	DequeNode	*pop;
	DequeNode	node;
	ListNode	*curr;
	int			i;

	deque = createLinkedDeque();
	if (deque == NULL)
		return ;
	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
		{
			pGraph->ppAdjEdge[i]->headerNode.pLink->visited = 1;
			node.vertexId = i;
			break ;
		}
	}
	printf("===== BFS =====\n");
	insertRearLD(deque, node);
	while (isLinkedDequeEmpty(deque) == FALSE)
	{
		pop = deleteFrontLD(deque);
		printf("%d ", pop->vertexId);
		curr = pGraph->ppAdjEdge[pop->vertexId]->headerNode.pLink->pLink;
		while (curr)
		{
			if (pGraph->ppAdjEdge[curr->data]->headerNode.pLink->visited == 0)
			{
				node.vertexId = curr->data;
				pGraph->ppAdjEdge[curr->data]->headerNode.pLink->visited = 1;
				insertRearLD(deque, node);
			}
			curr = curr->pLink;
		}
		free(pop);
	}
	deleteLinkedDeque(deque);
	printf("\n\n");
}
