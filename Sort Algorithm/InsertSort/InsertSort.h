void InsertSort(int* a, size_t n)
{
	assert(a);

	for (size_t i = 0; i < n - 1; ++i)
	{
		int end = i; //end指向有序区间的末尾
		int tmp = a[end + 1]; //有序区间下一个位置的值
		while (end >= 0 && a[end] > tmp) //end指针合法，并且有序区间末尾的值大于tmp
		{
			a[end + 1] = a[end]; //end位置的数向后移动
			--end;
		}
		//前面把end移到end+1，并且end--，此时原来end的位置就是空位，也就是现在的end+1处
		a[end + 1] = tmp;
	}
}