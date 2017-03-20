void SelectSort(int* a, size_t n)
{
	assert(a);
	for (int end = n - 1; end > 0; --end) //用end缩小选择的区间
	{
		int maxIndex = 0;//maxIndex标记所选区间里最大值的下标
		for (int i = 1; i <= end; ++i) //从0到end选出最大值
		{
			if (a[i] > a[maxIndex])
			{
				maxIndex = i;
			}
		}
		swap(a[maxIndex], a[end]);//把选出的最大值和end交换
	}
}

void SelectSortOP1(int* a, size_t n)
{
	assert(a);

	int left = 0, right = n - 1; //left指向数组0下标，right指向数组末尾
	while (left < right)  //left < right保证区间大小最少为两个元素
	{
		int minIndex = left, maxIndex = left;//minIndex和maxIndex标记所选区间里最小值和最大值的下标
		for (int i = left+1; i <= right; ++i) //遍历区间选出最大值和最小值的下标
		{
			if (a[i] > a[maxIndex])  
				maxIndex = i;

			if (a[i] < a[minIndex])
				minIndex = i;
		}

		swap(a[left], a[minIndex]); //把区间内最小的值和left交换
		//如果maxIndex等于left，由于前面left的值和minIndex的值交换了，所以maxIndex应该指向到minIndex
		if (maxIndex == left)
			maxIndex = minIndex;

		swap(a[right], a[maxIndex]); //把区间内最大的值和right交换

		//缩小区间
		++left;
		--right;
	}
}

void SelectSortOP2(int* a, size_t n)
{
	assert(a);

	int left = 0, right = n - 1; //left指向数组0下标，right指向数组末尾
	while (left < right)  //left < right保证区间大小最少为两个元素
	{
		for (int i = left; i <= right; ++i)//遍历区间
		{
			if (a[i] < a[left])//把比left小的值和left交换
				swap(a[i], a[left]);

			if (a[i] > a[right])//把比right大的值和right交换
				swap(a[i], a[right]);
		}

		//缩小区间
		++left;
		--right;
	}
}