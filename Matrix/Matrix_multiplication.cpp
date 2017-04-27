//矩阵完全加括号问题的最小数乘次数
#include <iostream>
using namespace std;
//第一个矩阵的列数（column）和第二个矩阵的行数（row）相同
//乘法结合律： (AB)C=A(BC)


//计算最优值
//p输入参数 size是矩阵个数 m所需最小数乘次数(最优值) s最优断开位置 
void matrixChain(int* p, int size, int* m /*, int* s*/)
{
	for(int i = 1; i < size; ++i) 
		//m[i][i] = 0; // i == j 的情况最优值为0
		m[i*size+i] = 0; // i == j 的情况最优值为0

	//最外层循环控制m[i][i+j]计算次数 
	for(int r = 2; r < size; ++r) //n个矩阵r最多取n 
	{
		//依次计算矩阵长度m[i][i+1] m[i][i+2] m[i][i+3] 
		for(int i = 1; i <= size - r; ++i)
		{
			int j = i + r -1; //r-1是矩阵链长度 
			
			//m[i][j] = m[i][i] + m[i+1][j] + p[i-1]*p[i]*p[j]; //当前最优值 
			m[i*size+j] = m[(i+1)*size+j] + p[i-1]*p[i]*p[j];
			//s[i][j] = i; //当前最优断开位置 
			
			//k的位置只有j-i种可能 
			for(int k = i + 1; k < j; ++k) //测试下一个断开位置
			{
				int tmp = m[i*size+k] + m[(k+1)*size+j] + p[i-1]*p[k]*p[j];
				if(tmp < m[i*size+j])
				{
					m[i*size+j] = tmp;
					//s[i][j] = k;
				}
			}
		}
	}			
}

int main()
{
	//输入的第一行包含一个整数n，表示矩阵的个数
	int n;
	cin >> n;
	//第二行包含n+1个数，表示给定的矩阵的规模。 	
	int p[n+1];
	
	for(int i= 0; i <= n; ++i)
		cin >> p[i];
	
	int m[(n+1)*(n+1)];
	
	matrixChain(p, n+1, m);
	cout << m[n+1+n] << endl; //m[1][n] 
	return 0;
}

