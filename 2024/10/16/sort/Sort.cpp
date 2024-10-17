#include "Sort.h"
#include "Stack.h"
 
void PrintArry(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ",a[i]);
 
	printf("\n");
}
 
//直接插入排序
//1，直接插入排序（单趟排序） 一个数一次向后比较一个元素，当比该数字小时，后面元素后移，后插入该数
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		// [0,end]有序，吧end+1 位置的值插入，保持有序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])//要交换的数字更大
			{
				//指针指向元素后移，end指针前移
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				//要交换的数字更小,退出循环
				break;
			}
		}
		//开始交换
		a[end + 1] = tmp;
	}
}
 
//希尔排序
/*
	1,预排序(接近顺序有序)
	2,直接插入排序(有序)
*/
//void ShellSort(int* a, int n)
//{
//	int gap = 3;
//	//gap组交替进行排序
//	/*
//	gap越大大的数更快到后面,小的数可以更快到前面
//	排升序,gap越小,越接近有序,当gap==1,就是插入排序
//	*/
//	for (int i = 0; i < n-gap; i++)
//	{
//		int end = i;
//		int tmp = a[end + gap];
//
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				//排序
//				a[end + gap] = a[end];
//				end -= gap;
//			}
//			else
//				break;
//		}
//		a[end + gap] = tmp;
//	}
	//for (int j = 0; j < gap; j++)//往前走一位,gap另一部分
	//{
	//	for (int i = 0; i < n - gap; i += gap)
	//	{
	//		int end = i;
	//		int tmp = a[end + gap];
 
	//		while (end >= 0)
	//		{
	//			if (tmp < a[end])
	//			{
	//				//排序
	//				a[end + gap] = a[end];
	//				end -= gap;
	//			}
	//			else
	//				break;
	//		}
	//		a[end + gap] = tmp;
	//	}
	//}
