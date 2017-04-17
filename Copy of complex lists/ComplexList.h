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

//��һ��ʵ��˼·
template<typename T>
ComplexListNode<T>* Clone1(ComplexListNode<T>* pHead)
{
	/*��һ��������ԭʼ�����ϵ�ÿ����㣬����_next��������*/
	ComplexListNode<T>* cur = pHead;
	//����������ĵ�һ�����
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
	/*�ڶ�������λԭ����ÿ�����_random��ָ���㵽pHead�ľ��룬
	�Ӷ��ҵ����Ƶ��������ÿ�����_randomָ��Ľ��*/
	cur = pHead;
	dest = newHead;
	while (cur)
	{
		//����ԭ�����һ����㣬��head��ʼ�ҵ�_random��ָ��Ľ�㣬������
		ComplexListNode<T>* head = pHead;
		int count = 0;
		while (head)
		{
			count++;//�������ж�֮ǰ������һ�£�Ϊ�˱����_randomָ���һ���������ĳ�ͻ
			//cur->_random == NULLֱ��break��count�͵���1
			if (cur->_random == NULL || cur->_random == head)
			{
				break;
			}
			head = head->_next;
		}

		//�����������һ����㣬��ͷ��ʼ��destCur��count���ҵ�_randomָ��Ľ��
		ComplexListNode<T>* destCur = newHead;
		if (count == 0)
		{
			dest->_random = NULL;
		}
		else
		{
			while (--count)//ǰ���������ģ��������Լ�
			{
				destCur = destCur->_next;
			}
			dest->_random = destCur;
		}
		//cur��dest�Ƕ�Ӧ�Ľ��
		dest = dest->_next;
		cur = cur->_next;
	}
	return newHead;
}

//�ڶ���ʵ��˼·
template<typename T>
ComplexListNode<T>* Clone2(ComplexListNode<T>* pHead)
{
	/*
	��һ��������ԭʼ�����ÿ�����N,������Ӧ��N��,
	���´�����ÿ�����N��������ԭ�Ƚ��N�ĺ���
	*/
	ComplexListNode<T>* cur = pHead;
	while (cur != NULL)
	{
		ComplexListNode<T>* cloned = new ComplexListNode<T>(cur->_value);
		cloned->_next = cur->_next;

		cur->_next = cloned;//���¸��ƵĽ��������ԭʼ���ĺ���  
		cur = cloned->_next;
	}
	/*
	�ڶ������������Ǹ��Ƴ����������ϵĽ���_random
	�ҵ�ÿ������_randomʱ�临�Ӷ�ΪO(1)
	*/
	cur = pHead;
	while (cur != NULL) //��������������ָ��  
	{
		ComplexListNode<T>* cloned = cur->_next;
		if (cur->_random != NULL)
		{
			//�¸��ƽ������ָ�����ԭʼ�������ָ��ָ��Ľ�����һ�����
			cloned->_random = cur->_random->_next;
		}
		cur = cloned->_next;
	}
	/*
	��������������������ֳ�������������λ�õĽ��������������ԭʼ����
	��ż��λ�õĽ�����ӳ������Ǹ��Ƴ�����������
	*/
	cur = pHead;
	ComplexListNode<T>* clonedHead = NULL;
	ComplexListNode<T>* clonedNode = NULL;
	if (cur != NULL) //��ʼ��ͷָ��
	{
		clonedHead = clonedNode = cur->_next;
		cur->_next = clonedNode->_next;//����ԭ����

		cur = cur->_next;//��curָ��ԭ������һ�����
	}//1 2 3 4 5
	while (cur != NULL)
	{
		clonedNode->_next = cur->_next;//��ż��λ�õĽ�������������Ǹ��Ƴ�����������  
		clonedNode = cur->_next;
		cur->_next = clonedNode->_next;//������λ�õĽ��������������ԭʼ����  
		cur = cur->_next;
	}
	return clonedHead;
}