//��n�����Ŷӵ�r��ˮ��ͷȥ��ˮ������װ��ˮͰ��ʱ��t1��t2������..tnΪ�����Ҹ�����ȣ�Ӧ��ΰ������ǵĴ�ˮ˳�����ʹ�����ܹ����ѵ�ʱ�����٣�
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int t[500] = {0}; //��ˮʱ�� 
int d[75] = {0}; //ˮ��ͷ�ĵȴ�ʱ��

int main()
{ 
	int n, r, i;
	cin >> n >> r;
	for(i = 0; i < n; ++i)
		cin >> t[i];
	
	//����ˮʱ����������
	sort(t, t+n);
	
	int sum = 0; //�ܹ�����ʱ�� 
	for(i = 0; i < n; ++i)
	{
		//�ѵȴ�ʱ����С��ˮ��ͷ��ǰ��
		sort(d, d+r); 
		//��ǰ��ͷ�ȴ���ʱ�� + ��i���˴�ˮ��Ҫʱ�� 
		sum += d[0] + t[i]; 
		//���µ�ǰ��ͷ�ȴ���ʱ��
		d[0] += t[i];
	}
	cout << sum << endl;
	return 0;
} 