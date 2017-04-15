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

void GetMaze(int* maze, int n) //������һ��n*n��ά����
{
	//���ļ�
	FILE* fout = fopen("MazeMap.txt", "r");
	//����ָ��
	assert(fout);
	//��ȡn��
	for (int i = 0; i < n; ++i)
	{
		//��ȡÿ�е�n�������ַ�
		int j = 0;
		while (j < n)
		{
			//��ȡһ���ַ�
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
//����CheckAccess
bool CheckAccess(int* maze, int n, const Pos& cur, const Pos& next)
{
	//���겻�Ϸ�������ǽ
	if (next._row < 0 || next._row >= n || next._col < 0 || next._col >= n
		|| maze[next._row * n + next._col] == 1)
	{
		return false;
	}
	//û���߹����ҿ�����ͨ
	else if (maze[next._row * n + next._col] == 0)
	{
		return true;
	}
	//����Ϸ�����������̽���ǹ�
	else
	{
		return maze[next._row * n + next._col] > maze[cur._row * n + cur._col];
	}
		
}

//ջ����Թ����⣨�ǵݹ飩
bool MazePath(int* maze, const int n, const Pos& entry, stack<Pos>& path)
{
	//������������Ƿ�Ϸ�
	assert(entry._col < n && entry._col >= 0 && entry._col < n && entry._col >= 0);
	//���ͨ·���һ��
	maze[entry._row * n + entry._col] = 2;
	path.push(entry); //����ͨ������ѹջ

	//��ջΪ��ʱ���ص���ڣ��Թ�û�г���
	while (!path.empty())
	{
		//��cur��¼���ĸ�λ�ÿ�ʼ̽��
		Pos cur = path.top();
		//���������һ��
		if (cur._row == n - 1)
		{
			return true;
		}

		//��next��¼��һ��̽���ĸ�λ��
		Pos next = cur;
		//���Ե�ǰλ���Ϸ��Ƿ�ͨ·
		next._row -= 1;
		if (CheckAccess((int*)maze, n, next))
		{	
			//��ͨ·λ�ñ�ǿո�
			maze[next._row * n + next._col] = 2;
			path.push(next);
			continue;
		}

		//̽���ҷ�
		next = cur;
		next._col += 1;
		if (CheckAccess((int*)maze, n, next))
		{
			maze[next._row * n + next._col] = 2;
			path.push(next);
			continue;
		}

		//̽���·�
		next = cur;
		next._row += 1;
		if (CheckAccess((int*)maze, n, next))
		{
			maze[next._row * n + next._col] = 2;
			path.push(next);
			continue;
		}

		//̽����
		next = cur;
		next._col -= 1;
		if (CheckAccess((int*)maze, n, next))
		{
			maze[next._row * n + next._col] = 2;
			path.push(next);
			continue;
		}

		//�ĸ����򶼲�ͨ,�����λ�ñ��Ϊ��ͨ
		next = cur;
		maze[next._row * n + next._col] = 3;
		//�ѵ�ǰλ��pop��ջ
		path.pop();
	}
	return false;
}

//�ݹ�����Թ��������Ž�
void MazePathR(int* maze, const int n, const Pos& entry, stack<Pos>& path, stack<Pos>& shortPath)
{
	//������������Ƿ�Ϸ�
	assert(entry._col < n && entry._col >= 0 && entry._col < n && entry._col >= 0);
	//��cur��¼���ĸ�λ�ÿ�ʼ̽��
	path.push(entry);
	Pos cur = path.top();
	//���������һ��,�ݹ��������
	if (cur._row == n - 1)
	{
		//�ҵ����ڣ���ʾ���Թ�
		PrintMaze((int*)maze, n);
		//���µ�ǰ���·��
		if (shortPath.empty() || path.size() < shortPath.size())
		{
			shortPath = path;
		}
	}
	
	//��next��¼��һ��̽���ĸ�λ��
	Pos next = cur;
	//���Ե�ǰλ���Ϸ��Ƿ�ͨ·
	next._row -= 1;
	if (CheckAccess((int*)maze, n, cur, next))
	{
		//��һ����λ�ñȵ�ǰλ�ü�1
		maze[next._row * n + next._col] = maze[cur._row * n + cur._col] + 1;
		//������nextΪentry����Թ�����
		MazePathR((int*)maze, n, next, path, shortPath); //������Բ���return
	}

	//̽���ҷ�
	next = cur;
	next._col += 1;
	if (CheckAccess((int*)maze, n, cur, next))
	{
		//��һ����λ�ñȵ�ǰλ�ü�1
		maze[next._row * n + next._col] = maze[cur._row * n + cur._col] + 1;
		//������nextΪentry����Թ�����
		MazePathR((int*)maze, n, next, path, shortPath);
	}

	//̽���·�
	next = cur;
	next._row += 1;
	if (CheckAccess((int*)maze, n, cur, next))
	{
		//��һ����λ�ñȵ�ǰλ�ü�1
		maze[next._row * n + next._col] = maze[cur._row * n + cur._col] + 1;
		//������nextΪentry����Թ�����
		MazePathR((int*)maze, n, next, path, shortPath);
	}

	//̽����
	next = cur;
	next._col -= 1;
	if (CheckAccess((int*)maze, n, cur, next))
	{
		//��һ����λ�ñȵ�ǰλ�ü�1
		maze[next._row * n + next._col] = maze[cur._row * n + cur._col] + 1;
		//������nextΪentry����Թ�����
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
	//���ͨ·�������
	maze[2][0] = 1;
	MazePathR((int*)maze, N, entry, path, shortPath);
	cout << "���·��Ϊ��" << shortPath.size() << endl;

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
	cout << "�Ƿ��ҵ����ڣ�" << ret << endl;
	PrintMaze((int*)maze, N);
}

int main()
{
	//testMaze();
	testMazeR();
	return 0;
}