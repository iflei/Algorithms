#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int visit[26] = {0}; //判标记涉及的士兵
int dep[26][26] = {0};//存储士兵之间身高关系（二维数组表示图） 
int in[26] = {0};//记录每个顶点的入度
char ans[26]; //保存最终排序结果
 
void topSort() //拓扑排序 
{
	queue<int> q;
	int n = 0; 
	for(int i = 0; i < 26; ++i)
	{
		if(visit[i] == 1)
		{
			n++;//统计人数 
			if(in[i] == 0)	
				q.push(i); //入度为0说明是某个序列中最高的 
		}		
	}
	
	int index = 0; 
	while(!q.empty())
	{
		//队列首元素出队列 
		int f = q.front();
		q.pop();
		n--; //人数减少
		ans[index++] = f + 'A'; //加入结果数组中 
		for(int i = 0; i < 26; ++i)
		{
			if(visit[i] && dep[f][i])//f在i前面
			{
				in[i]--;
				if(in[i] == 0) //如果入度为零入队列
					q.push(i); 
			} 
		} 
	} 
	
	if(n != 0) //如果出现的总人数不等于出队列的人数，说明存在环或者子连通图
	{
		cout << "No Answer!";
	}
	else
    {
        for (int i=0; i < index; ++i)
        {
            cout << ans[i];
        }
    }
}
 
int main()
{
	char a, op, b;
	int x, y;
	while(scanf("%c%c%c", &a, &op, &b) !=EOF)
	{
		getchar(); //读取掉每行的换行符 
		x = a-'A'; //0-25作为下标
		y = b-'A';
		visit[x] = visit[y] = 1; //标记已存在的顶点
		if (dep[x][y] == 0) //如果没有标记图 
		{
			dep[x][y] = 1; //x比y高 
        	in[y]++; //y的入度增加 
		} 
	} 
	topSort();
	return 0;
}