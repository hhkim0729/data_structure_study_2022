#include "linkedgraph.h"

LinkedList	*getSortedEdge(LinkedGraph *pGraph)
{
	LinkedList	*edge;
	int			i;
	ListNode	*node;
	ListNode	element;
	ListNode	*tmpNode;
	int			position;

	edge = createLinkedList();
	if (edge == NULL)
		return (NULL);
	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		node = pGraph->ppAdjEdge[i]->headerNode.pLink->pLink;
		while (node)
		{
			element.start = i;
			element.end = node->data;
			element.weight = node->weight;
			tmpNode = edge->headerNode.pLink;
			position = 0;
			while (tmpNode && tmpNode->weight <= element.weight)
			{
				position++;
				tmpNode = tmpNode->pLink;
			}
			if (element.start < element.end)
			{
				if (addLLElement(edge, position, element) == FALSE)
					return (NULL);
			}
			node = node->pLink;
		}
	}
	return (edge);
}

int	dfs(LinkedGraph *pGraph, int now, int from)
{
	ListNode	*curr;

	curr = pGraph->ppAdjEdge[now]->headerNode.pLink->pLink;
	while (curr)
	{
		if(curr->data == from)
		{
			curr = curr->pLink;
			continue;
		}
		if (pGraph->ppAdjEdge[curr->data]->headerNode.pLink->visited == TRUE)
			return (FALSE);
		pGraph->ppAdjEdge[curr->data]->headerNode.pLink->visited = TRUE;
		dfs(pGraph, curr->data, now);
		curr = curr->pLink;
	}
	return (TRUE);
}

int	checkCycle(LinkedGraph *pGraph, int start)
{
	int	i;

	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
			pGraph->ppAdjEdge[i]->headerNode.pLink->visited = FALSE;
	}
	pGraph->ppAdjEdge[start]->headerNode.pLink->visited = TRUE;
	return (dfs(pGraph, start, start));
}


LinkedGraph	*kruskal(LinkedGraph *pGraph)
{
	LinkedGraph	*new;
	int			i;
	LinkedList	*sortedEdge;
	ListNode	*tmpNode;
	int			position;

	new = createLinkedGraph(pGraph->maxVertexCount);
	if (new == NULL)
		return (NULL);
	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (addVertexLG(new, i) == FALSE)
			return (NULL);
	}
	sortedEdge = getSortedEdge(pGraph);
	if (sortedEdge == NULL)
		return (NULL);
	while (sortedEdge->currentElementCount)
	{
		tmpNode = getLLElement(sortedEdge, 0);
		if (tmpNode == NULL)
			return (NULL);
		if (addEdgewithWeightLG(new, tmpNode->start, tmpNode->end, tmpNode->weight) == FALSE)
			return (NULL);
		if (checkCycle(new, tmpNode->start) == FALSE)
		{
			if (removeEdgeLG(new, tmpNode->start, tmpNode->end) == FALSE)
				return (NULL);
		}
		if (removeLLElement(sortedEdge, 0) == FALSE)
			return (NULL);
	}
	free(sortedEdge);
	return (new);
}

LinkedGraph	*prim(LinkedGraph *pGraph)
{
	LinkedGraph *new;
	int			i;
	LinkedList	*sortedEdge;
	ListNode	*tmpNode;
	int			position;
	int			result;
	int			vertexId;

	new = createLinkedGraph(pGraph->maxVertexCount);
	if (new == NULL)
		return (NULL);
	for (i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
		{
			addVertexLG(new, i);
			break ;
		}
	}
	sortedEdge = getSortedEdge(pGraph);
	if (sortedEdge == NULL)
		return (NULL);
	while (sortedEdge->currentElementCount)
	{
		for (i = 0; i < sortedEdge->currentElementCount; i++)
		{
			tmpNode = getLLElement(sortedEdge, i);
			if (tmpNode == NULL)
				return (NULL);
			if (checkVertexValid(new, tmpNode->start) || checkVertexValid(new, tmpNode->end))
			{
				vertexId = checkVertexValid(new, tmpNode->start) ? tmpNode->end : tmpNode->start;
				position = i;
				break ;
			}
		}
		result = addVertexLG(new, vertexId);
		if (addEdgewithWeightLG(new, tmpNode->start, tmpNode->end, tmpNode->weight) == FALSE)
			return (NULL);
		if (checkCycle(new, tmpNode->start) == FALSE)
		{
			if (removeEdgeLG(new, tmpNode->start, tmpNode->end) == FALSE)
				return (NULL);
			if (result)
			{
				if (removeVertexLG(new, vertexId) == FALSE)
					return (NULL);
			}
		}
		if (removeLLElement(sortedEdge, position) == FALSE)
			return (NULL);
	}
	free(sortedEdge);
	return (new);
}

