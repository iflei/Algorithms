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
		//如果栈2为空
		if (s2.size() == 0)
		{
			//把栈1的全倒入栈2
			while (s1.size() > 0)
			{
				T& top = s1.top();
				s2.push(top);
				s1.pop();
			}
		}
		//如果栈2还为空，说明栈1也为空
		if (s2.size() == 0)
			throw new exception("queue is empty!");

		//栈2不为空，队列也就不为空
		s2.pop();
	}

private:
	stack<T> s1;
	stack<T> s2;
};