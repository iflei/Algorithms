#include <vector>
#include <stack>
using namespace std;

bool IsPopOrder(vector<int> pushOrder, vector<int> popOrder)
{
	if (pushOrder.size() != popOrder.size() || pushOrder.size() <= 0)
		return false;

	int len = pushOrder.size();
	int indexPopOrder = 0;
	stack<int> s;
	for (int i = 0; i < len && indexPopOrder < len; ++i)
	{
		//ģ����ջ˳��
		s.push(pushOrder[i]);
		//���ջ��Ԫ�ص��ڳ�ջ˳���е�Ԫ�أ�pop��ջ��Ԫ�ز�ƫ�Ƴ�ջ˳����һ��Ԫ��
		//���ջ�������ڳ�ջ˳���е�Ԫ����pop
		while (!s.empty() && s.top() == popOrder[indexPopOrder])
		{
			s.pop();
			indexPopOrder++;
		}
	}
	//����ѭ�����������������
	//1. i == len ˵����Ԫ�ز����ϳ�ջ˳��û��ִ���ڲ�ѭ����++i
	//2. indexPopOrder == len �� s.empty() ˵����ջ˳���Ѿ��������ˣ���ôջҲ��Ӧ�Ŀ���
	if (s.empty())  //if (indexPopOrder == len)
	{
		return true;
	}
	return false;
}