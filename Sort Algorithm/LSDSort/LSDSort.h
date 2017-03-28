//数组里最大数位数
int MaxDigit(int* a, int n)
{
	int max = 10;
	int digit = 1;

	for (int i = 0; i < n; ++i)
	{
		while (a[i] >= max)
		{
			digit++;
			max *= 10;
		}
	}

	return digit;
}
//基数排序
void LSDSort(int* a, int n)
{
	int count[10] = { 0 }; //统计某位数相同的数的个数
	int start[10] = { 0 }; //统计某位数相同的数的起始下标

	int* butket = new int[n]; //暂存数据，防止覆盖

	int digit = MaxDigit(a, n);//最大位数
	int baseDigit = 1; //基数

	//
	for (int i = 1; i <= digit; ++i) 
	{
		memset(count, 0, sizeof(int)* 10);//count数组置零
		
		int j;
		//统计某位数相同的数的个数
		for (j = 0; j < n; ++j)
		{
			int num = (a[j] / baseDigit) % 10;//某位的数
			count[num]++;
		}

		start[0] = 0;
		for (j = 1; j < 10; ++j)
		{
			//统计某位为j的数的起始下标
			start[j] = count[j - 1] + start[j - 1];
		}

		for (j = 0; j < n; ++j)
		{
			int num = (a[j] / baseDigit) % 10;//某位的数
			int& index = start[num];//根据某位的数应该从哪个起始下标开始放数
			butket[index++] = a[j];//所有数根据放进bucket里
		}

		baseDigit *= 10;//个位、十位、百位...

		memcpy(a, butket, n * sizeof(int));
	}

	delete[] butket;
}