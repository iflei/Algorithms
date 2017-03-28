//�����������λ��
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
//��������
void LSDSort(int* a, int n)
{
	int count[10] = { 0 }; //ͳ��ĳλ����ͬ�����ĸ���
	int start[10] = { 0 }; //ͳ��ĳλ����ͬ��������ʼ�±�

	int* butket = new int[n]; //�ݴ����ݣ���ֹ����

	int digit = MaxDigit(a, n);//���λ��
	int baseDigit = 1; //����

	//
	for (int i = 1; i <= digit; ++i) 
	{
		memset(count, 0, sizeof(int)* 10);//count��������
		
		int j;
		//ͳ��ĳλ����ͬ�����ĸ���
		for (j = 0; j < n; ++j)
		{
			int num = (a[j] / baseDigit) % 10;//ĳλ����
			count[num]++;
		}

		start[0] = 0;
		for (j = 1; j < 10; ++j)
		{
			//ͳ��ĳλΪj��������ʼ�±�
			start[j] = count[j - 1] + start[j - 1];
		}

		for (j = 0; j < n; ++j)
		{
			int num = (a[j] / baseDigit) % 10;//ĳλ����
			int& index = start[num];//����ĳλ����Ӧ�ô��ĸ���ʼ�±꿪ʼ����
			butket[index++] = a[j];//���������ݷŽ�bucket��
		}

		baseDigit *= 10;//��λ��ʮλ����λ...

		memcpy(a, butket, n * sizeof(int));
	}

	delete[] butket;
}