
template <typename T>
class TwoStack
{
	TwoStack()
		:arr(NULL)
		, top1(0)
		, top2(9)
		, capacity(10)
	{
		arr = new T[capacity];
	}

	~TwoStack()
	{
		if (arr)
			delete[] arr;
	}

	void Push1(const T& x)
	{
		_CheckCapacity();
		arr[top1++] = x;
	}

	void Push2(const T& x)
	{
		_CheckCapacity();
		arr[top2--] = x;
	}

	void Pop1()
	{
		if (top1 > 0)
			--top1;
	}

	void Pop2()
	{
		if (top2 < capacity -1)
			++top2;
	}

protected:
	void _CheckCapacity()
	{
		if (top1 > top2)
		{
			//开新空间
			size_t oldCapacity = capacity;
			capacity = capacity * 3 / 2;
			T* tmp = new T[capacity];

			//拷贝数据
			for (int i = 0; i < top1; ++i)
				tmp[i] = arr[i];
			for (int i = oldCapacity - 1, j = capacity - 1; i > top2; --i, --j)
				tmp[j] = arr[i];

			delete[] arr;
			arr = tmp;
			top2 += oldCapacity / 2; //调整top2
		}
	}

private:
	T* arr;
	size_t top1;
	size_t top2;
	size_t capacity;
};