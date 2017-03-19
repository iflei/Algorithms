void ShellSort(int* a, size_t n)
{
	assert(a);

	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //加1的目的是最后一次间距gap等于1的最终插入排序
		//控制多区间的同时插入排序
		for (int i = 0; i < n - gap; ++i) //n - gap 是有序区间的末尾下标
		{
			// 间距为gap的插入排序
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}