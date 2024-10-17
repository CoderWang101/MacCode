#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
 
void PrintArry(int* a, int n);
 
//直接插入排序
void InsertSort(int* a, int n);
 
//希尔排序
void ShellSort(int* a, int n);
 
//选择排序
void SelectSort(int* a, int n);
 
void Swap(int* p1, int* p2);
 
void AdjustDown(int* a, int size, int parent);
 
//堆排序
void HeapSort(int* a, int n);
 
//冒泡排序
void Bubblesort(int* a, int n);
 
//快速排序
void QuickSort(int* a, int begin, int end);
//直接定义 int callCount=0; 在Sort.和Heap.c 在编译的链接过程中产生冲突,导致输出callCount时会出现错误输出
// static int callCount=0; 为仅该文件可用,错误
//extern : 声明变量
extern int callCount;//快排执行次数
 
//将快速排序改为非递归
void QuickSortNonR(int* a, int begin, int end);
 
//归并排序
void MergeSort(int* a, int n);
 
//非递归 归并排序
void MergeSortNonR(int* a, int n);