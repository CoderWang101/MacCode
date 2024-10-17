/*
构造哈希表
给定一个关键字序列(19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79)，假设表长15，选取哈希函数Hash(𝑘𝑒𝑦)=(𝑘𝑒𝑦) % 13。用开放定址法处理冲突
Hash′(𝑘𝑒𝑦)=(Hash(𝑘𝑒𝑦)+𝑑_𝑖) % 𝑚， 𝑑_𝑖=𝑖((7∗𝑘𝑒𝑦)  𝑚𝑜𝑑 10+1)(𝑖=1,2,3,…)
写出构造后的哈希表。
*/
#include <iostream>
#include <vector>

using namespace std;

// 哈希表的大小
const int TABLE_SIZE = 1;

// 哈希函数，使用线性组合进行哈希映射
int hash_function(int key)
{
    return (3 * key) % TABLE_SIZE; // 返回映射到哈希表的索引
}

// 探测函数，使用线性探测的方法来解决冲突
int probe_function(int key, int i)
{
    return i * ((7 * key) % 10 + 1); // 返回新的探测偏移量
}

// 向哈希表中插入一个键
void insert_key(vector<int> &hash_table, int key)
{
    int index = hash_function(key); // 首先计算出键的哈希索引
    // 如果该索引为空，则直接插入
    if (hash_table[index] == -1)
    {
        hash_table[index] = key;
    }
    else // 如果该索引已被占用，则进行冲突处理
    {
        for (int i = 1;; ++i) // 进行线性探测查找下一个空位
        {
            int new_index = (index + probe_function(key, i)) % TABLE_SIZE; // 计算新的索引
            if (hash_table[new_index] == -1)                               // 找到空位
            {
                hash_table[new_index] = key; // 插入键
                break;                       // 结束循环
            }
        }
    }
}

// 打印哈希表的内容
void print_hash_table(const vector<int> &hash_table)
{
    for (int i = 0; i < TABLE_SIZE; ++i) // 遍历哈希表
    {
        if (hash_table[i] != -1)
        {
            cout << "Index " << i << ": " << hash_table[i] << endl; // 输出索引和存储的键
        }
        else
        {
            cout << "Index " << i << ": -" << endl; // 输出为空的索引
        }
    }
}

int main()
{
    vector<int> hash_table(TABLE_SIZE, -1); // 初始化哈希表，所有位置设置为-1（表示空）

    // 待插入的数组
    int arr[] = {19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79};
    int sz = sizeof(arr) / sizeof(arr[0]); // 计算数组的大小

    // 创建一个与 arr 大小相同的 keys 向量并填充数据
    vector<int> keys(sz, 0); // 初始化一个大小为 sz 的向量
    for (int i = 0; i < sz; i++)
        keys[i] = arr[i]; // 将数组 arr 的值复制到 keys 中

    // 将 keys 中的每个键插入哈希表
    for (int key : keys)
        insert_key(hash_table, key);

    // 打印最终的哈希表
    print_hash_table(hash_table);

    return 0; // 程序结束
}