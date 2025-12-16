#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int BTNodeDataType;

typedef struct BinTreeNode
{
	BTNodeDataType val;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
}BTNode;

BTNode* BuyNode(BTNodeDataType x)
{
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
	if (tmp == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	tmp->val = x;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	//       1
	//    2      4
	//  3     5     6
	//          7
	return node1;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%d ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;

	int leftSize = TreeLeafSize(root->left);
	int rightSize = TreeLeafSize(root->right);

	return leftSize + rightSize;
}

int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return TreeSize(root->left)+ TreeSize(root->right)+1;
}

int main()
{
	BTNode* root = CreatBinaryTree();
	printf("PreOrder:>  ");
	PreOrder(root);
	puts(" ");

	printf("InOrder:>   ");
	InOrder(root);
	puts(" ");

	printf("PostOrder:> ");
	PostOrder(root);
	puts(" ");

	printf("TreeHeight:> ");
	printf("%d",TreeHeight(root));
	puts(" ");

	printf("TreeLeafSize:> ");
	printf("%d", TreeLeafSize(root));
	puts(" ");

	printf("TreeSize:> ");
	printf("%d", TreeSize(root));
	puts(" ");

	return 0;
}
