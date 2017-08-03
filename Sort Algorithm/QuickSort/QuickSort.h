//三数取中
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

//左右指针法
int PartSort1(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);

	swap(a[mid], a[right]); //把三数取中法取的数放到区间末尾
	int key = a[right]; //用区间末尾的数做key

	int begin = left;
	int end = right - 1; //除了key的区间
	while (begin < end)
	{
		//begin找比key大的值
		while (begin < end && a[begin] <= key)
			++begin;
		//end找比key小的值
		while (begin < end && a[end] >= key)
			--end;
		//把比大的值和小的值交换
		if (begin < end)
			swap(a[begin], a[end]);
	}

	//到这里begin等于end
	if (a[begin] > key)
	{
		swap(a[begin], a[right]); //靠bug
		return begin;
	}
	else //key的左边都比key小，右边没有数
		return right;
}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	
	swap(a[mid], a[right]);
	int key = a[right]; //最开始end位置是坑

	int begin = left;
	int end = right; //整个区间
	while (begin < end)
	{
		//begin找比key大的值
		while (begin < end && a[begin] <= key)
			++begin;
		//begin找到一个比key大的值，并且begin<end
		if (begin < end)
			a[end] = a[begin];  //填到end这个坑里，begin 位置变成坑

		//end找比key小的值
		while (begin < end && a[end] >= key)
			--end;
		//end找到一个比key小的值，并且begin<end
		if (begin < end)
			a[begin] = a[end]; //填到begin这个坑里，end位置变成坑
	}
	//到这里begin等于end并且begin指向坑，把key放到坑里
	a[begin] = key;
	return begin;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	
	swap(a[mid], a[right]);
	int key = a[right];

	int cur = left;
	int prev = left - 1;
	
	while (cur < right)
	{
		//当cur的值一直小于key时，prev紧跟在cur后面，if第二个条件不满足（逻辑与两个条件都会判断）；
		//当cur的值大于key时，if条件不满足，并且不会判断第二个条件，因此prev不会向前走；
		//当cur继续向前走，知道找到一个小于key的位置，这时prev和cur拉开了距离，++prev != cur第二个条件也满足了；
		//++prev后指向cur遇到的第一个比key大的值的位置，而cur指向一个比key小的值的位置，这时交换cur和prev的值；
		if (a[cur] < key && ++prev != cur)
			swap(a[cur], a[prev]);
		
		++cur;
	}
	//到这里cur等于right
	++prev; //让prev指向比key大的值的位置
	swap(a[prev], a[cur]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	assert(a);
	//如果区间大小为1或交叉就return
	if (left >= right)
		return;

	//小区间优化：区间小于等于5就进行插入排序
	if (right - left < 5) 
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		//div左边的数都比div小，右边的数都比div大
		int div = PartSort3(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}

void QuickSort_NonR(int* a, int left, int right)
{
	stack<int> s;
	//把区间下标存进栈里
	s.push(left); //先存left
	s.push(right); 

	while (!s.empty()) //栈空时所有区间都有序了
	{
		int end = s.top();
		s.pop();
		int begin = s.top();
		s.pop();

		////小区间优化：区间小于等于5就进行插入排序
		if (right - left < 5)
		{
			InsertSort(a + left, right - left + 1);
		}
		else
		{
			int div = PartSort3(a, begin, end);
			if (begin < div - 1) //div左边还有大于等于2的区间
			{
				s.push(begin); //把区间的left和right压入栈
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
