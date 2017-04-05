#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;


struct ListNode
{
	int value;
	ListNode* next;
};
//���������Ԫ��ʱ��Ҫ��ͷָ���ֵ��������Ҫ�ö���ָ��
//pHead��ͷָ���ָ�룬*pHead��ͷָ�룬����ǵ�һ���ڵ��ָ��
void PushBack(ListNode** pHead, int value)
{
	assert(pHead);

	//ListNode* newNode = new ListNode();
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->value = value;
	newNode->next = NULL;

	//ͷָ��Ϊ�գ�������
	if (*pHead == NULL)
		*pHead = newNode;
	else
	{
		//ָ���һ���ڵ�
		ListNode* pNode = *pHead;
		//�����һ���ڵ�
		while (pNode->next)
			pNode = pNode->next;

		pNode->next = newNode;
	}
}


void Remove(ListNode** pHead, const int value)
{
	assert(pHead); //pHead����Ϊ�գ�*pHead����Ϊ��

	ListNode* cur = *pHead;
	ListNode* prev = NULL;
	if (cur == NULL)
		return;

	while (cur)
	{
		if (cur->value == value)
		{
			if (prev == NULL)
				*pHead = (*pHead)->next;
			else
				prev->next = cur->next;
			
			free(cur);
			break;
		}

		prev = cur;
		cur = cur->next;
	}
}

//ֻ���������ö���ָ��
//head��ͷָ��
void PrintListReverse(ListNode* head)
{
	if (head)
	{
		if (head->next)
			PrintListReverse(head->next);

		printf("%d -> ", head->value);
	}
}

//�ǵݹ�
void PrintListReverseNonR(ListNode* head)
{
	stack<ListNode*> pNodes;

	ListNode* pNode = head;
	while (pNode)
	{
		pNodes.push(pNode);
		pNode = pNode->next;
	}

	while (!pNodes.empty())
	{
		pNode = pNodes.top();
		printf("%d -> ", pNode->value);
		pNodes.pop();
	}
}

int main()
{
	ListNode* pList = NULL; //ͷָ����ָ�������ָ��
	PushBack(&pList, 1);
	PushBack(&pList, 2);
	PushBack(&pList, 3);
	PushBack(&pList, 4);
	PushBack(&pList, 5);
	Remove(&pList, 3);
	PrintListReverseNonR(pList);

	system("pause");
	return 0;
}