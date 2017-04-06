#include <stdio.h>
#include <stdlib.h>

unsigned long long Fib_R(size_t n)
{
	return n < 2 ? n : Fib_R(n - 1) + Fib_R(n - 2);
}

unsigned long long Fib(size_t n)
{
	if (n < 2)
		return n;
	unsigned long long first = 0;
	unsigned long long second = 1;
	unsigned long long ret = 0;
	for (size_t i = 0; i <= n; ++i)
	{
		ret = first + second;
		first = second;
		second = ret;
	}
	return ret;
}

void test2()
{
	unsigned long long ret = Fib_R(10);
	printf("ret = %ld\n", ret);
	ret = Fib(50);
	printf("ret = %lld\n", ret);
	system("pause");
}