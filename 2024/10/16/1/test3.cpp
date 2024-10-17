#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 获取数组中最大的数
int getMax(vector<int> &arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// 对数组按照第 exp 位进行计数排序
void countSort(vector<int> &arr, int exp)
{
    vector<int> output(arr.size()); // 输出数组
    vector<int> count(10, 0);       // 计数数组，长度为10（因为每一位的数字范围是0-9）

    // 统计每个数字出现的次数
    for (int i = 0; i < arr.size(); i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // 计算累积次数
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // 构建输出数组
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将输出数组复制回原数组
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = output[i];
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 基数排序
void radixSort(vector<int> &arr)
{
    int max = getMax(arr);

    // 对每一位进行计数排序
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, exp);
    }
}

// 打印数组
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int a[] = {100, 50, 11, 23, 14, 3, 99, 28, 61, 78, 82, 45};
    int sz = sizeof(a) / sizeof(a[0]); // 计算数组的大小

    // 创建一个与 arr 大小相同的 keys 向量并填充数据
    vector<int> arr(sz, 0); // 初始化一个大小为 sz 的向量
    for (int i = 0; i < sz; i++)
        arr[i] = a[i]; // 将数组 arr 的值复制到 keys 中
    cout << "排序前: ";
    printArray(arr);

    radixSort(arr);

    cout << "排序后: ";
    printArray(arr);

    return 0;
}