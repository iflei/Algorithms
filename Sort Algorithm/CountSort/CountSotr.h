//��������
void CountSort(int* a, int n)
{
	//�ҵ����������е����ֵ����Сֵ  
	int max = a[0];
	int min = a[0];
	for (size_t i = 1; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	//�����ʵ��ռ������  
	int range = max - min + 1;
	int* tmp = new int[range];
	memset(tmp, 0, sizeof(int) * range);
	for (size_t i = 0; i < n; ++i)
	{
		tmp[a[i] - min]++;
	}

	//�����ݿ�����ԭ����  
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (tmp[i]--)
		{
			a[index] = i + min;
			++index;
		}
	}
	delete[]tmp;
}