#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int visit[26] = {0}; //�б���漰��ʿ��
int dep[26][26] = {0};//�洢ʿ��֮����߹�ϵ����ά�����ʾͼ�� 
int in[26] = {0};//��¼ÿ����������
char ans[26]; //��������������
 
void topSort() //�������� 
{
	queue<int> q;
	int n = 0; 
	for(int i = 0; i < 26; ++i)
	{
		if(visit[i] == 1)
		{
			n++;//ͳ������ 
			if(in[i] == 0)	
				q.push(i); //���Ϊ0˵����ĳ����������ߵ� 
		}		
	}
	
	int index = 0; 
	while(!q.empty())
	{
		//������Ԫ�س����� 
		int f = q.front();
		q.pop();
		n--; //��������
		ans[index++] = f + 'A'; //������������ 
		for(int i = 0; i < 26; ++i)
		{
			if(visit[i] && dep[f][i])//f��iǰ��
			{
				in[i]--;
				if(in[i] == 0) //������Ϊ�������
					q.push(i); 
			} 
		} 
	} 
	
	if(n != 0) //������ֵ������������ڳ����е�������˵�����ڻ���������ͨͼ
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
		getchar(); //��ȡ��ÿ�еĻ��з� 
		x = a-'A'; //0-25��Ϊ�±�
		y = b-'A';
		visit[x] = visit[y] = 1; //����Ѵ��ڵĶ���
		if (dep[x][y] == 0) //���û�б��ͼ 
		{
			dep[x][y] = 1; //x��y�� 
        	in[y]++; //y��������� 
		} 
	} 
	topSort();
	return 0;
}