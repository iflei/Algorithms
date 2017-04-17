#include <iostream>
using namespace std;

void test()
{
	//构建复杂链表
	//new新结点
	ComplexListNode<int>* Node1 = new ComplexListNode<int>(1);
	ComplexListNode<int>* Node2 = new ComplexListNode<int>(2);
	ComplexListNode<int>* Node3 = new ComplexListNode<int>(3);
	ComplexListNode<int>* Node4 = new ComplexListNode<int>(4);
	//链接各个结点
	ComplexListNode<int>* Head = Node1;
	Node1->_next = Node2;
	Node2->_next = Node3;
	Node3->_next = Node4;
	//指定_sibling指向
	Node1->_random = Node3;
	Node2->_random = Node1;
	Node3->_random = NULL;
	Node4->_random = Node2;
	//复制复杂链表
	ComplexListNode<int>* newHead = Clone2(Head);
}

int main()
{
	test();
	return 0;
}