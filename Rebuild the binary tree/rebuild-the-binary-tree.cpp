#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;

typedef struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
}BinaryTreeNode;

BinaryTreeNode* ConstructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder)
{
	//ǰ���һ��ֵ�Ǹ��ڵ�
	int rootValue = startPreOrder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->_value = rootValue;
	root->_left = root->_right = NULL;
	//ֻ��һ��Ԫ��
	if (startPreOrder == endPreOrder)
	{
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
			return root;
		else
			throw exception("Invalid input!");
	}

	//�����������Ҹ��ڵ�ֵ
	int* rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
		++rootInOrder;
	//˵��û�ҵ�
	if (rootInOrder > endInOrder)
		throw exception("Invalid input!");

	//������
	int leftSize = rootInOrder - startInOrder;
	int* leftPreOrderEnd = startPreOrder + leftSize;

	//��startPreOrder+1, leftPreOrderEnd, startInOrder, rootInOrder-1)
	if (leftSize > 0)
	{
		//����������
		root->_left = ConstructCore(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	}

	//�������ڵ���С���������ڵ�����˵��������Ҳ����
	if (leftSize < endPreOrder - startPreOrder)
	{
		root->_right = ConstructCore(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);
	}

	return root;
}

BinaryTreeNode* Construct(int* PreOrder, int* InOrder, int size)
{
	assert(PreOrder && InOrder && size > 0);

	return ConstructCore(PreOrder, PreOrder + size - 1, InOrder, InOrder + size - 1);
}

int main()
{
	int PreOrder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int InOrder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	BinaryTreeNode* root = Construct(PreOrder, InOrder, sizeof(PreOrder) / sizeof(PreOrder[0]));

	system("pause");
	return 0;
}