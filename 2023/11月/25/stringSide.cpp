#include <iostream>
#include <string>
using namespace std;

// for (size_t i = 0; i < s2.size(); i++)
// {
//     cout<<s2[i]<<" ";
// }
// cout<<endl;

namespace Example
{
    void test1()
    {
        string s1;
        string s2("HelloWord");

        string s3 = "HappyEveryDay";
        string s4(s3, 5, 3);
        string s5(s3, 5, 20);
        string s6(s3, 5);

        string s7("HelloWorld", 5);

        string s8(5, '*');

        // cout << s4 << endl;
        // cout << s5 << endl;
        // cout << s6 << endl;
        // cout << s7 << endl;
        cout << s8 << endl;
    }

    void test2()
    {
        string s1("HelloWord");
        cout << s1.size() << endl;   // 9
        cout << s1.length() << endl; // 9

        cout << s1.capacity() << endl;
    }

    void test3()
    {
        // string s1("Hello");
        // s1.push_back(' ');
        // s1.push_back('!');
        // cout << s1 << endl;

        string s2("Hello");
        s2.append("Word");
        cout << s2 << endl;

        s2 += ' ';
        s2 += "!!!";
        cout << s2 << endl;
    }

    void test4()
    {
        // 观察扩容情况
        string s;

        s.reserve(100); // 提前开辟空间

        size_t sz = s.capacity();
        cout << "making s grow:\n";
        for (int i = 0; i < 100; ++i)
        {
            s.push_back('c');
            if (sz != s.capacity())
            {
                sz = s.capacity();
                cout << "capacity changed:" << sz << '\n';
            }
        }
    }

    void test5()
    {
        // string s1("HelloWord");
        // s1.reserve(100);
        // cout << s1.size() << endl;
        // cout << s1.capacity() << endl;

        cout << endl;

        string s2("HelloWord");
        s2.resize(100, 'x');
        cout << s2.size() << endl;
        cout << s2.capacity() << endl;

        cout << endl;

        // 比size小，删除数据，保留前5个
        s2.resize(5);
        cout << s2.size() << endl;
        cout << s2.capacity() << endl;
    }

    void test6()
    {
        string s1("Hello Word");
        string::iterator it=s1.begin();
        while (it!=s1.end())
        {
            cout<<*it<<" ";
            ++it;
        }
        cout<<endl;

        // for(auto ch: s1)
        // {
        //     cout<<ch<<" ";
        // }
        // cout<<endl;
    }
}

int main()
{
    Example::test6();

    return 0;
}