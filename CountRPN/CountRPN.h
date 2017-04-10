//逆波兰表达式求解

#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

enum Type
{
	OP_SYMBOL,
	OP_NUM,
	ADD,
	SUB,
	MUL,
	DIV
};

struct Cell
{
	Type _type;
	int _value;
};

int CountRPN(Cell* rpn, size_t n)
{
	assert(rpn);
	stack<int> s;
	//遍历整个数组
	for (size_t i = 0; i < n; ++i)
	{
		//如果是操作数
		if (rpn[i]._type == OP_NUM)
		{
			s.push(rpn[i]._value);
		}
		//如果是操作符
		else if (rpn[i]._type == OP_SYMBOL)
		{
			//先取出栈顶两个元素
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();
			//根据操作符进行运算
			switch (rpn[i]._value)
			{
			case ADD:
				s.push(left + right);
				break;
			case SUB:
				s.push(left - right);
				break;
			case MUL:
				s.push(left * right);
				break;
			case DIV:
				s.push(left / right);
				break;
			default:
				assert(false);
			}
		}
		else
			assert(false);
	}
	//返回栈顶元素
	return s.top();
}

void testRPN()
{
	Cell rpn[] = {
		{OP_NUM, 12},
		{OP_NUM, 3},
		{OP_NUM, 4},
		{OP_SYMBOL, ADD},
		{OP_SYMBOL, MUL},
		{OP_NUM, 6},
		{OP_SYMBOL, SUB},
		{OP_NUM, 8},
		{OP_NUM, 2},
		{OP_SYMBOL, DIV},
		{OP_SYMBOL, ADD}
	};

	int ret = CountRPN(rpn, sizeof(rpn) / sizeof(rpn[0]));
	cout << "ret = " << ret << endl;
}