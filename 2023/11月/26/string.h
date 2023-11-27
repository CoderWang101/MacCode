#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

namespace wzf
{
    class string
    {
    public:
        typedef char *iterator;
        typedef const char *const_iterator;
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }

        const_iterator begin() const
        {
            return _str;
        }
        const_iterator end() const
        {
            return _str + _size;
        }

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

        // 给const对象调用
        const char &operator[](size_t pos) const
        {
            assert(pos < _size);
            return _str[pos];
        }
        // 给普通对象,构成函数重载
        char &operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }

        void Print(const string &s)
        {
            for (size_t i = 0; i < s.size(); i++)
            {
                cout << s[i] << " ";
            }
            cout << endl;

            const_iterator rit = s.begin();
            while (rit != s.end())
            {
                cout << *rit << " ";
                ++rit;
            }
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
            cout << s1[i] << " ";
        }
        cout << endl;

        // Print(s1);

        string::iterator it = s1.begin();
        while (it != s1.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
}