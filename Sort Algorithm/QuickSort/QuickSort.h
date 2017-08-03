//����ȡ��
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else //left > mid
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;
	}
}

//����ָ�뷨
int PartSort1(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);

	swap(a[mid], a[right]); //������ȡ�з�ȡ�����ŵ�����ĩβ
	int key = a[right]; //������ĩβ������key

	int begin = left;
	int end = right - 1; //����key������
	while (begin < end)
	{
		//begin�ұ�key���ֵ
		while (begin < end && a[begin] <= key)
			++begin;
		//end�ұ�keyС��ֵ
		while (begin < end && a[end] >= key)
			--end;
		//�ѱȴ��ֵ��С��ֵ����
		if (begin < end)
			swap(a[begin], a[end]);
	}

	//������begin����end
	if (a[begin] > key)
	{
		swap(a[begin], a[right]); //��bug
		return begin;
	}
	else //key����߶���keyС���ұ�û����
		return right;
}

//�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	
	swap(a[mid], a[right]);
	int key = a[right]; //�ʼendλ���ǿ�

	int begin = left;
	int end = right; //��������
	while (begin < end)
	{
		//begin�ұ�key���ֵ
		while (begin < end && a[begin] <= key)
			++begin;
		//begin�ҵ�һ����key���ֵ������begin<end
		if (begin < end)
			a[end] = a[begin];  //�end������begin λ�ñ�ɿ�

		//end�ұ�keyС��ֵ
		while (begin < end && a[end] >= key)
			--end;
		//end�ҵ�һ����keyС��ֵ������begin<end
		if (begin < end)
			a[begin] = a[end]; //�begin������endλ�ñ�ɿ�
	}
	//������begin����end����beginָ��ӣ���key�ŵ�����
	a[begin] = key;
	return begin;
}

//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	
	swap(a[mid], a[right]);
	int key = a[right];

	int cur = left;
	int prev = left - 1;
	
	while (cur < right)
	{
		//��cur��ֵһֱС��keyʱ��prev������cur���棬if�ڶ������������㣨�߼����������������жϣ���
		//��cur��ֵ����keyʱ��if���������㣬���Ҳ����жϵڶ������������prev������ǰ�ߣ�
		//��cur������ǰ�ߣ�֪���ҵ�һ��С��key��λ�ã���ʱprev��cur�����˾��룬++prev != cur�ڶ�������Ҳ�����ˣ�
		//++prev��ָ��cur�����ĵ�һ����key���ֵ��λ�ã���curָ��һ����keyС��ֵ��λ�ã���ʱ����cur��prev��ֵ��
		if (a[cur] < key && ++prev != cur)
			swap(a[cur], a[prev]);
		
		++cur;
	}
	//������cur����right
	++prev; //��prevָ���key���ֵ��λ��
	swap(a[prev], a[cur]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	assert(a);
	//��������СΪ1�򽻲��return
	if (left >= right)
		return;

	//С�����Ż�������С�ڵ���5�ͽ��в�������
	if (right - left < 5) 
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		//div��ߵ�������divС���ұߵ�������div��
		int div = PartSort3(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}

void QuickSort_NonR(int* a, int left, int right)
{
	stack<int> s;
	//�������±���ջ��
	s.push(left); //�ȴ�left
	s.push(right); 

	while (!s.empty()) //ջ��ʱ�������䶼������
	{
		int end = s.top();
		s.pop();
		int begin = s.top();
		s.pop();

		////С�����Ż�������С�ڵ���5�ͽ��в�������
		if (right - left < 5)
		{
			InsertSort(a + left, right - left + 1);
		}
		else
		{
			int div = PartSort3(a, begin, end);
			if (begin < div - 1) //div��߻��д��ڵ���2������
			{
				s.push(begin); //�������left��rightѹ��ջ
				s.push(div - 1);
			}
			if (end > div + 1)
			{
				s.push(div + 1);
				s.push(end);
			}
		}
	}
}
