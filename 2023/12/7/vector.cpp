#include <iostream>
#include <vector>
using namespace std;

/*

*/
void test_vector1()
{
    // 定义一个vector
    vector<int> v;
    // 向vector中添加元素
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
    // 定义一个vector，元素个数为10，元素值为1
    vector<int> v1(10, 1);

    for (size_t i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
}

void test_vector3()
{
    // 定义一个vector
    vector<int> v;
    // 向vector中添加元素
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // 反向迭代器
    vector<int>::reverse_iterator reit = v.rbegin();
    while (reit != v.rend())
    {
        cout << *reit << " ";
        ++reit;
    }
    cout << endl;
}
// void TestVectorExpand()
// {
//     size_t sz;
//     vector<int> v;
//     sz=v.capacity();
//     cout<<"making v grow:"<<endl;
//     for (int i = 0; i < 100; ++i)
//     {
//         v.pop_back();
//         if (sz!=v.capacity())
//         {
//             sz=v.capacity();
//             cout<<"capacity changed:"<<sz<<endl;
//         }
        
//     }
    

// }


void test_vector4()
{
    //两个中还是v1开空间的方法更好用
    vector<int> v1;
    v1.resize(10,0);

    vector<int> v2(10,0);
}

void test_vector5()
{
    vector<int>::iterator it;
    cout << "vector<int>::iterator it" << endl;

}

int main()
{
    // test_vector1();
    //TestVectorExpand();
    test_vector5();
    
    return 0;
}