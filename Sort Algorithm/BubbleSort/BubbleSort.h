void BubbleSort(int* a, int n)
{
	assert(a);
	//n个数需要排n-1趟
	for (int i = 0; i < n - 1; ++i)
	{
		bool exchange = false;
		//第i趟需要从前向后比较n-1-i次
		for (int j = 0; j < n - 1 - i; j++) //比较时访问a[n-1-i]所以这个是开区间
		{
			if (a[j] > a[j + 1])
			{
				//把大的数向后交换
				swap(a[j], a[j + 1]);
				exchange = true;
			}
		}
		//第i趟比较完了，如果没有交换过数，说明[0, n-1-i]区间已经有序
		if (exchange == false)
			break;
	}
}