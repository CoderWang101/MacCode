#include "Sort.h"
#include "Stack.h"
 
//调试时最好切换为Release版本
 
//快速排序
 
//进行声明并初始化 ，此时当前文件callCount 与Sort.h中的为同一变量
int callCount = 0;
 
//1，hoare版本
int PartSort1(int* a, int begin, int end)
{
	//区间不存在，或者只有一个值则不需要再处理
	if (begin >= end)
		return -1;
 
	int left = begin, right = end;
	int keyi = left;
 
	while (left < right)
	{
		//右边先走，找小
		while (left < right && a[right] >= a[keyi])
			--right;
 
		// 左边再走，找大
		while (left < right && a[left] <= a[keyi])
			++left;
 
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	keyi = left;
 
	return keyi;
}
 
//2,挖坑法 相比hoare本质上并没有简化复杂度
int PartSort2(int* a, int begin, int end)
{
    int key = a[begin]; // 选择第一个元素为基准值
    int piti = begin;   // 初始化挖坑位置
 
    while (begin < end)
    {
        // 右边找小，填到左边的坑里面去。这个位置形成新的坑
        while (begin < end && a[end] >= key) // 从右边开始找比基准值小的元素
            --end;
 
        a[piti] = a[end]; // 将小元素填入左边的坑里
        piti = end;       // 更新当前坑的位置
 
        // 左边找大，填到右边的坑里面去。这个位置形成新的坑
        while (begin < end && a[begin] <= key) // 从左边开始找比基准值大的元素
            ++begin;
 
        a[piti] = a[begin]; // 将大元素填入右边的坑里
        piti = begin;       // 更新当前坑的位置
    }
    a[piti] = key; // 将基准值放入最后形成的坑中
    return piti;   // 返回基准值的最终位置
}
 
//计算中间值
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] < a[end])
			return end;
		else
			return begin;
	}
	else //a[begin]>a[mid]
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}
 
//前后指针法
int PartSort3(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;
	
	int midi = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midi]);
 
	while (cur<=end)
	{
		//cur位置的值小于keyi位置的值
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
 
	return keyi;
}
/*
	key非常影响效率：
	1.当key每次选的都为该数组从小到大的中间值，每次排序为二分，效率更高
	  但当key选的为最 小/大 时为最坏情况 
	  每次递归都是将key后面的数进行递归：N-1+N-2...=O(N^2),且会出现栈溢出
	  解决方法：1.随机选key(但存在巧合)2，三数取中(头中尾三个数对比选其中一个中间值)
	2.小区间优化：在每次递归都接近二分基础上(例：有10个数，最后一层要递归13次)
	  减小最后一层递归，当区间较小时就不在递归去分化去排序这个小区间，
	  可以考虑用其他排序对小区建处理(插入排序)
	假设递归深度为h->最后一层的调用次数为2^(h-1),倒数第二层为2^(h-2)...总调用次数为2^h - 1
	若区间不再调用最后一层，总调用次数大约会减少50%。(最后一层越50%，倒二层25%，倒三层12.5%)
	假设区间小于10时，不再递归区间->减少80%以上递归次数
*/
 
void QuickSort(int* a, int begin, int end)
{
	callCount++;
	
	//区间不存在，或者只有一个值则不需要再处理
	if (begin >= end)
		return;
 
	if (end - begin > 10)
	{
		//单趟排序
		int keyi = PartSort3(a, begin, end);
 
		//区间： [begin,keyi-1] keyi [keyi+1,right]
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	else
	{
		//小区间优化
		InsertSort(a + begin, end - begin + 1); //目前QuickSort为左右闭区间故+1
	}
}
 
//将快速排序改为非递归 ->递归在极端问题下，递归太深,会出现栈溢出
//1.直接该循环--比如斐波那契数列，归并排序	
//2.用数据结构栈模拟递归过程
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	//先入左再入右边，出栈时先出右再出左
	StackPush(&st,end);
	StackPush(&st,begin);
	
	while (!StackEmpty(&st))//无子区间时停止
	{
		int left = StackTop(&st);
		StackPop(&st);
	
		int right = StackTop(&st);
		StackPop(&st);
 
		int keyi = PartSort3(a, left, right);
		//[left,keyi-1] keyi [keyi+1,right]
 
		//左区间类递归
		if (left<keyi-1)
		{
			StackPush(&st, keyi-1);
			StackPush(&st, begin);
		}
 
		//右区间类递归
		if (keyi + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyi+1);
		}
	}
	StackDestory(&st);
}