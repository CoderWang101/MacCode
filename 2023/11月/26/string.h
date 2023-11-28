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
            _capacity = _size == 0 ? 3 : _size;
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

        // 赋值重载
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
        // 析构
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

        // 不改变数据的都建议加上const
        bool operator>(const string &s) const
        {
            return strcmp(_str, s._str) > 0;
        }

        bool operator==(const string &s) const
        {
            return strcmp(_str, s._str) == 0;
        }

        bool operator>=(const string &s) const
        {
            return *this > s || *this == s;
        }

        bool operator<(const string &s) const
        {
            return !(*this <= s);
        }
        bool operator<=(const string &s) const
        {
            return !(*this > s);
        }

        bool operator!=(const string &s) const
        {
            return !(*this == s);
        }

        string &operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }

        string &operator+=(const char *str)
        {
            append(str);
            return *this;
        }

        // 开空间
        void reserve(size_t n)
        {
            char *tmp = new char[n + 1]; //+1是为了存放"\0"
            strcpy(tmp, _str);           // 拷贝
            delete[] _str;               // 销毁_str空间
            _str = tmp;
            _capacity = n;
        }

        void push_back(char ch)
        {
            if (_size + 1 > _capacity)
            {
                reserve(_capacity * 2);
            }
            _str[_size] = ch; // 将字符插入
            ++_size;
            _str[_size] = '\0';
        }

        void append(const char *str)
        {
            size_t len = strlen(str); // 计算要插入字符的长度

            if (_size + len > _capacity)
            {
                reserve(_size + len);
            }

            strcpy(_str + _size, str); // _str 指针所指向的内存块中找到要插入字符串的位置(+_size)
            _size += len;
        }

        // 任意位置插入
        void insert(size_t pos, char ch)
        {
            assert(pos <= _size);
            if (_size + 1 > _capacity)
            {
                reserve(2 * _capacity);
            }
            size_t end = _size;
            while (end >= pos)
            {
                _str[end+1]=_str[end];
                --end;
            }
            _str[pos]=ch;
            ++_size;
        }

        void insert(size_t pos, const char *str)
        {
        }

        // 任意位置删除
        void erase(size_t pos, size_t len = npos)
        {
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

        static size_t npos;
    };
    size_t string::npos = -1;

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

    void test_string4()
    {
        string s1("Hello Word");
        string s2("Hello Word");
        string s3("Iello Word");

        cout << (s1 == s2) << endl;
        cout << (s1 >= s3) << endl;
        cout << (s1 <= s3) << endl;
        cout << (s1 != s3) << endl;
    }
    void test_string5()
    {
        string s1("HelloWord");
        s1.push_back(' ');
        s1.append("*******************");
        cout << s1.c_str() << endl
             << endl;

        string s2("HelloWord");
        s2 += ' ';
        s2 += "xxxxxxxxxx";

        cout << s2.c_str() << endl
             << endl;

        string s3;
        s3 += 'a';
        s3 += 'a';
        s3 += 'a';
        cout << s3.c_str() << endl;
    }
    void test_string5()
    {
        string s1("HelloWord");
        s1.insert(5, 'x');
        cout << s1.c_str() << endl;

    }
}