#include <iostream>
#include <assert.h>
using namespace std;

namespace wzf
{
    class Sort
    {
    public:
        // 冒泡排序
        void BubbleSort(int *a, int n)
        {
            for (size_t i = 0; i < n; ++i)
            {
                int exchange = 0;
                for (size_t j = 0; j < n - 1; ++j)
                {
                    if (a[i - 1] > a[i])
                    {
                        swap(a[i - 1], a[i]);
                        exchange = 1;
                    }
                }
                if (exchange == 0)
                    break;
            }
        }

        // 直接插入排序
        void InsertSort(int *a, int n)
        {
            for (size_t i = 0; i < n - 1; ++i)
            {
                int end = i;
                int tmp = a[end - 1];
                while (end >= 0)
                {
                    if (tmp < a[end])
                    {
                        a[end + 1] = a[end];
                    }
                    else
                        break;
                }
                a[end + 1] = tmp;
            }
        }

        void ShellSort(int *a, int n)
        {
            int gap = n;
            while (gap > 1)
            {
                gap = gap / 3 + 1; // gap/3:保证每次跳跃的间隔. +1：保证不为0

                // gap组交替进行排序
                /*
                gap越大大的数更快到后面,小的数可以更快到前面
                排升序,gap越小,越接近有序,当gap==1,就是插入排序
                */
                for (int i = 0; i < n - gap; i++) // 往前走一位,gap另一部分
                {
                    int end = i;
                    int tmp = a[end + gap];

                    while (end >= 0)
                    {
                        if (tmp < a[end])
                        {
                            // 排序
                            a[end + gap] = a[end];
                            end -= gap;
                        }
                        else
                            break;
                    }
                    a[end + gap] = tmp; // 交换元素值
                }
            }
        }

        int PartSort1(int *a, int begin, int end)
        {
            // 区间不存在，或者只有一个值则不需要再处理
            if (begin >= end)
                return 0; // 返回值类型应该是void，不需要返回具体的值

            int left = begin, right = end;
            int keyi = left; // 取begin作为基准元素的下标

            while (left < right)
            {
                // 右边先走，找小
                while (left < right && a[right] >= a[keyi])
                    --right;

                // 左边再走，找大
                while (left < right && a[left] <= a[keyi])
                    ++left;

                swap(a[left], a[right]); // 交换左右指针所指向的元素
            }
            swap(a[keyi], a[left]); // 将基准元素放到正确的位置上
            keyi = left;            // 更新基准元素的下标

            return keyi; // 返回基准元素的下标
        }

        void PrintArry(int *a, int n)
        {
            for (size_t i = 0; i < n; ++i)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }

        void TestShellSort()
        {
            int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 100, 546, 4874, 6546, 468, 54, 4586, 8, 5, 78945, 89, 465, 7, 486, 65, 658, 87, 456, 89, 5611, 48, 564, 56};
            int sz = sizeof(a) / sizeof(a[0]);

            ShellSort(a, sz);
            PrintArry(a, sz);
        }

        void TestPartSort1()
        {
            int a[] = {46,79,56,38,40,84};
            int sz = sizeof(a) / sizeof(a[0]);
            PartSort1(a,0,sz);
            PrintArry(a, sz);
        }
    };

}

int main()
{
    wzf::Sort sort;
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 1};
    size_t n = sizeof(a) / sizeof(a[0]);
    sort.BubbleSort(a, n);
    for (size_t i = 0; i < n-1; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    sort.TestShellSort();

    sort.TestPartSort1();

    return 0;
}