void InsertSort(int* a, size_t n)
{
	assert(a);

	for (size_t i = 0; i < n - 1; ++i)
	{
		int end = i; //endָ�����������ĩβ
		int tmp = a[end + 1]; //����������һ��λ�õ�ֵ
		while (end >= 0 && a[end] > tmp) //endָ��Ϸ���������������ĩβ��ֵ����tmp
		{
			a[end + 1] = a[end]; //endλ�õ�������ƶ�
			--end;
		}
		//ǰ���end�Ƶ�end+1������end--����ʱԭ��end��λ�þ��ǿ�λ��Ҳ�������ڵ�end+1��
		a[end + 1] = tmp;
	}
}