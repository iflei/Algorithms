//ǰk����С����������ѣ���С���������
void GetTopK(int* a, int n, int k)
{
	assert(n > k && a);
	//��ǰk��Ԫ�ؽ���
	int* heap = new int[k];
	for (size_t i = 0; i < k; ++i)
	{
		heap[i] = a[i];
	}
 
	for (int i = (k - 2) / 2; i >= 0; --i)
	{
		AdjustDown(heap, k, i);
	}
 
	//ʣ�µ�Ԫ�����κͶѶ��Ƚ�
	for (size_t i = k; i < n; ++i)
	{
		if (a[i] < heap[0])
		{
			heap[0] = a[i];
			AdjustDown(heap, k, 0);
		}
	}
	cout << "��С��ǰ" << k << "�����ǣ�" << endl;
	for (size_t i = 0; i < k; ++i)
	{
		cout << heap[i] << " ";
	}
	cout << endl;
	delete[] heap;
}
 
//�����
void AdjustDown(int* a, int size, int root)
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
 
		//������Ӵ��ڸ��ף��������Ӻ͸��׽ڵ��ֵ��Ȼ����parentָ���ӽ�㣬��������Ĳ���
		if (a[child] > a[parent])
		{
			//������swapֻ�ܽ���������������
			int tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
 
			parent = child;
			child = parent * 2 + 1;
		}
		//�������С�ڸ��ף�����Ҫ�������µ���
		else
			break;
	}
}