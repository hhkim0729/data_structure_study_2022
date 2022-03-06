#include "arraygraph.h"

ArrayGraph*	createArrayGraph(int maxVertexCount)
{
	ArrayGraph	*graph;
	int			*vertex;
	int			**edge;
	int			i;
	int			j;

	graph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	if (graph == NULL)
		return (NULL);
	vertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (vertex == NULL)
	{
		free(graph);
		return (NULL);
	}
	for (i = 0; i < maxVertexCount; i++)
		vertex[i] = NOT_USED;
	edge = (int **)malloc(sizeof(int *) * maxVertexCount);
	if (edge == NULL)
	{
		free(graph);
		free(vertex);
		return (NULL);
	}
	for (i = 0; i < maxVertexCount; i++)
	{
		edge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
		if (edge[i] == NULL)
		{
			free(graph);
			free(vertex);
			for (j = 0; j < i; j++)
				free(edge[j]);
			free(edge);
			return (NULL);
		}
	}
	for (i = 0; i < maxVertexCount; i++)
	{
		for (j = 0; j < maxVertexCount; j++)
			edge[i][j] = 0;
	}
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->graphType = GRAPH_UNDIRECTED;
	graph->pVertex = vertex;
	graph->ppAdjEdge = edge;
	return (graph);
}

ArrayGraph*	createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph	*graph;
	int			*vertex;
	int			**edge;
	int			i;
	int			j;

	graph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	if (graph == NULL)
		return (NULL);
	vertex = (int *)malloc(sizeof(int) * maxVertexCount);
	if (vertex == NULL)
	{
		free(graph);
		return (NULL);
	}
	for (i = 0; i < maxVertexCount; i++)
		vertex[i] = NOT_USED;
	edge = (int **)malloc(sizeof(int *) * maxVertexCount);
	if (edge == NULL)
	{
		free(graph);
		free(vertex);
		return (NULL);
	}
	for (i = 0; i < maxVertexCount; i++)
	{
		edge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
		if (edge[i] == NULL)
		{
			free(graph);
			free(vertex);
			for (j = 0; j < i; j++)
				free(edge[j]);
			free(edge);
			return (NULL);
		}
	}
	for (i = 0; i < maxVertexCount; i++)
	{
		for (j = 0; j < maxVertexCount; j++)
			edge[i][j] = 0;
	}
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->graphType = GRAPH_DIRECTED;
	graph->pVertex = vertex;
	graph->ppAdjEdge = edge;
	return (graph);
}

// 그래프 삭제
void	deleteArrayGraph(ArrayGraph* pGraph)
{
	int	i;

	free(pGraph->pVertex);
	for (i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph);
}

// 공백 그래프 여부 판단
int	isEmptyAG(ArrayGraph* pGraph)
{
	return (pGraph->currentVertexCount == 0);
}

// 노드 추가
int	addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (vertexID < 0 || vertexID >= pGraph->maxVertexCount)
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

// 간선 추가
int	addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) == FAIL || checkVertexValid(pGraph, toVertexID) == FAIL)
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
	return (SUCCESS);
}

int	addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (checkVertexValid(pGraph, fromVertexID) == FAIL || checkVertexValid(pGraph, toVertexID) == FAIL || weight < 0)
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (SUCCESS);
}

// 노드의 유효성 점검.
int	checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (vertexID < 0 || vertexID >= pGraph->maxVertexCount)
		return (FAIL);
	return (pGraph->pVertex[vertexID] == USED);
}

// 노드 제거
int	removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	int	i;

	if (checkVertexValid(pGraph, vertexID) == FAIL)
		return (FAIL);
	pGraph->pVertex[vertexID] = NOT_USED;
	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		pGraph->ppAdjEdge[vertexID][i] = 0;
		pGraph->ppAdjEdge[i][vertexID] = 0;
	}
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

// 간선 제거
int	removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) == FAIL || checkVertexValid(pGraph, toVertexID) == FAIL)
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	return (SUCCESS);
}

// 그래프 정보 출력
void	displayArrayGraph(ArrayGraph* pGraph)
{
	char	*type;

	if (pGraph == NULL)
	{
		printf("No graph\n\n");
		return ;
	}
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		type = "Undirected Graph";
	else
		type = "Directed Graph";
	printf("1. Graph Type: %s\n", type);
	printf("2. Max vertex count: %d\n", pGraph->maxVertexCount);
	printf("3. Current vertex count: %d\n", pGraph->currentVertexCount);
	printf("4. Graph Node\n");
	if (pGraph->currentVertexCount == 0)
	{
		printf("Empty graph\n\n");
		return ;
	}
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
		{
			printf("[%d]", i);
			for (int j = 0; j < pGraph->maxVertexCount; j++)
			{
				if (pGraph->ppAdjEdge[i][j] != 0)
				{
					if (pGraph->graphType == GRAPH_UNDIRECTED)
							printf(" - ");
						else
							printf(" -> ");
					printf("[%d](%d)", j, pGraph->ppAdjEdge[i][j]);
				}
			}
			printf("\n");
		}
	}
	printf("\n");
}

