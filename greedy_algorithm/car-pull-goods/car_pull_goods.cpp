//֪��������������Ϊw���ɹ�ѡ�����Ʒ������n��ÿ����Ʒ������Ϊgi,��ֵΪpi����������װ�ص�����ֵ������������Ϊɢ����\
//��n<10000,w<10000,0<gi<=100,0<=pi<=100)
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct bag
{
	int gi; //��Ʒ������ 
	int pi; //��Ʒ�ļ۸� 
	double per; //ÿ����Ʒ�ĵ���	
}a[10000];

//�������� 
int cmp(bag a, bag b)
{
	return a.per > b.per;	
}

int main()
{
	//��������n w
	int n, w, i;
	cin >> n >> w;
	//ÿ���������������ɿո�ֿ����ֱ��ʾgi��pi
	for(i = 0; i < n; ++i)
	{
		cin >> a[i].gi >> a[i].pi;
		a[i].per = a[i].pi * 1.0 / a[i].gi;
	}
	//�������� 
	sort(a, a+n, cmp);
	double maxValue = 0; //����ֵ 
	int sumWei = 0; //��ǰ������ 
	for(i = 0; i < n && w-sumWei >= a[i].gi; ++i)
	{
		maxValue += a[i].pi;
		sumWei += a[i].gi;
	}
	//װ����װ����Ʒ������ɢװ 
	if(i < n)
	{
		maxValue += (w-sumWei) * a[i].per;
	} 
	printf("%.1f", maxValue);
	return 0;
} 