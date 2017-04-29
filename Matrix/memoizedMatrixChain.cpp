#include <iostream>
using namespace std;

//全局的二维数组避免二维数组传参的麻烦 
int m[1000][1000]; //m数组保存最优值 
int p[1000]; //输入值 

int lookupChain(int i, int j)
{
	if(m[i][j] > 0) //该子问题已经解决过 
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
			m[i][j] = 0; //初始化为0表示该子问题还未计算 
	
	return lookupChain(1, n); //该方法只解需要求解的子问题 
}

int main()
{
	//输入的第一行包含一个整数n，表示矩阵的个数
	int n;
	cin >> n;
	//第二行包含n+1个数，表示给定的矩阵的规模。 	
	for(int i= 0; i <= n; ++i)
		cin >> p[i]; 
	
	memoizedMatrixChain(n);
	cout << m[1][n] << endl; 
	return 0;
}