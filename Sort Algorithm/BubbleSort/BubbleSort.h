void BubbleSort(int* a, int n)
{
	assert(a);
	//n������Ҫ��n-1��
	for (int i = 0; i < n - 1; ++i)
	{
		bool exchange = false;
		//��i����Ҫ��ǰ���Ƚ�n-1-i��
		for (int j = 0; j < n - 1 - i; j++) //�Ƚ�ʱ����a[n-1-i]��������ǿ�����
		{
			if (a[j] > a[j + 1])
			{
				//�Ѵ������󽻻�
				swap(a[j], a[j + 1]);
				exchange = true;
			}
		}
		//��i�˱Ƚ����ˣ����û�н���������˵��[0, n-1-i]�����Ѿ�����
		if (exchange == false)
			break;
	}
}