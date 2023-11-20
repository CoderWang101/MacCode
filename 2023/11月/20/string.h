#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

namespace wzf
{
    class string
    {
    public:
        // string()
        //     : _str(new char[1]), _size(0), _capacity(0)
        // {
        //     _str[0] = '\0'; // 没有内容时依旧有‘\0’
        // }
        // // r,string应该是遇到'\0'停止否则会崩

        // string(const char *str)
        //     : _size(strlen(str))
        // {
        //     _capacity = _size;
        //     _str = new char[_capacity + 1]; //+1-> '\0'
        //     strcpy(_str, str);
        // }

        // 将string()与string(const)进行复用
        // const char *str≠nulptr,string应该是遇到'\0'停止否则会崩

        // 默认参数值是 '\0'，即空字符。然而，由于 str 是 const char* 类型，而不是 char 类型，因此在这种情况下，
        //'\0' 被解释为一个整数 0，而不是一个空字符。这可能导致编译错误或未定义行为。
        // string(const char *str="/0")// ≠‘\0’

        /*
        一个空字符串也是一个有效的字符串，它不需要以 '\0' 的形式进行显式表示，也就是说，一个空字符串已经包含了一个空字符。
        因此，当我们在下面的类构造函数中将空字符串 "" 传递给 const char* 类型的形参 str 时，
        编译器会自动将其转换为一个空字符 '\0'。
        */
        string(const char *str = "") // 可以不写 "\0"
            : _size(strlen(str))
        {
            _capacity = _size;
            _str = new char[_capacity + 1]; //+1-> '\0'
            strcpy(_str, str);
        }

        // 深拷贝 s3
        string(const string &s)
            : _size(s._size), _capacity(s._capacity)
        {
            _str = new char[s._capacity + 1];
            strcpy(_str, s._str);
        }

        string &operator=(const string &s) // string&为返回类型
        {
            if (this != &s) // s1≠s1
            {
                // delete[] _str;//销毁原来空间,防止s1空间小于s2,或s1>s2造成空间浪费
                // _size = s._size;
                // _capacity = s._capacity;
                // _str = new char[s._capacity + 1];

                // assert(_str != nullptr); // 判断是否开辟成功
                // strcpy(_str, s._str);
                char *tmp = new char[s._capacity + 1];
                strcpy(tmp, s._str);
                delete[] _str; // 销毁原来空间,防止s1空间小于s2,或s1>s2造成空间浪费
                _str = tmp;
                _size = s._size;
                _capacity = s._capacity;
            }

            return *this; // s1
        }
        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        const char *c_str()
        {
            return _str;
        }

        size_t size() const
        {
            return _size;
        }

        char &operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }

    private:
        char *_str;
        size_t _size;
        size_t _capacity;
    };

    void test_string1()
    {
        string s1;
        string s2("HelloWord");

        cout << s1.c_str() << endl;
        cout << s2.c_str() << endl;

        s2[0]++;
        cout << s1.c_str() << endl;
        cout << s2.c_str() << endl;
    }
    void test_string2()
    {
        string s1;
        string s2("Hello Word");
        /*
        string s3(s2); // 拷贝构造(浅拷贝/值拷贝) 用系统自动生成的拷贝构造
        1.两个用的是同一个空间. 2.会析构两次
        */
        // 深拷贝:
        string s3(s2);

        cout << s2.c_str() << endl;
        cout << s3.c_str() << endl;
        s2[0]++;
        cout << s2.c_str() << endl;
        cout << s3.c_str() << endl;
        cout << "===" << endl;

        s1 = s3; // 调用 s1 的 operator= 函数，将 s2 赋值给 s1
        cout << s3.c_str() << endl;
        cout << s1.c_str() << endl;
    }

    void test_string3()
    {
        string s1("Hello Word");
        for (size_t i = 0; i < s1.size(); i++)
        {
            s1[i]++;
        }
        cout << endl;
        for (size_t i = 0; i < s1.size(); i++)
        {
            cout << s1[i] << "";
        }
        cout << endl;
    }
}