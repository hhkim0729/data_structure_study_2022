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

void	deleteBinTree(BinTree *pBinTree)
{
	if (pBinTree == NULL)
	{
		fprintf(stderr, "ERROR: 트리 없음\n");
		return ;
	}
	deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
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
