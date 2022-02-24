#include "bintree.h"

BinTree	*makeBinTree(BinTreeNode rootNode)
{
	BinTree	*tree;

	tree = (BinTree *)calloc(1, sizeof(BinTree));
	if (tree == NULL)
		return (NULL);
	tree->pRootNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (tree->pRootNode == NULL)
	{
		free(tree);
		return (NULL);
	}
	tree->pRootNode->data = rootNode.data;
	return (tree);
}

BinTreeNode	*getRootNodeBT(BinTree *pBinTree)
{
	if (pBinTree == NULL)
	{
		fprintf(stderr, "ERROR: 트리 없음\n");
		return (NULL);
	}
	return (pBinTree->pRootNode);
}

BinTreeNode	*insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	if (pParentNode == NULL)
	{
		fprintf(stderr, "ERROR: 트리 없음\n");
		return (NULL);
	}
	pParentNode->pLeftChild = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (pParentNode->pLeftChild == NULL)
	{
		fprintf(stderr, "ERROR: 노드 메모리 할당 X\n");
		return (NULL);
	}
	pParentNode->pLeftChild->data = element.data;
	return (pParentNode->pLeftChild);
}

BinTreeNode	*insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	if (pParentNode == NULL)
	{
		fprintf(stderr, "ERROR: 트리 없음\n");
		return (NULL);
	}
	pParentNode->pRightChild = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (pParentNode->pRightChild == NULL)
	{
		fprintf(stderr, "ERROR: 노드 메모리 할당 X\n");
		return (NULL);
	}
	pParentNode->pRightChild->data = element.data;
	return (pParentNode->pRightChild);
}

BinTreeNode	*getLeftChildNodeBT(BinTreeNode *pNode)
{
	if (pNode == NULL)
	{
		fprintf(stderr, "ERROR: 노드 없음\n");
		return (NULL);
	}
	return (pNode->pLeftChild);
}

BinTreeNode	*getRightChildNodeBT(BinTreeNode *pNode)
{
	if (pNode == NULL)
	{
		fprintf(stderr, "ERROR: 노드 없음\n");
		return (NULL);
	}
	return (pNode->pRightChild);
}

void	deleteBinTree(BinTree **pBinTree)
{
	if (pBinTree == NULL || *pBinTree == NULL)
	{
		fprintf(stderr, "ERROR: 트리 없음\n");
		return ;
	}
	deleteBinTreeNode((*pBinTree)->pRootNode);
	free(*pBinTree);
	*pBinTree = NULL;
}

void	deleteBinTreeNode(BinTreeNode *pNode)
{
	if (pNode == NULL)
		return ;
	// 후위순회: L-R-V
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
}

// 순회
// V-L-R
void	preorderTraverse(BinTreeNode *pNode)
{
	if (pNode == NULL)
		return ;
	printf("%c ", pNode->data);
	preorderTraverse(pNode->pLeftChild);
	preorderTraverse(pNode->pRightChild);
}

// L-V-R
void	inorderTraverse(BinTreeNode *pNode)
{
	if (pNode == NULL)
		return ;
	inorderTraverse(pNode->pLeftChild);
	printf("%c ", pNode->data);
	inorderTraverse(pNode->pRightChild);
}

// L-R-V
void	postorderTraverse(BinTreeNode *pNode)
{
	if (pNode == NULL)
		return ;
	postorderTraverse(pNode->pLeftChild);
	postorderTraverse(pNode->pRightChild);
	printf("%c ", pNode->data);
}

// BST
// 이진 탐색 트리 생성
BinTree	*createBinSearchTree(void)
{
	BinTree	*pBinTree;

	pBinTree = (BinTree *)calloc(1, sizeof(BinTree));
	if (pBinTree == NULL)
		return (NULL);
	return (pBinTree);
}

// 자료 추가
int	insertBinSearchTreeNode(BinTree *pBinTree, BinTreeNode element)
{
	BinTreeNode	*parent;
	BinTreeNode	*new;

	if (pBinTree == NULL || searchBinSearchTreeNode(pBinTree, element.key))
		return (FALSE);
	new = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (new == NULL)
		return (FALSE);
	new->key = element.key;
	parent = pBinTree->pRootNode;
	while (parent)
	{
		if (element.key < parent->key)
		{
			if (parent->pLeftChild == NULL)
				break ;
			parent = parent->pLeftChild;
		}
		else
		{
			if (parent->pRightChild == NULL)
				break ;
			parent = parent->pRightChild;
		}
	}
	if (parent == NULL)
		pBinTree->pRootNode = new;
	else
	{
		if (new->key < parent->key)
			parent->pLeftChild = new;
		else
			parent->pRightChild = new;
	}
	return (TRUE);
}

