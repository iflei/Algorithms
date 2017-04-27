#include <iostream>
#include <stdio.h>
using namespace std;

//合并的费用为两堆石子的总数
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
	//一堆石子合并花费为0 
	for(int i = 0; i < n; ++i)
		m[i*n + i] = 0; //m[i][i]
	
	//相邻两堆石子合并		
	for(int i = 0; i < n - 1; ++i)
		m[i*n + i+1] = a[i] + a[i+1]; //m[i][i+1]
	//0 1
	//控制合并的区间大小 
	for(int r = 2; r < n; ++r)
	{
		//依次计算合并堆数的花费 m[i][i+1]， m[i][i+2]， m[i][i+3] 
		for(int i = 0; i < n - r; ++i)
		{
			int j = i + r; //控制几堆合并 
			//m[i][j] = m[i][i] + m[i+1][j] + cost(a, i, j); 
			m[i*n + j] = m[i*n + i]  + m[(i+1)*n + j] + cost(a, i, j);  //cost是两大堆石子合并的花费 
			
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
	int n; //石子的堆数
	cin >> n;
	
	int a[n]; //每堆石子的大小
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	int m[n][n];	
	MergeCost(a, n, (int*)m);
	cout<< m[0][n-1] << endl;
	return 0; 
} 