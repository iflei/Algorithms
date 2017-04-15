#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

struct Pos
{
	int _row;
	int _col;
	Pos(int row, int col)
		:_row(row)
		, _col(col)
	{}
};

void GetMaze(int* maze, int n) //传进来一个n*n二维数组
{
	//打开文件
	FILE* fout = fopen("MazeMap.txt", "r");
	//断言指针
	assert(fout);
	//读取n行
	for (int i = 0; i < n; ++i)
	{
		//读取每列的n的数字字符
		int j = 0;
		while (j < n)
		{
			//读取一个字符
			char c = fgetc(fout);
			if (c == '0' || c == '1')
			{
				maze[i * n + j] = c - '0';
				++j;
			}
		}
	}
	fclose(fout);
}

void PrintMaze(int* maze, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%2d ", maze[i * n + j]);
		}
		cout << endl;
	}
	cout << endl;
}

bool CheckAccess(int* maze, int n, const Pos& next)
{
	if ((next._row < n && next._col >= 0)
		&& (next._col < n && next._col >= 0)
		&& (maze[next._row*n + next._col] == 0))
	{
		return true;
	}
	else
		return false;
}
//重载CheckAccess
bool CheckAccess(int* maze, int n, const Pos& cur, const Pos& next)
{
	//坐标不合法或者是墙
	if (next._row < 0 || next._row >= n || next._col < 0 || next._col >= n
		|| maze[next._row * n + next._col] == 1)
	{
		return false;
	}
	//没有走过并且可以走通
	else if (maze[next._row * n + next._col] == 0)
	{
		return true;
	}
	//坐标合法但被曾经的探测标记过
	else
	{
		return maze[next._row * n + next._col] > maze[cur._row * n + cur._col];
	}
		
}

//栈求解迷宫问题（非递归）
bool MazePath(int* maze, const int n, const Pos& entry, stack<Pos>& path)
{
	//断言入口坐标是否合法
	assert(entry._col < n && entry._col >= 0 && entry._col < n && entry._col >= 0);
	//入口通路标记一下
	maze[entry._row * n + entry._col] = 2;
	path.push(entry); //能走通的坐标压栈

	//当栈为空时，回到入口，迷宫没有出口
	while (!path.empty())
	{
		//用cur记录从哪个位置开始探测
		Pos cur = path.top();
		//出口在最后一行
		if (cur._row == n - 1)
		{
			return true;
		}

		//用next记录下一步探测哪个位置
		Pos next = cur;
		//测试当前位置上方是否通路
		next._row -= 1;
		if (CheckAccess((int*)maze, n, next))
		{	
			//给通路位置标记空格
			maze[next._row * n + next._col] = 2;
			path.push(next);
			continue;
		}

		//探测右方
		next = cur;
		next._col += 1;
		if (CheckAccess((int*)maze, n, next))
		{
			maze[next._row * n + next._col] = 2;
			path.push(next);
			continue;
		}

		//探测下方
		next = cur;
		next._row += 1;
		if (CheckAccess((int*)maze, n, next))
		{
			maze[next._row * n + next._col] = 2;
			path.push(next);
			continue;
		}

		//探测左方
		next = cur;
		next._col -= 1;
		if (CheckAccess((int*)maze, n, next))
		{
			maze[next._row * n + next._col] = 2;
			path.push(next);
			continue;
		}

		//四个方向都不通,把这个位置标记为不通
		next = cur;
		maze[next._row * n + next._col] = 3;
		//把当前位置pop出栈
		path.pop();
	}
	return false;
}

//递归求解迷宫问题最优解
void MazePathR(int* maze, const int n, const Pos& entry, stack<Pos>& path, stack<Pos>& shortPath)
{
	//断言入口坐标是否合法
	assert(entry._col < n && entry._col >= 0 && entry._col < n && entry._col >= 0);
	//用cur记录从哪个位置开始探测
	path.push(entry);
	Pos cur = path.top();
	//出口在最后一行,递归结束条件
	if (cur._row == n - 1)
	{
		//找到出口，显示下迷宫
		PrintMaze((int*)maze, n);
		//更新当前最短路径
		if (shortPath.empty() || path.size() < shortPath.size())
		{
			shortPath = path;
		}
	}
	
	//用next记录下一步探测哪个位置
	Pos next = cur;
	//测试当前位置上方是否通路
	next._row -= 1;
	if (CheckAccess((int*)maze, n, cur, next))
	{
		//下一步的位置比当前位置加1
		maze[next._row * n + next._col] = maze[cur._row * n + cur._col] + 1;
		//继续以next为entry解决迷宫问题
		MazePathR((int*)maze, n, next, path, shortPath); //这里绝对不能return
	}

	//探测右方
	next = cur;
	next._col += 1;
	if (CheckAccess((int*)maze, n, cur, next))
	{
		//下一步的位置比当前位置加1
		maze[next._row * n + next._col] = maze[cur._row * n + cur._col] + 1;
		//继续以next为entry解决迷宫问题
		MazePathR((int*)maze, n, next, path, shortPath);
	}

	//探测下方
	next = cur;
	next._row += 1;
	if (CheckAccess((int*)maze, n, cur, next))
	{
		//下一步的位置比当前位置加1
		maze[next._row * n + next._col] = maze[cur._row * n + cur._col] + 1;
		//继续以next为entry解决迷宫问题
		MazePathR((int*)maze, n, next, path, shortPath);
	}

	//探测左方
	next = cur;
	next._col -= 1;
	if (CheckAccess((int*)maze, n, cur, next))
	{
		//下一步的位置比当前位置加1
		maze[next._row * n + next._col] = maze[cur._row * n + cur._col] + 1;
		//继续以next为entry解决迷宫问题
		MazePathR((int*)maze, n, next, path, shortPath);
	}
	
	path.pop();
}

void testMazeR()
{
	const int N = 10;
	int maze[N][N];
	GetMaze((int*)maze, N);
	PrintMaze((int*)maze, N);
	
	Pos entry(2, 0);
	stack<Pos> path;
	stack<Pos> shortPath;
	//入口通路标记数字
	maze[2][0] = 1;
	MazePathR((int*)maze, N, entry, path, shortPath);
	cout << "最短路径为：" << shortPath.size() << endl;

}

void testMaze()
{
	const int N = 10;
	int maze[N][N];
	GetMaze((int*)maze, N);
	PrintMaze((int*)maze, N);

	Pos entry(2, 0);
	stack<Pos> path;
	bool ret = MazePath((int*)maze, N, entry, path);
	cout << "是否找到出口？" << ret << endl;
	PrintMaze((int*)maze, N);
}

int main()
{
	//testMaze();
	testMazeR();
	return 0;
}