//}
 
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
 
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;// /3:保证每次跳跃的间隔. 1：保证不为0
 
		//gap组交替进行排序
		/*
		gap越大大的数更快到后面,小的数可以更快到前面
		排升序,gap越小,越接近有序,当gap==1,就是插入排序
		*/
		for (int i = 0; i < n - gap; i++)//往前走一位,gap另一部分	
		{
			int end = i;
			int tmp = a[end + gap];
 
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					//排序
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}
 
 
//选择排序 o(N^2)
//对比插入排序，还是插入排序更优
void SelectSort(int* a, int n)
{
	assert(a);
	//遍历一遍选出最小and最大的，分别放在左右边
	int begin = 0, end = n - 1;
	int mini = begin, maxi = begin;
	while (begin<end)
	{
		for (int i = 0; i <= end; i++)
		{
			if (a[i] < a[mini])
				mini = i;
 
			if (a[i] > a[maxi])
				maxi = i;
		}
 
		Swap(&a[begin], &a[mini]);
 
		//如果begin和maxi重叠，那么需要修正位置
		if (begin == maxi)
			maxi = mini;
 
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
} 
 
//冒泡排序  时间复杂度O(N^2),最坏情况还为O(N^2)
//对比插入排序哪个更好？--接近有序或局部有序时，插入排序能更好适应
void Bubblesort(int* a, int n)
{
	assert(a);
 
	for (int j = 0; j < n; j++)
	{
		int exchange = 0;
		for (int i = 0; i < n - j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}
 
void _MergeSort(int* a, int begin, int end,int* tmp)//temp:第三方数组
{
	if (begin >= end)
		return;
 
	int mid=(begin + end) / 2;
	//[begin,mid][mid+1,end]分值递归，让子区间有序
	
	_MergeSort(a, begin, mid, tmp);	// 递归  左区间
	_MergeSort(a, mid + 1, end, tmp);//递归 右边区间
 
	//归并[begin,mid][mid+1,end]
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;
	while (begin1<=end1 && begin2<=end2)
	{
		if (a[begin1]< a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	
	while (begin1<=end1)
	{
		tmp[i++] = a[begin1++];
	}
	
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
 
	//把归并拷贝回原数组
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}
 
//归并排序
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);
 
	free(tmp);
}
 
//非递归 归并排序
//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	int gap = 1;
//	while (gap<n)
//	{
//		printf("gap->%d",gap);
//		for (int i = 0; i < n; i += 2 * gap)
//		{ 
//			//[imi+gap-1][i+gap,i+2*gap-1] //此时数组长度不为2的次方就会出现越界
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			printf("[%d,%d] [%d,%d]--", begin1, end1, begin2, end2);
//
//			int j = begin1;
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[j++] = a[begin1++];
//				}
//				else
//				{
//					tmp[j++] = a[begin2++];
//				}
//			}
//			while (begin1 <= end1)
//			{
//				tmp[j++] = a[begin1++];
//
//			}
//
//			while (begin2 <= end2)
//			{
//				tmp[j++] = a[begin2++];
//			}
//		}
//		printf("\n");
//		memcpy(a, tmp, n * sizeof(int));
//		gap *= 2;
//	}
//	free(tmp);
//}
//非递归 归并排序
/* 
	end1 begin2 end2 皆有可能出现越界
	故应该修正边界 
*/
 
//方法一 修正边界法
void _MergeSortNonR1(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
 
	int gap = 1;
	while (gap < n)
	{
		printf("gap->%d", gap);
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[imi+gap-1][i+gap,i+2*gap-1] //此时数组长度不为2的次方就会出现越界
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
 
			//修正边界(阻止越界)	
			/*
				若选择直接修正begin2即,不进行类递归:
				if (begin2>=2)
					break;
				这将导致该数组begin2照样会越界且最后进行memcpy时末尾元素可能会出现随机值
			*/
			if (end1 >= n)//end1越界
			{
				end1 = n - 1;
				/*
					修正end1后，将begin2和end2修正为一个不存在的区间
					再用if语句进行判断是否越界若是直接退出该次类递归
				*/
				//[begin2,end2]
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)
				end2 = n - 1;
 
			printf("[%d,%d] [%d,%d]--", begin1, end1, begin2, end2);
 
			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					tmp[j++] = a[begin1++];
				else
					tmp[j++] = a[begin2++];
			}
 
			while (begin1 <= end1)
				tmp[j++] = a[begin1++];
 
			while (begin2 <= end2)
				tmp[j++] = a[begin2++];
		}
		printf("\n");
		memcpy(a, tmp, n * sizeof(int));
		gap *= 2;
	}
	free(tmp);
}
 
//方法二 越界只有可能在[begin2,end2] end1，最后一组越界时停止递归而对end1进行修正
void _MergeSortNonR2(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
 
	int gap = 1;
	while (gap < n)
	{
		printf("gap->%d ", gap);
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[imi+gap-1][i+gap,i+2*gap-1] //此时数组长度不为2的次方就会出现越界
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
 
			//end1越界或begin2越界。则可以不归并了
			if (end1 >= n || begin2 >= n)
				break;
			else if (end2 >= n)
				end2 = n - 1;
 
			//printf("[%d,%d] [%d,%d]--", begin1, end1, begin2, end2);
			
			int m = end2 - begin1+1;//元素个数
			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					tmp[j++] = a[begin1++];
				else
					tmp[j++] = a[begin2++];
			}
 
			while (begin1 <= end1)
				tmp[j++] = a[begin1++];
 
			while (begin2 <= end2)
				tmp[j++] = a[begin2++];
 
			//每类递归依次，进行一次拷贝 
			memcpy(a + i, tmp + i, sizeof(int) * m);
		}
		gap *= 2;
	}
	free(tmp);
}
 
void MergeSortNonR(int* a, int n)
{
	_MergeSortNonR2(a, n);
}
 
//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//
//	int gap = 1;
//	while (gap < n)
//	{
//		printf("gap->%d", gap);
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			//[imi+gap-1][i+gap,i+2*gap-1] //此时数组长度不为2的次方就会出现越界
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			
//			//修正边界(阻止越界)	
//			/*
//				若选择直接修正begin2即,不进行类递归:
//				if (begin2>=2)
//					break;
//				这将导致该数组begin2照样会越界且最后进行memcpy时末尾元素可能会出现随机值
//			*/
//			if (end1 >= n)//end1越界
//			{
//				end1 = n - 1;
//				/*
//					修正end1后，将begin2和end2修正为一个不存在的区间
//					再用if语句进行判断是否越界若是直接退出该次类递归
//				*/
//				//[begin2,end2]
//				begin2 = n;
//				end2 = n - 1;
//			}
//			else if (begin2 >= n)
//			{
//				begin2 = n;
//				end2 = n - 1;
//			}
//			else if (end2 >= n)
//				end2 = n - 1;
//
//			printf("[%d,%d] [%d,%d]--", begin1, end1, begin2, end2);
//
//			int j = begin1;
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//					tmp[j++] = a[begin1++];
//				else
//					tmp[j++] = a[begin2++];
//			}
//
//			while (begin1 <= end1)
//				tmp[j++] = a[begin1++];
//
//			while (begin2 <= end2)
//				tmp[j++] = a[begin2++];
//		}
//		printf("\n");
//		memcpy(a, tmp, n  * sizeof(int));
//		gap *= 2;
//	}
//	free(tmp);
//}