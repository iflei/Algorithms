#include <iostream>
#include <stdio.h>
using namespace std;

//�ϲ��ķ���Ϊ����ʯ�ӵ�����
int cost(int* a, int i, int j)
{
	int sum = 0;
	for(int k = i; k <= j; ++k)
	{
		sum += a[k];
	}
	return sum;
}

void MergeCost(int* a, int n, int* m)
{
	//һ��ʯ�Ӻϲ�����Ϊ0 
	for(int i = 0; i < n; ++i)
		m[i*n + i] = 0; //m[i][i]
	
	//��������ʯ�Ӻϲ�		
	for(int i = 0; i < n - 1; ++i)
		m[i*n + i+1] = a[i] + a[i+1]; //m[i][i+1]
	//0 1
	//���ƺϲ��������С 
	for(int r = 2; r < n; ++r)
	{
		//���μ���ϲ������Ļ��� m[i][i+1]�� m[i][i+2]�� m[i][i+3] 
		for(int i = 0; i < n - r; ++i)
		{
			int j = i + r; //���Ƽ��Ѻϲ� 
			//m[i][j] = m[i][i] + m[i+1][j] + cost(a, i, j); 
			m[i*n + j] = m[i*n + i]  + m[(i+1)*n + j] + cost(a, i, j);  //cost�������ʯ�Ӻϲ��Ļ��� 
			
			for(int k = i + 1; k < j; ++k)
			{
				//int tmp = m[i][k] + m[k+1][j] + cost(a, i, j);
				int tmp = m[i*n + k] + m[(k+1)*n + j] + cost(a, i, j);
				if(tmp < m[i*n + j])
					m[i*n + j] = tmp; 
			}
		}
	}
}

int main()
{
	int n; //ʯ�ӵĶ���
	cin >> n;
	
	int a[n]; //ÿ��ʯ�ӵĴ�С
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	int m[n][n];	
	MergeCost(a, n, (int*)m);
	cout<< m[0][n-1] << endl;
	return 0; 
} 