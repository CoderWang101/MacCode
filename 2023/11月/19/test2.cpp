#include <iostream>
using std::cout;
using std::endl;
using std::string;

namespace wzf1
{
    void ConstSring(const string &s)
    {
        // 遍历和读容器的数据,不能写
        string::const_iterator it = s.begin();
        while (it != s.end())
        {
            //*it +=1 ;
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }

    void ConstReverseString(const string &s)
    {
        // 遍历和读容器的数据,不能写
        string ::const_reverse_iterator rit = s.rbegin();
        while (rit != s.rend())
        {
            cout << *rit << " ";
            ++rit;
        }
        cout << endl;
    }

    void _main()
    {
        string s1("HelloWord");

        // 在string类内定义iterator(迭代器)类型
        string::iterator it = s1.begin();
        // 遍历数组
        while (it != s1.end()) // end()指向的是'/0'
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        // 反向遍历,反向迭代器
        string ::reverse_iterator rit = s1.rbegin();
        while (rit != s1.rend())
        {
            cout << *rit << " ";
            ++rit;
        }
        cout << endl;

        cout << "=======" << endl;

        ConstSring(s1);
        ConstReverseString(s1);
    }

}

namespace wzf2
{
    void _main1()
    {
        // insert/erase 不推荐经常使用
        // 应为他们可能存在要挪动数据,效率低下
        string s1("Word");
        s1.insert(0, "Hello");
        cout << s1 << endl;

        // s1.insert(5,1,' ');
        // s1.insert(5," ");
        s1.insert(s1.begin() + 5, ' ');
        cout << s1 << endl;

        string s2("Happy Every Day");
        cout << s2 << endl;
        // s2.erase(5,1);
        s2.erase(s2.begin() + 5);
        cout << s2 << endl;

        s2.erase(5, 3);
        cout << s2 << endl;

        // 当要删的长度大于原本长度,只会将指定位置后的所有字符进行删除
        s2.erase(5, 30);
        cout << s2 << endl;
    }

    void _main2()
    {
        string s1("How about the last days");
        string newStr;
        size_t num = 0;
        for (auto ch : s1)
        {
            if (ch == ' ')
                ++num;
        }
        newStr.reserve(s1.size() + 2 * num);

        for (auto ch : s1)
        {
            if (ch != ' ')
            {
                newStr += ch;
            }
            else
            {
                newStr += "%20";
            }
        }
        s1 = newStr;
        cout << newStr << endl;
    }

    void _main3()
    {
        string s1("Hello Word");

        cout<<s1<<endl;
        cout<<s1.c_str()<<endl;
    }
}

int main()
{
    wzf2::_main3();

    return 0;
}