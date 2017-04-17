#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct ComplexListNode
{
public:
	ComplexListNode(const T& e)
		:_value(e)
		,_next(NULL)
		,_random(NULL)
	{}
public:
	T _value;
	ComplexListNode<T>* _next;
	ComplexListNode<T>* _random;
};

//第一种实现思路
template<typename T>
ComplexListNode<T>* Clone1(ComplexListNode<T>* pHead)
{
	/*第一步：复制原始链表上的每个结点，并用_next链接起来*/
	ComplexListNode<T>* cur = pHead;
	//创建新链表的第一个结点
	ComplexListNode<T>* newHead = new ComplexListNode<T>(cur->_value);
	cur = cur->_next;

	ComplexListNode<T>* dest = newHead;
	while (cur)
	{
		ComplexListNode<T>* cloned = new ComplexListNode<T>(cur->_value);
		dest->_next = cloned;
		dest = dest->_next;
		cur = cur->_next;
	}	
	/*第二步：定位原链表每个结点_random所指向结点到pHead的距离，
	从而找到复制的新链表的每个结点_random指向的结点*/
	cur = pHead;
	dest = newHead;
	while (cur)
	{
		//对于原链表的一个结点，从head开始找到_random所指向的结点，并计数
		ComplexListNode<T>* head = pHead;
		int count = 0;
		while (head)
		{
			count++;//这里在判断之前就自增一下，为了便面和_random指向第一个结点计数的冲突
			//cur->_random == NULL直接break，count就等于1
			if (cur->_random == NULL || cur->_random == head)
			{
				break;
			}
			head = head->_next;
		}

		//对于新链表的一个结点，从头开始，destCur走count步找到_random指向的结点
		ComplexListNode<T>* destCur = newHead;
		if (count == 0)
		{
			dest->_random = NULL;
		}
		else
		{
			while (--count)//前面先自增的，这里先自减
			{
				destCur = destCur->_next;
			}
			dest->_random = destCur;
		}
		//cur和dest是对应的结点
		dest = dest->_next;
		cur = cur->_next;
	}
	return newHead;
}

//第二种实现思路
template<typename T>
ComplexListNode<T>* Clone2(ComplexListNode<T>* pHead)
{
	/*
	第一步：根据原始链表的每个结点N,创建对应的N’,
	把新创建的每个结点N’链接在原先结点N的后面
	*/
	ComplexListNode<T>* cur = pHead;
	while (cur != NULL)
	{
		ComplexListNode<T>* cloned = new ComplexListNode<T>(cur->_value);
		cloned->_next = cur->_next;

		cur->_next = cloned;//将新复制的结点链接在原始结点的后面  
		cur = cloned->_next;
	}
	/*
	第二步：设置我们复制出来的链表上的结点的_random
	找到每个结点的_random时间复杂度为O(1)
	*/
	cur = pHead;
	while (cur != NULL) //遍历链表更新随机指针  
	{
		ComplexListNode<T>* cloned = cur->_next;
		if (cur->_random != NULL)
		{
			//新复制结点的随机指针就是原始结点的随机指针指向的结点的下一个结点
			cloned->_random = cur->_random->_next;
		}
		cur = cloned->_next;
	}
	/*
	第三步：把这个长链表拆分成两个：把奇数位置的结点链接起来就是原始链表，
	把偶数位置的结点链接出来就是复制出来的新链表。
	*/
	cur = pHead;
	ComplexListNode<T>* clonedHead = NULL;
	ComplexListNode<T>* clonedNode = NULL;
	if (cur != NULL) //初始化头指针
	{
		clonedHead = clonedNode = cur->_next;
		cur->_next = clonedNode->_next;//链接原链表

		cur = cur->_next;//让cur指向原链表下一个结点
	}//1 2 3 4 5
	while (cur != NULL)
	{
		clonedNode->_next = cur->_next;//把偶数位置的结点链接起来就是复制出来的新链表  
		clonedNode = cur->_next;
		cur->_next = clonedNode->_next;//把奇数位置的结点链接起来就是原始链表  
		cur = cur->_next;
	}
	return clonedHead;
}