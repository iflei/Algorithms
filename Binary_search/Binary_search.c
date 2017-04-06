#include <stdio.h>
#include <stdlib.h>

int binary_search(int* arr, int size, int flag)
{
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (flag == arr[mid])
			return mid;
		else if (flag > arr[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int binary_search_R(int* arr, int low, int high, int flag)
{
	if (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (flag == arr[mid])
			return mid;
		else if (flag > arr[mid])
			return binary_search_R(arr, mid + 1, high, flag);
		else
			return binary_search_R(arr, low, mid - 1, flag);
	}
	else
		return -1;
}

void test1()
{
	int arr[9] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
	int ret = binary_search(arr, sizeof(arr)/sizeof(arr[0]), 55);
	printf("ret = %d\n", ret);
	ret = binary_search_R(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 66);
	printf("ret = %d\n", ret);
}