#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stack
{
public:
	void Push(const T& x)
	{
		//1. 如果q1与q2都为空，那么往q1中插入元素
		if (q1.empty() && q2.empty())
			q1.push(x);
		//2. 如果q1不为空（那么q2肯定为空），那么往q1中插入元素（说明q1连续push操作）
		else if (!q1.empty())
			q1.push(x);
		//3. 如果q1为空，q2不为空，那么往q2中插入元素（q1为空说明进行了一次pop操作）
		else
			q2.push(x);
	}
	//pop操作：把其中不为空的队列里的前面的元素pop并push到另一个队列，把最后一个元素pop出去
	T Pop()
	{
		if (!q1.empty())
		{
			while (q1.size() - 1) //q.size()会跟着pop减
			{
				q2.push(q1.front());
				q1.pop();
			}
			
			T top = q1.front();
			q1.pop();
			return top;
		}
		else
		{
			while (q2.size() - 1) 
			{
				q1.push(q2.front());
				q2.pop();
			}

			T top = q2.front();
			q2.pop();
			return top;
		}
	}
private:
	//其中的两个队列有两种状态：
	//1、两个队列都为空
	//2、其中一个队列为空，另一个不为空
	queue<T> q1;
	queue<T> q2;
};