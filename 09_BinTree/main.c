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
	deleteBinTree(pBinTree);
}

int	main(void)
{
	test();
	// system("leaks bintree");
	return (0);
}
