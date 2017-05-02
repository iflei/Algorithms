#include <iostream>
#include <string.h>
using namespace std;

int b[1000][1000];
int c[1000][1000];

int lcsLength(char* x, char* y)
{
	int m = strlen(x);
	int n = strlen(y);
	
	for(int i = 1; i <= m; ++i)
		c[i][0] = 0;
	for(int i = 1; i <= n; ++i)
		c[0][i] = 0;
	
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(x[i-1] == y[j-1]) //字符串下标从0开始 
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1;
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = 3;
			}
		}
	}
	return c[m][n];
}

void lcs(int i, int j, char* x)
{
	if(i==0 || j==0)
		return;
	
	if(b[i][j] == 1)
	{
		lcs(i-1, j-1, x);
		cout << x[i-1]; //字符串下标从0开始 
	}
	else if(b[i][j] == 2)
		lcs(i-1, j, x);
	else
		lcs(i, j-1, x);
}
//ABCBDAB BDCABA 
int main()
{
	char x[1000];
	char y[1000];
	cin >> x >> y;
	cout << lcsLength(x, y) << endl;
	//第三个参数传较长的字符串 
	lcs(strlen(x), strlen(y), x);
	return 0;
}
