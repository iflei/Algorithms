#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;


struct ListNode
{
	int value;
	ListNode* next;
};
//空链表插入元素时需要改头指针的值，所以需要用二级指针
//pHead是头指针的指针，*pHead是头指针，存的是第一个节点的指针
void PushBack(ListNode** pHead, int value)
{
	assert(pHead);

	//ListNode* newNode = new ListNode();
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->value = value;
	newNode->next = NULL;

	//头指针为空，空链表
	if (*pHead == NULL)
		*pHead = newNode;
	else
	{
		//指向第一个节点
		ListNode* pNode = *pHead;
		//找最后一个节点
		while (pNode->next)
			pNode = pNode->next;

		pNode->next = newNode;
	}
}


void Remove(ListNode** pHead, const int value)
{
	assert(pHead); //pHead不能为空，*pHead可以为空

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

//只读操作不用二级指针
//head是头指针
void PrintListReverse(ListNode* head)
{
	if (head)
	{
		if (head->next)
			PrintListReverse(head->next);

		printf("%d -> ", head->value);
	}
}

//非递归
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
	ListNode* pList = NULL; //头指针是指向链表的指针
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