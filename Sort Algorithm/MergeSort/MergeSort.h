void Merge(int* a, int* tmp, int left, int mid, int right)
{
	//��������:[begin1, end1] �� [begin2, end2]
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;

	int index = begin1;
	//ѡ��С��ֵ�ŵ�tmp[index]�index��begin�������
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	//����һ��������ʣ���Ԫ�����η���tmp[index],ֱ������
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right) //����С��2�򽻲�ֱ��return
		return;

	int mid = left + (right - left) / 2;

	//������������й鲢���򣨷�С���䣩
	_MergeSort(a, tmp, left, mid); //[left, mid]
	_MergeSort(a, tmp, mid + 1, right); //[mid+1, right]
	
	//�������䶼�����ˣ��ϲ���������
	Merge(a, tmp, left, mid, right);//��a��[left, mid]��[mid+1, right]������������ϲ���һ���������䣬�ϲ������tmp��
	memcpy(a + left, tmp + left, (right - left + 1)*sizeof(int));//�Ѻϲ��õ�[left, right]�������俽����a�����Ӧ��λ��
}

void MergeSort(int* a, size_t n)
{
	int* tmp = new int[n];
	//����һ��ͬ�������ʱ���飬����������ϲ�����
	_MergeSort(a, tmp, 0, n - 1);

	delete[] tmp;
}