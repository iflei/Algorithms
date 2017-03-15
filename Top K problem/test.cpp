#include <iostream>
#include "TopK.h"
using namespace std;

void testGetTopK()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19, 1, 4 };
	int size = sizeof(a) / sizeof(a[0]);
	GetTopK(a, size, 5);
}

int main()
{
	testGetTopK();
	
	system("pause");
	return 0;
}
