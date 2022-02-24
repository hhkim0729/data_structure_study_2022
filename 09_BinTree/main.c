#include "bintree.h"

void	test(void)
{
	BinTree		*pBinTree;
	BinTreeNode	node;
	BinTreeNode	*pLeft;
	BinTreeNode	*pRight;

	node.data = 'A';
	pBinTree = makeBinTree(node);

	node.data = 'B';
	pLeft = insertLeftChildNodeBT(pBinTree->pRootNode, node);
	node.data = 'E';
	pRight = insertRightChildNodeBT(pLeft, node);
	node.data = 'D';
	pLeft = insertLeftChildNodeBT(pLeft, node);
	node.data = 'H';
	insertLeftChildNodeBT(pLeft, node);
	node.data = 'I';
	insertRightChildNodeBT(pLeft, node);
	node.data = 'J';
	insertLeftChildNodeBT(pRight, node);

	node.data = 'C';
	pRight = insertRightChildNodeBT(pBinTree->pRootNode, node);
	node.data = 'F';
	pLeft = insertLeftChildNodeBT(pRight, node);
	node.data = 'G';
	pRight = insertRightChildNodeBT(pRight, node);
	node.data = 'K';
	insertRightChildNodeBT(pLeft, node);
	node.data = 'L';
	insertLeftChildNodeBT(pRight, node);
	node.data = 'M';
	insertRightChildNodeBT(pRight, node);

	printf("전위: ");
	preorderTraverse(pBinTree->pRootNode);
	printf("\n중위: ");
	inorderTraverse(pBinTree->pRootNode);
	printf("\n후위: ");
	postorderTraverse(pBinTree->pRootNode);
	printf("\n");
	deleteBinTree(&pBinTree);
}

void	test_bst(void)
{
	BinTree		*pBinTree;
	BinTreeNode	element;

	pBinTree = createBinSearchTree();

	element.key = 30;
	insertBinSearchTreeNode(pBinTree, element);
	element.key = 20;
	insertBinSearchTreeNode(pBinTree, element);
	element.key = 40;
	insertBinSearchTreeNode(pBinTree, element);
	element.key = 10;
	insertBinSearchTreeNode(pBinTree, element);
	element.key = 24;
	insertBinSearchTreeNode(pBinTree, element);
	element.key = 34;
	insertBinSearchTreeNode(pBinTree, element);
	element.key = 46;
	insertBinSearchTreeNode(pBinTree, element);
	element.key = 6;
	insertBinSearchTreeNode(pBinTree, element);
	element.key = 14;
	insertBinSearchTreeNode(pBinTree, element);
	element.key = 22;
	insertBinSearchTreeNode(pBinTree, element);

	inorderTraverseBST(pBinTree->pRootNode);
	printf("\n");
	// 없는 경우
	// deleteBinSearchTreeNode(pBinTree, 14);
	// 1개인 경우
	// deleteBinSearchTreeNode(pBinTree, 24);
	// 2개인 경우
	deleteBinSearchTreeNode(pBinTree, 40);
	inorderTraverseBST(pBinTree->pRootNode);

	deleteBinTree(&pBinTree);
}

int	main(void)
{
	// test();
	test_bst();
	// system("leaks bintree");
	return (0);
}
