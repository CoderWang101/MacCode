// 3
#include <iostream>
#include <vector>

using namespace std;

// 对指定子序列进行直接插入排序
void insertionSort(vector<int> &arr, int start, int gap)
{
    for (int i = start; i < arr.size(); i += gap)
    {
        int temp = arr[i];
        int j;
        for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
        {
            arr[j] = arr[j - gap];
        }
        arr[j] = temp;
    }
}

// 希尔排序函数
void shellSort(vector<int> &arr)
{
    int n = arr.size();

    // 初始增量
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // 对每个子序列进行直接插入排序
        for (int start = 0; start < gap; ++start)
        {
            insertionSort(arr, start, gap);
        }

        // 输出当前轮次的排序结果
        cout << "当前增量 gap = " << gap << " 时的排序结果: ";
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // 待插入的数组
    int a[] = {44, 5, 38, 3, 15, 47, 26, 2, 48, 19, 50, 48};
    int sz = sizeof(a) / sizeof(a[0]); // 计算数组的大小

    // 创建一个与 arr 大小相同的 keys 向量并填充数据
    vector<int> arr(sz, 0); // 初始化一个大小为 sz 的向量
    for (int i = 0; i < sz; i++)
        arr[i] = a[i]; // 将数组 arr 的值复制到 keys 中

    cout << "初始序列: ";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 调用希尔排序
    shellSort(arr);

    cout << "最终排序结果: ";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
初始序列: 44 5 38 3 15 47 26 2 48 19 50 48
当前增量 gap = 6 时的排序结果: 26 2 38 3 15 47 44 5 48 19 50 48
当前增量 gap = 3 时的排序结果: 3 2 38 19 5 47 26 15 48 44 50 48
当前增量 gap = 1 时的排序结果: 2 3 5 15 19 26 38 44 47 48 48 50
最终排序结果: 2 3 5 15 19 26 38 44 47 48 48 50
*/

