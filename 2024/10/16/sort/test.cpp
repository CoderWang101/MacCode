#include "Sort.h"
 
void TestOP()
{
	srand(time(0));
	const int N = 10000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
 
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
 
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
 
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
 
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
 
	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();
 
	int begin7 = clock();
	//Bubblesort(a7, N);
	int end7 = clock();
 
	printf("直接插入排序InsertSort:%d\n", end1 - begin1);
	printf("希尔排序ShellSort:%d\n", end2 - begin2);
	printf("选择排序SelectSort:%d\n", end3 - begin3);
	printf("堆排序HeapSort:%d\n", end4 - begin4);
	//printf("冒泡排序Bubblesort:%d\n", end7 - begin7);
	printf("快速排序QuickSort:%d\n", end5 - begin5);
	printf("归并排序MergeSort:%d\n", end6 - begin6);
 
	printf("快速排序次数callCount:%d\n", callCount);
	printf("%p\n", &callCount);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	//free(a7);
}
 
void TestInsertSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	InsertSort(a, sz);
	PrintArry(a, sz);
 
}
void TestShellSort()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(a) / sizeof(a[0]);
 
	ShellSort(a, sz);
	PrintArry(a, sz);
}
 
void TestSelectSort()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(a) / sizeof(a[0]);
 
	SelectSort(a, sz);
	PrintArry(a, sz);
}
 
void TestHeapSort()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(a) / sizeof(a[0]);
 
	HeapSort(a, sz);
	PrintArry(a, sz);
}
 
void TestBubbleSort()
{
	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(a) / sizeof(a[0]);
 
	Bubblesort(a, sz);
	PrintArry(a, sz);
}
 
void TestQuickSortSort()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	int sz = sizeof(a) / sizeof(a[0]);
 
	QuickSort(a, 0, sz-1);
	PrintArry(a, sz);
}
 
void TestQuickSortNonRSort()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	int sz = sizeof(a) / sizeof(a[0]);
 
	QuickSortNonR(a, 0, sz - 1);
	PrintArry(a, sz);
}
 
void TestMergeSortSort()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	int sz = sizeof(a) / sizeof(a[0]);
 
	MergeSort(a, sz);
	PrintArry(a, sz);
 
}
 
void TestMergeSortNonR()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	int sz = sizeof(a) / sizeof(a[0]);
 
	MergeSortNonR(a, sz);
	PrintArry(a, sz);
}
 
int main()
{
	//TestInsertSort();
	//TestBubbleSort();
	//TestQuickSortSort();
	//TestQuickSortNonRSort();
	//TestHeapSort();
	//TestMergeSortSort();
	//estMergeSortNonR();
 
	TestOP();
 
	return 0;
}