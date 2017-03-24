void Merge(int* a, int* tmp, int left, int mid, int right)
{
	//两个区间:[begin1, end1] 和 [begin2, end2]
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;

	int index = begin1;
	//选择小的值放到tmp[index]里，index和begin都向后移
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	//其中一个区间里剩余的元素依次放入tmp[index],直到放完
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right) //区间小于2或交叉直接return
		return;

	int mid = left + (right - left) / 2;

	//对两个区间进行归并排序（分小区间）
	_MergeSort(a, tmp, left, mid); //[left, mid]
	_MergeSort(a, tmp, mid + 1, right); //[mid+1, right]
	
	//两个区间都有序了，合并有序区间
	Merge(a, tmp, left, mid, right);//把a里[left, mid]和[mid+1, right]两个有序区间合并成一个有序区间，合并结果在tmp里
	memcpy(a + left, tmp + left, (right - left + 1)*sizeof(int));//把合并好的[left, right]有序区间拷贝回a数组对应的位置
}

void MergeSort(int* a, size_t n)
{
	int* tmp = new int[n];
	//借助一个同样大的临时数组，对整个区间合并排序
	_MergeSort(a, tmp, 0, n - 1);

	delete[] tmp;
}