#include <iostream>
#include <set>
using namespace std;

void TestSet()
{
    // 用数组array中的元素构造set
    int array[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4,
                   6, 8, 0};
    set<int> s(array, array + sizeof(array) / sizeof(array[0]));
    cout << s.size() << endl;

    // 正向打印set中的元素，从打印结果中可以看出:set可去重
    for (auto &e : s)
        cout << e << " ";
    cout << endl;

    // 使用迭代器逆向打印set中的元素
    for (auto it = s.rbegin(); it != s.rend(); ++it)
        cout << *it << " ";
    cout << endl;
    
    // set中值为3的元素出现了几次
    cout << s.count(3) << endl;
}

// int main()
// {
//     TestSet();
//     return 0;
// }