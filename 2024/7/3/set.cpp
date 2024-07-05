#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <class K>
void print_set(set<K> &s)
{
    set<int>::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

template <class V>
void insert_v(vector<V> &v)
{
    v.push_back(2);
    v.push_back(11);
    v.push_back(9);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(20);
    v.push_back(13);
    v.push_back(33);
    v.push_back(40);
    v.push_back(29);
    v.push_back(21);
    v.push_back(22);
    v.push_back(24);
    v.push_back(7);
    v.push_back(31);
}

void set_test1()
{
    set<int> s1;

    s1.insert(1);
    s1.insert(11);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);

    print_set(s1);
}

void set_test2()
{

    // 用vector插入set
    vector<int> v;
    insert_v(v);
    set<int> s2(v.begin(), v.end());
    print_set(s2);

    // 删除
    s2.erase(11);
    s2.erase(13);
    print_set(s2);

    // 查找
    auto pos = s2.find(2);
    if (pos != s2.end())
    {
        cout << *pos << " 已删除" << endl;
        s2.erase(pos);
    }
    else
        cout << "找不到" << endl;
}

// lower_bound && upper_bound
void set_test3()
{
    vector<int> v;
    insert_v(v);
    set<int> s2(v.begin(), v.end());
    print_set(s2);

    auto itlow = s2.lower_bound(20); // >=x
    auto itup = s2.upper_bound(30);  // > x

    // 删除区间
    //[20,30]
    s2.erase(itlow, itup); // 右边区间的值是大于30的,故删除的是‘30]’ -> [20,31)
    print_set(s2);
}

// multiset
// 排序不去重 允许冗余
void set_multiset()
{
    multiset<int> s1;
    s1.insert(1);
    s1.insert(11);
    s1.insert(11);
    s1.insert(3);
    s1.insert(4);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);
    multiset<int>::iterator it = s1.begin();
    while (it != s1.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

int main()
{
    // set_test3();

    set_multiset();

    return 0;
}