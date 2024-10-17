#include "Sort.h"
 
//向下调整
void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
			++child;
 
		//跟孩子父亲比较
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			//左右孩子都大于/小于父亲，结束交换
			break;
		}
	}
}
 
//堆排序
void HeapSort(int* a, int n)
{
	//时间复杂度：O(N)
	for (int i = (n - 1) / 2; i >= 0; i--)
		AdjustDown(a, n, i);
 
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
 