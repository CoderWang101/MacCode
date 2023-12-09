#include <iostream>
#include <vector>
using namespace std;

/*

*/
void test_vector1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // 下标访问
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // 用迭代器去访问
    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    // for(auto e:v)
    // {
    //     cout<<e<<" ";
    // }
    // cout << endl;

    // 拷贝
    vector<int> v2(v);
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void test_vector2()
{
    vector<int> v1(10, 1);

    for (size_t i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
}

int main()
{
    test_vector2();

    return 0;
}