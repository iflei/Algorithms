//ɾ�������ַ��������е��ظ�Ԫ�ء����������ظ�Ԫ��ҲҪɾ���� 
#include <iostream>
#include <string.h>
using namespace std;

void DelPack(char* str)
{
	//p ��ָ���ַ�����ʼ��q ���Ѱ����ͬ���ַ� 
	for(char* p = str; *p != '\0'; ++p)
	{
		int len = strlen(p); 
		for(char* q = p + 1; *q != '\0'; ++q)
		{
			if(*q == *p)
			{
				//������ͬ�ַ���//��ɾ����� 
				strcpy(q, q+1); //���Ƿ�ɾ�� 
			}
		}
		//���strlen(p)��С�ˣ�˵��������Ԫ�ر�ɾ��
		if(strlen(p) < len) 
		{
			strcpy(p, p+1);
		} 
	}
}

int main()
{
	char str[101] = {'\0'};
	cin >> str;
	DelPack(str);
	cout << str << endl;
	return 0;
}