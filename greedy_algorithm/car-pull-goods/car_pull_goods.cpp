//知道汽车核载重量为w，可供选择的物品的数量n。每个物品的重量为gi,价值为pi。求汽车可装载的最大价值。（所拉货物为散货）\
//（n<10000,w<10000,0<gi<=100,0<=pi<=100)
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct bag
{
	int gi; //物品的重量 
	int pi; //物品的价格 
	double per; //每件物品的单价	
}a[10000];

//降序排序 
int cmp(bag a, bag b)
{
	return a.per > b.per;	
}

int main()
{
	//两个整数n w
	int n, w, i;
	cin >> n >> w;
	//每行有两个整数，由空格分开，分别表示gi和pi
	for(i = 0; i < n; ++i)
	{
		cin >> a[i].gi >> a[i].pi;
		a[i].per = a[i].pi * 1.0 / a[i].gi;
	}
	//降序排序 
	sort(a, a+n, cmp);
	double maxValue = 0; //最大价值 
	int sumWei = 0; //当前总重量 
	for(i = 0; i < n && w-sumWei >= a[i].gi; ++i)
	{
		maxValue += a[i].pi;
		sumWei += a[i].gi;
	}
	//装不下装个物品，可以散装 
	if(i < n)
	{
		maxValue += (w-sumWei) * a[i].per;
	} 
	printf("%.1f", maxValue);
	return 0;
} 