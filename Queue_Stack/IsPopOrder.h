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
		//模拟入栈顺序
		s.push(pushOrder[i]);
		//如果栈顶元素等于出栈顺序中的元素，pop出栈顶元素并偏移出栈顺序到下一个元素
		//如果栈顶还等于出栈顺序中的元素再pop
		while (!s.empty() && s.top() == popOrder[indexPopOrder])
		{
			s.pop();
			indexPopOrder++;
		}
	}
	//上面循环结束有两种情况：
	//1. i == len 说明有元素不符合出栈顺序，没有执行内层循环而++i
	//2. indexPopOrder == len 或 s.empty() 说明出栈顺序已经遍历完了，那么栈也对应的空了
	if (s.empty())  //if (indexPopOrder == len)
	{
		return true;
	}
	return false;
}