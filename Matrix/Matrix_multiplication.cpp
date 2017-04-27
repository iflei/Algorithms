//������ȫ�������������С���˴���
#include <iostream>
using namespace std;
//��һ�������������column���͵ڶ��������������row����ͬ
//�˷�����ɣ� (AB)C=A(BC)


//��������ֵ
//p������� size�Ǿ������ m������С���˴���(����ֵ) s���ŶϿ�λ�� 
void matrixChain(int* p, int size, int* m /*, int* s*/)
{
	for(int i = 1; i < size; ++i) 
		//m[i][i] = 0; // i == j ���������ֵΪ0
		m[i*size+i] = 0; // i == j ���������ֵΪ0

	//�����ѭ������m[i][i+j]������� 
	for(int r = 2; r < size; ++r) //n������r���ȡn 
	{
		//���μ�����󳤶�m[i][i+1] m[i][i+2] m[i][i+3] 
		for(int i = 1; i <= size - r; ++i)
		{
			int j = i + r -1; //r-1�Ǿ��������� 
			
			//m[i][j] = m[i][i] + m[i+1][j] + p[i-1]*p[i]*p[j]; //��ǰ����ֵ 
			m[i*size+j] = m[(i+1)*size+j] + p[i-1]*p[i]*p[j];
			//s[i][j] = i; //��ǰ���ŶϿ�λ�� 
			
			//k��λ��ֻ��j-i�ֿ��� 
			for(int k = i + 1; k < j; ++k) //������һ���Ͽ�λ��
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
	//����ĵ�һ�а���һ������n����ʾ����ĸ���
	int n;
	cin >> n;
	//�ڶ��а���n+1��������ʾ�����ľ���Ĺ�ģ�� 	
	int p[n+1];
	
	for(int i= 0; i <= n; ++i)
		cin >> p[i];
	
	int m[(n+1)*(n+1)];
	
	matrixChain(p, n+1, m);
	cout << m[n+1+n] << endl; //m[1][n] 
	return 0;
}

