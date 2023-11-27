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
    // for(auto ch: s1)
    // {
    //     cout<<ch<<" ";
    // }
    // cout<<endl;
    void test6()
    {
        string s1("Hello Word");
        string::iterator it = s1.begin();
        while (it != s1.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        string s3("Hello Word");
        string::const_iterator cit = s3.begin();
        while (cit != s3.end())
        {
            cout << *cit << " ";
            ++cit;
        }
        cout << endl;

        // 反向迭代
        string::reverse_iterator rit = s1.rbegin();
        while (rit != s1.rend())
        {
            cout << *rit << " ";
            ++rit;
        }
        cout << endl;

        string::const_reverse_iterator crit = s1.rbegin(); // auto crit=s.rbegin();
        while (crit != s1.rend())
        {
            cout << *crit << " ";
            ++crit;
        }
        cout << endl;
    }

    void test7()
    {
        string s1("Word");
        s1.insert(0, "Hello");
        cout << s1 << endl;

        s1.insert(5, "1");
        cout << s1 << endl;

        s1.insert(s1.begin() + 5, ' ');
        cout << s1 << endl;
    }

    void test8()
    {
        string s1("Hello Word");
        s1.erase(5, 1);
        cout << s1 << endl;

        s1.erase(s1.begin() + 5);
        cout << s1 << endl;

        s1.erase(s1.begin() + 5, s1.begin() + 7);
        cout << s1 << endl;
    }

    void test9()
    {
        cout << endl;

        string s1("Hello Word i love you");

        size_t num = 0;
        for (size_t i = 0; i < s1.size(); ++i)
        {
            if (s1[i] == ' ')
                ++num;
        }
        // 提前开空间，减少开辟次数，提高效率,避免replace
        s1.reserve(s1.size() + 2 * num);

        size_t pos = s1.find(' '); // 找到第一个并范围下标，若没找到返回-1
        while (pos != string::npos)
        {
            s1.replace(pos, 1, "%20");   // 从pos位置后的一个字符替换为%20
            pos = s1.find(' ', pos + 3); // 从pos+3位置向后找' ',
        }
        cout << s1 << endl;

        cout << endl;

        string s2("Hello Word i love you");
        string newStr;

        size_t num2 = 0;
        for (size_t i = 0; i < s1.size(); ++i)
        {
            if (s1[i] == ' ')
                ++num2;
        }
        s1.reserve(s1.size() + 2 * num2);

        for (size_t i = 0; i < s2.size(); ++i)
        {
            if (s2[i] != ' ')
                newStr += s2[i];
            else
                newStr += "%20";
        }
        s2 = newStr;
        cout << s2 << endl;
    }

    void test10()
    {
        // string::swap
        string s1("HelloWord");
        string s2("***********");
        cout << s1 << endl
             << s2 << endl;

        s1.swap(s2);
        cout << endl
             << s1 << endl
             << s2 << endl;

        // std::swap
        swap(s1, s2);
        cout << endl
             << s1 << endl
             << s2 << endl;
    }
    void test11()
    {
        string s1("Hello Word");
        cout << (void *)s1.c_str() << endl;

        s1 += '\0';
        s1 += '\0';
        s1 += "xxxxxxx";

        cout << s1 << endl
             << s1.c_str() << endl;
    }

    void test12()
    {
        string file("string.cpp.txt.exe");
        size_t pos = file.rfind('.');

        if (pos != string::npos)
        {
            string suffix = file.substr(pos, file.size() - pos);//substr:提取从位置 poa 开始的前 file.size()-pos 个字符
            cout<<suffix<<endl;//.exe
        }
    }
}

int main()
{
    Example::test12();

    return 0;
}