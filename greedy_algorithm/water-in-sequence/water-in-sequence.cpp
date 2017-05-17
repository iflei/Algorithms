//有n个人排队到r个水龙头去打水，他们装满水桶的时间t1、t2………..tn为整数且各不相等，应如何安排他们的打水顺序才能使他们总共花费的时间最少？
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int t[500] = {0}; //打水时间 
int d[75] = {0}; //水龙头的等待时间

int main()
{ 
	int n, r, i;
	cin >> n >> r;
	for(i = 0; i < n; ++i)
		cin >> t[i];
	
	//按打水时间升序排序
	sort(t, t+n);
	
	int sum = 0; //总共花费时间 
	for(i = 0; i < n; ++i)
	{
		//把等待时间最小的水龙头排前面
		sort(d, d+r); 
		//当前龙头等待的时间 + 第i个人打水需要时间 
		sum += d[0] + t[i]; 
		//更新当前龙头等待的时间
		d[0] += t[i];
	}
	cout << sum << endl;
	return 0;
} 