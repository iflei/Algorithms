void AdjustDown(int* a, int size, int root) //���򽨴��
{
	int parent = root;
	//���ӽڵ��±���ڸ��ڵ��±��2��1
	int child = parent * 2 + 1;

	while (child < size) //���Ӵ���
	{
		//childָ�����
		//����Һ��Ӵ��ڣ������Һ��Ӵ�������
		if (child + 1 < size && a[child + 1] > a[child])
			++child;

		//������Ӵ��ڸ��ף��������Ӻ͸��׽ڵ��ֵ��
		//Ȼ����parentָ���ӽ�㣬��������Ĳ���
		if (a[child] > a[parent])
		{
			//������swapֻ�ܽ���������������
			swap(a[child], a[parent]);

			parent = child;
			child = parent * 2 + 1;
		}
		//�������С�ڸ��ף�����Ҫ�������µ���
		else
			break;
	}
}
//   0
// 1   2
//3 4 5 6

//���򽨴��
void HeapSort(int* a, int size)
{
	assert(a && size > 1);//size����Ϊ2
	//����
	//�����һ����Ҷ�ӽڵ㿪ʼ�����һ���ڵ���±��1�ٳ�2��
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, size, i);
	}

	//ѡ������
	int end = size - 1; //endָ��Ҫ�ŵ���������λ��
	while (end > 0) //��֤������2��Ԫ��
	{
		//�ѵ�0��Ԫ�غ͵�ǰ��������һ��Ԫ�ؽ�����a[0]�Ƕ������Ԫ�أ����Ǵ�ѵ����ã�
		//��֤��ǰ�����һ��λ�õ�Ԫ�ض��������������֮������
		swap(a[0], a[end]);
		AdjustDown(a, end, 0);//��0��end-1���½���
		--end;
	}
}