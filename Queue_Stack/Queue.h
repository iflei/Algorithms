#include <stack>
using namespace std;

template <typename T>
class Queue
{
public:
	void Push(const T& x)
	{
		s1.push(x);
	}

	void Pop()
	{
		//���ջ2Ϊ��
		if (s2.size() == 0)
		{
			//��ջ1��ȫ����ջ2
			while (s1.size() > 0)
			{
				T& top = s1.top();
				s2.push(top);
				s1.pop();
			}
		}
		//���ջ2��Ϊ�գ�˵��ջ1ҲΪ��
		if (s2.size() == 0)
			throw new exception("queue is empty!");

		//ջ2��Ϊ�գ�����Ҳ�Ͳ�Ϊ��
		s2.pop();
	}

private:
	stack<T> s1;
	stack<T> s2;
};