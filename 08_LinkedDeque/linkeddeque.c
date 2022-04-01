#include "linkeddeque.h"

LinkedDeque*	createLinkedDeque()
{
	LinkedDeque	*deque;

	deque = (LinkedDeque *)malloc(sizeof(LinkedDeque));
	if (deque == NULL)
		return (NULL);
	deque->currentElementCount = 0;
	deque->pFrontNode = NULL;
	deque->pRearNode = NULL;
	return (deque);
}

int	insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*new;

	new = (DequeNode *)malloc(sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	*new = element;
	if (isLinkedDequeEmpty(pDeque) == TRUE)
	{
		new->pLLink = NULL;
		new->pRLink = NULL;
		pDeque->pFrontNode = new;
		pDeque->pRearNode = new;
	}
	else
	{
		new->pLLink = NULL;
		new->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode->pLLink = new;
		pDeque->pFrontNode = new;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int	insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*new;

	new = (DequeNode *)malloc(sizeof(DequeNode));
	if (new == NULL)
		return (FALSE);
	*new = element;
	if (isLinkedDequeEmpty(pDeque) == TRUE)
	{
		new->pLLink = NULL;
		new->pRLink = NULL;
		pDeque->pFrontNode = new;
		pDeque->pRearNode = new;
	}
	else
	{
		new->pRLink = NULL;
		new->pLLink = pDeque->pRearNode;
		pDeque->pRearNode->pRLink = new;
		pDeque->pRearNode = new;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode*	deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode	*ret;

	ret = peekFrontLD(pDeque);
	if (ret == NULL)
		return (NULL);
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	else
	{
		pDeque->pFrontNode = ret->pRLink;
		pDeque->pFrontNode->pLLink = NULL;
	}
	ret->pRLink = NULL;
	pDeque->currentElementCount--;
	return (ret);
}

DequeNode*	deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode	*ret;

	ret = peekRearLD(pDeque);
	if (ret == NULL)
		return (NULL);
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	else
	{
		pDeque->pRearNode = ret->pLLink;
		pDeque->pRearNode->pRLink = NULL;
	}
	ret->pLLink = NULL;
	pDeque->currentElementCount--;
	return (ret);
}

DequeNode*	peekFrontLD(LinkedDeque* pDeque)
{
	if (isLinkedDequeEmpty(pDeque) == TRUE)
		return (NULL);
	return (pDeque->pFrontNode);
}

DequeNode*	peekRearLD(LinkedDeque* pDeque)
{
	if (isLinkedDequeEmpty(pDeque) == TRUE)
		return (NULL);
	return (pDeque->pRearNode);
}

void	deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode	*curr;
	DequeNode	*next;

	curr = pDeque->pFrontNode;
	while (curr)
	{
		next = curr->pRLink;
		free(curr);
		curr = next;
	}
	free(pDeque);
}

int	isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	return (pDeque->currentElementCount == 0);
}

void	displayLinkedDeque(LinkedDeque *pDeque)
{
	DequeNode	*curr;

	curr = pDeque->pFrontNode;
	if (curr == NULL)
	{
		printf("empty deque\n");
		return ;
	}
	while (curr->pRLink)
	{
		// printf("%c -> ", curr->data);
		printf("%d -> ", curr->vertexId);
		curr = curr->pRLink;
	}
	// printf("%c\n", curr->data);
	printf("%d\n", curr->vertexId);
}
