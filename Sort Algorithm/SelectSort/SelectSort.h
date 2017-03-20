void SelectSort(int* a, size_t n)
{
	assert(a);
	for (int end = n - 1; end > 0; --end) //��end��Сѡ�������
	{
		int maxIndex = 0;//maxIndex�����ѡ���������ֵ���±�
		for (int i = 1; i <= end; ++i) //��0��endѡ�����ֵ
		{
			if (a[i] > a[maxIndex])
			{
				maxIndex = i;
			}
		}
		swap(a[maxIndex], a[end]);//��ѡ�������ֵ��end����
	}
}

void SelectSortOP1(int* a, size_t n)
{
	assert(a);

	int left = 0, right = n - 1; //leftָ������0�±꣬rightָ������ĩβ
	while (left < right)  //left < right��֤�����С����Ϊ����Ԫ��
	{
		int minIndex = left, maxIndex = left;//minIndex��maxIndex�����ѡ��������Сֵ�����ֵ���±�
		for (int i = left+1; i <= right; ++i) //��������ѡ�����ֵ����Сֵ���±�
		{
			if (a[i] > a[maxIndex])  
				maxIndex = i;

			if (a[i] < a[minIndex])
				minIndex = i;
		}

		swap(a[left], a[minIndex]); //����������С��ֵ��left����
		//���maxIndex����left������ǰ��left��ֵ��minIndex��ֵ�����ˣ�����maxIndexӦ��ָ��minIndex
		if (maxIndex == left)
			maxIndex = minIndex;

		swap(a[right], a[maxIndex]); //������������ֵ��right����

		//��С����
		++left;
		--right;
	}
}

void SelectSortOP2(int* a, size_t n)
{
	assert(a);

	int left = 0, right = n - 1; //leftָ������0�±꣬rightָ������ĩβ
	while (left < right)  //left < right��֤�����С����Ϊ����Ԫ��
	{
		for (int i = left; i <= right; ++i)//��������
		{
			if (a[i] < a[left])//�ѱ�leftС��ֵ��left����
				swap(a[i], a[left]);

			if (a[i] > a[right])//�ѱ�right���ֵ��right����
				swap(a[i], a[right]);
		}

		//��С����
		++left;
		--right;
	}
}