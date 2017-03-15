//前k个最小的数，建大堆，让小数往堆里沉
void GetTopK(int* a, int n, int k)
{
	assert(n > k && a);
	//用前k个元素建堆
	int* heap = new int[k];
	for (size_t i = 0; i < k; ++i)
	{
		heap[i] = a[i];
	}
 
	for (int i = (k - 2) / 2; i >= 0; --i)
	{
		AdjustDown(heap, k, i);
	}
 
	//剩下的元素依次和堆顶比较
	for (size_t i = k; i < n; ++i)
	{
		if (a[i] < heap[0])
		{
			heap[0] = a[i];
			AdjustDown(heap, k, 0);
		}
	}
	cout << "最小的前" << k << "个数是：" << endl;
	for (size_t i = 0; i < k; ++i)
	{
		cout << heap[i] << " ";
	}
	cout << endl;
	delete[] heap;
}
 
//建大堆
void AdjustDown(int* a, int size, int root)
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
 
		//如果孩子大于父亲，交换孩子和父亲节点的值；然后让parent指向孩子结点，继续上面的操作
		if (a[child] > a[parent])
		{
			//这里用swap只能交换内置数据类型
			int tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
 
			parent = child;
			child = parent * 2 + 1;
		}
		//如果孩子小于父亲，则不需要继续向下调整
		else
			break;
	}
}