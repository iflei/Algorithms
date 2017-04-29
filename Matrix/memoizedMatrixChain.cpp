#include <iostream>
using namespace std;

//ȫ�ֵĶ�ά��������ά���鴫�ε��鷳 
int m[1000][1000]; //m���鱣������ֵ 
int p[1000]; //����ֵ 

int lookupChain(int i, int j)
{
	if(m[i][j] > 0) //���������Ѿ������ 
		return m[i][j];
	
	if(i == j) 
		return 0;
	
	int u = lookupChain(i+1, j) + p[i-1]*p[i]*p[j];
	
	for(int k = i+1; k < j; ++k)
	{
		int tmp = lookupChain(i, k) + lookupChain(k+1, j) + p[i-1]*p[k]*p[j];
		if(tmp < u)
		{
			u = tmp;
		}
	}
	
	m[i][j] = u;
	return u;
} 

int memoizedMatrixChain(int n)
{
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; ++j)
			m[i][j] = 0; //��ʼ��Ϊ0��ʾ�������⻹δ���� 
	
	return lookupChain(1, n); //�÷���ֻ����Ҫ���������� 
}

int main()
{
	//����ĵ�һ�а���һ������n����ʾ����ĸ���
	int n;
	cin >> n;
	//�ڶ��а���n+1��������ʾ�����ľ���Ĺ�ģ�� 	
	for(int i= 0; i <= n; ++i)
		cin >> p[i]; 
	
	memoizedMatrixChain(n);
	cout << m[1][n] << endl; 
	return 0;
}