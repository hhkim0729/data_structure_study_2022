#include "linkedgraph.h"

void	dijkstra(LinkedGraph *pGraph)
{
	int			dist[pGraph->maxVertexCount];
	int			i;
	Heap		*heap;
	HeapNode	node;
	HeapNode	*parent;
	ListNode	*curr;

	heap = createHeap(pGraph->currentEdgeCount);
	if (heap == NULL)
		return ;
	for (i = 0; i < pGraph->maxVertexCount; i++)
		dist[i] = INF;
	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
			break;
	}
	dist[i] = 0;
	node.vertexId = i;
	node.key = dist[i];
	if (insertMinHeap(heap, node) == FALSE)
		return ;
	printf("======= Dijkstra =======\n");
	while (isHeapEmpty(heap) == FALSE)
	{
		parent = getMinHeapNode(heap);
		if (parent == NULL)
			return ;
		if (pGraph->ppAdjEdge[parent->vertexId]->headerNode.pLink->visited == FALSE)
		{
			curr = pGraph->ppAdjEdge[parent->vertexId]->headerNode.pLink->pLink;
			while (curr)
			{
				if (pGraph->ppAdjEdge[curr->data]->headerNode.pLink->visited == FALSE && dist[curr->data] > dist[parent->vertexId] + curr->weight)
				{
					dist[curr->data] = dist[parent->vertexId] + curr->weight;
					node.vertexId = curr->data;
					node.key = dist[curr->data];
					if (insertMinHeap(heap, node) == FALSE)
						return ;
				}
				curr = curr->pLink;
			}
		}
		pGraph->ppAdjEdge[parent->vertexId]->headerNode.pLink->visited = TRUE;
		free(parent);
		for (i = 0; i < pGraph->maxVertexCount; i++)
		{
			if (dist[i] == INF)
				printf("%-4s", "INF");
			else
				printf("%-4d", dist[i]);
		}
		printf("\n");
	}
	printf("\n");
	deleteHeap(&heap);
}

void floyd(LinkedGraph *pGraph)
{
	int			dist[pGraph->maxVertexCount][pGraph->maxVertexCount];
	int			i;
	int			j;
	int			k;
	ListNode	*curr;

	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (j = 0; j < pGraph->maxVertexCount; j++)
		{
			dist[i][j] = INF;
			if (i == j)
				dist[i][j] = 0;
		}
	}
	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
		{
			curr = pGraph->ppAdjEdge[i]->headerNode.pLink->pLink;
			while (curr)
			{
				dist[i][curr->data] = curr->weight;
				curr = curr->pLink;
			}
		}
	}
	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (j = 0; j < pGraph->maxVertexCount; j++)
		{
			for (k = 0; k < pGraph->maxVertexCount; k++)
			{
				if (dist[j][k] > dist[j][i] + dist[i][k])
					dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}
	printf("======= Floyd =======\n");
	for (i = 0; i < pGraph->maxVertexCount; i++)
		printf("%-4d", dist[0][i]);
	printf("\n\n");
}
