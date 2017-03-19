void ShellSort(int* a, size_t n)
{
	assert(a);

	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //��1��Ŀ�������һ�μ��gap����1�����ղ�������
		//���ƶ������ͬʱ��������
		for (int i = 0; i < n - gap; ++i) //n - gap �����������ĩβ�±�
		{
			// ���Ϊgap�Ĳ�������
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