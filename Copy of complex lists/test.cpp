#include <iostream>
using namespace std;

void test()
{
	//������������
	//new�½��
	ComplexListNode<int>* Node1 = new ComplexListNode<int>(1);
	ComplexListNode<int>* Node2 = new ComplexListNode<int>(2);
	ComplexListNode<int>* Node3 = new ComplexListNode<int>(3);
	ComplexListNode<int>* Node4 = new ComplexListNode<int>(4);
	//���Ӹ������
	ComplexListNode<int>* Head = Node1;
	Node1->_next = Node2;
	Node2->_next = Node3;
	Node3->_next = Node4;
	//ָ��_siblingָ��
	Node1->_random = Node3;
	Node2->_random = Node1;
	Node3->_random = NULL;
	Node4->_random = Node2;
	//���Ƹ�������
	ComplexListNode<int>* newHead = Clone2(Head);
}

int main()
{
	test();
	return 0;
}