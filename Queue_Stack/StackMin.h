#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class myStack
{
public:
	void Push(const T& x)
	{
		//s.empty()˵������ջΪ��
		if (s.empty() || x <= m.top()) 
		{
			s.push(x);
			m.push(x);
		}
		else
			s.push(x);
	}

	void Pop()
	{
		if (s.top() == m.top())
		{
			s.pop();
			m.pop();
		}
		else
			s.pop();
	}

	T Min()
	{
		return m.top();
	}
private:
	stack<T> s; //������
	stack<T> m; //���浱ǰ��СԪ��
};