int	deleteBinSearchTreeNode(BinTree *pBinTree, int key)
{
	BinTreeNode	*temp;
	BinTreeNode	*parent;
	BinTreeNode	*successor;

	if (pBinTree == NULL || pBinTree->pRootNode == NULL)
		return (FALSE);
	temp = searchBinSearchTreeNode(pBinTree, key);
	if (temp == NULL)
		return (FALSE);
	parent = searchBinSearchTreeParentNode(pBinTree, key);
	if (temp->pLeftChild == NULL && temp->pRightChild == NULL)
	{
		if (temp == pBinTree->pRootNode)
			pBinTree->pRootNode = NULL;
		else if (key < parent->key)
			parent->pLeftChild = NULL;
		else
			parent->pRightChild = NULL;
	}
	else if (temp->pLeftChild && temp->pRightChild)
	{
		successor = temp->pLeftChild;
		while (successor->pRightChild)
			successor = successor->pRightChild;
		parent = searchBinSearchTreeParentNode(pBinTree, successor->key);
		temp->key = successor->key;
		if (parent->pLeftChild->key == successor->key)
		{
			parent->pLeftChild = NULL;
			if (successor->pLeftChild)
				parent->pLeftChild = successor->pLeftChild;
		}
		else
		{
			parent->pRightChild = NULL;
			if (successor->pLeftChild)
				parent->pRightChild = successor->pLeftChild;
		}
		temp = successor;
	}
	else
	{
		if (parent == NULL)
			pBinTree->pRootNode = temp->pLeftChild ? temp->pLeftChild : temp->pRightChild;
		else if (key < parent->key)
			parent->pLeftChild = temp->pLeftChild ? temp->pLeftChild : temp->pRightChild;
		else
			parent->pRightChild = temp->pLeftChild ? temp->pLeftChild : temp->pRightChild;
	}
	free(temp);
	return (TRUE);
}

// 검색
BinTreeNode	*searchBinSearchTreeNode(BinTree *pBinTree, int key)
{
	BinTreeNode	*curr;

	if (pBinTree == NULL)
		return (NULL);
	curr = pBinTree->pRootNode;
	while (curr != NULL)
	{
		if (key == curr->key)
			break ;
		else if (key < curr->key)
			curr = curr->pLeftChild;
		else
			curr = curr->pRightChild;
	}
	return (curr);
}

// 부모노드 검색: key:(자식노드)
BinTreeNode	*searchBinSearchTreeParentNode(BinTree *pBinTree, int key)
{
	BinTreeNode	*curr;

	if (pBinTree == NULL)
		return (NULL);
	curr = pBinTree->pRootNode;
	if (key == curr->key)
		return (NULL);
	while (curr != NULL)
	{
		if (curr->pLeftChild && key == curr->pLeftChild->key)
			break ;
		else if (curr->pRightChild && key == curr->pRightChild->key)
			break ;
		if (key < curr->key)
			curr = curr->pLeftChild;
		else if (key > curr->key)
			curr = curr->pRightChild;
	}
	return (curr);
}

// 출력
// V-L-R
void	preorderTraverseBST(BinTreeNode *pNode)
{
	if (pNode == NULL)
		return;
	printf("%d ", pNode->key);
	preorderTraverseBST(pNode->pLeftChild);
	preorderTraverseBST(pNode->pRightChild);
}

// L-V-R
void	inorderTraverseBST(BinTreeNode *pNode)
{
	if (pNode == NULL)
		return;
	inorderTraverseBST(pNode->pLeftChild);
	printf("%d ", pNode->key);
	inorderTraverseBST(pNode->pRightChild);
}

// L-R-V
void	postorderTraverseBST(BinTreeNode *pNode)
{
	if (pNode == NULL)
		return;
	postorderTraverseBST(pNode->pLeftChild);
	postorderTraverseBST(pNode->pRightChild);
	printf("%d ", pNode->key);
}
