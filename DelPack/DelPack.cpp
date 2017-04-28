//删除输入字符串中所有的重复元素。不连续的重复元素也要删除。 
#include <iostream>
#include <string.h>
using namespace std;

void DelPack(char* str)
{
	//p 先指向字符串开始，q 向后寻找相同的字符 
	for(char* p = str; *p != '\0'; ++p)
	{
		int len = strlen(p); 
		for(char* q = p + 1; *q != '\0'; ++q)
		{
			if(*q == *p)
			{
				//消除相同字符，//先删后面的 
				strcpy(q, q+1); //覆盖法删除 
			}
		}
		//如果strlen(p)变小了，说明后面有元素被删了
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