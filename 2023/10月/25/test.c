#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct  Heap
{
    HPDataType* a;//创建数组
    int size;//目前存储数量
    int capacity;//最大容量
}HP;

// //初始化
// void HeapInit(HP* php);

// //交换
// void Swap(HPDataType* p1, HPDataType* p2);

// //打印
// void HeapPrint(HP* php);

// //销毁
// void HeapDestory(HP* php);

// //插入
// void HeapPush(HP* php,HPDataType x);

// //删除
// void HeapPop(HP* php);

// //向下调整
// void AdjustDown(HPDataType* a,int size, int parent);

// //取堆顶元素
// HPDataType  HeapTop(HP* php);

// //empty
// bool HeapEmpty(HP* php);

// //元素个数
//int HeapSize(HP* php);

//------------------------------------

 
//初始化
void HeapInit(HP* php)
{
	assert(php);
 
	php->a = NULL;
	php->size = php->capacity = 0;
}
 
//打印
void HeapPrint(HP* php)
{
	assert(php);
	for (int i = 0;i < php->size;i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}
 
//销毁
void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
 
//交换两数组元素之间的值
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
 
//向上调整
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
 
	//孩子被调到顶是结束(即数组首元素)
	while (child > 0)
	{
		if (a[child]<a[parent])  //小堆
		{
			//孩子 小于/小于 父亲
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			//孩子 大于/小于 父亲
			break;
		}
	}
}
 
//插入
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	//扩容
	if (php->size == php->capacity)
	{
		//判断capacity是否为0，并进行赋值
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = realloc(php->a, sizeof(HPDataType) * newcapacity);
 
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
 
	//	   当前数组  插入数值的位置
	AdjustUp(php->a, php->size - 1);
 
}
 
//向下调整
void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//选出左右孩子中 小/大 的那个
		if (child+1<size && a[child + 1] < a[child])
		{
			++child;
		}
 
		//跟孩子父亲比较
		if (a[child]<a[parent])
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
 
//删除
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
 
	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	php->size--;
 
	//向下调整
	AdjustDown(php->a, php->size, 0);
}
 
//取堆顶的元素
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
 
	return php->a[0];
}
 
//判断是否为空
bool HeapEmpty(HP* php)
{
	assert(php);
 
	return php->size == 0;
}
 
//计算该二叉树元素个数
int HeapSize(HP* php)
{
	assert(php);
 
	return php->size;
}

int main()
{
    HP* hp;
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int sz=sizeof(a)/sizeof(a[0]);
    HeapAdjust(a,sz);
    HeapPrint(a);

    return 0;
}