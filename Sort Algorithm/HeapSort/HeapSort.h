void AdjustDown(int* a, int size, int root) //升序建大堆
{
	int parent = root;
	//左孩子节点下标等于父节点下标乘2加1
	int child = parent * 2 + 1;

	while (child < size) //左孩子存在
	{
		//child指向大孩子
		//如果右孩子存在，并且右孩子大于左孩子
		if (child + 1 < size && a[child + 1] > a[child])
			++child;

		//如果孩子大于父亲，交换孩子和父亲节点的值；
		//然后让parent指向孩子结点，继续上面的操作
		if (a[child] > a[parent])
		{
			//这里用swap只能交换内置数据类型
			swap(a[child], a[parent]);

			parent = child;
			child = parent * 2 + 1;
		}
		//如果孩子小于父亲，则不需要继续向下调整
		else
			break;
	}
}
//   0
// 1   2
//3 4 5 6

//升序建大堆
void HeapSort(int* a, int size)
{
	assert(a && size > 1);//size至少为2
	//建堆
	//从最后一个非叶子节点开始（最后一个节点的下标减1再除2）
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, size, i);
	}

	//选择排序
	int end = size - 1; //end指向要排的数组的最后位置
	while (end > 0) //保证最少有2个元素
	{
		//把第0个元素和当前区间的最后一个元素交换（a[0]是堆中最大元素，正是大堆的作用）
		//保证当前的最后一个位置的元素都是现在这个序列之中最大的
		swap(a[0], a[end]);
		AdjustDown(a, end, 0);//从0到end-1重新建堆
		--end;
	}
}