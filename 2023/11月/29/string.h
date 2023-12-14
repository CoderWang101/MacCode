#pragma once
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

namespace wzf
{
    class string
    {
    private:
        char *_str;
        int _size;
        int _capacity;

    public:
        typedef char *iterator;
        typedef const char *const_iterator;
        // 迭代器
        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _size + _str;
        }

        iterator begin() const
        {
            return _str;
        }

        iterator end() const
        {
            return _size + _str;
        }

        string(const char *str = "")
            : _size(strlen(str))
        {
            _capacity = _size == 0 ? 3 : _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        // 深拷贝
        string(const string &s)
            : _size(s._size), _capacity(s._capacity)
        {
            _str = new char[_capacity + 1];
            strcpy(_str, s._str);
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _capacity = _size = 0;
        }

        string &operator=(const string &s) //// string&为返回类型
        {
            if (this != &s)
            {
                char *tmp = new char[_capacity + 1];
                strcpy(tmp, s._str);
                delete[] _str;
                _str = tmp;
                _capacity = s._capacity;
                _size = s._size;
            }
            return *this; // s1
        }

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
            return !(*this >= s);
        }

        bool operator<=(const string &s) const
        {
            return !(*this > s);
        }

        bool operator!=(const string &s) const
        {
            return !(*this == s);
        }

        //[]
        char &operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }

        const char &operator[](size_t pos) const
        {
            assert(pos < _size);
            return _str[pos];
        }

        string &operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }

        string &operator+=(const char *ch)
        {
            append(ch);
            return *this;
        }

        void reserve(size_t n)
        {
            char *tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }

        void push_back(char ch)
        {
            if (_size + 1 > _capacity)
            {
                reserve(_capacity * 2);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }

        void append(const char *str)
        {
            size_t len = strlen(str);
            if (_size + len > _capacity)
            {
                reserve(_size + len + 1);
            }
            strcpy(_size + _str, str);
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
                _str[end + 1] = _str[end];
                --end;
            }
            _str[pos] = ch;
            ++_size;
        }

        void insert(size_t pos, const char *str)
        {
            assert(pos <= _size);

            size_t len = strlen(str);
            if (_size + len + 1 > _capacity)
            {
                reserve(_size + len + 1);
            }

            if (pos == _size)
            {
                // 直接将字符串接在旧字符串后面
                memcpy(_str + _size, str, len + 1);
            }
            else
            {
                // 将旧字符串后移，腾出插入新字符串的空间
                size_t end = _size + len;
                size_t pre = _size;
                while (pre >= pos) 
                {
                    _str[end] = _str[pre];
                    --end;
                    --pre;
                }

                // 插入新字符串
                size_t sz = pos;
                while (len > 0)
                {
                    _str[sz] = *str;
                    ++str;
                    ++sz;
                    --len;
                }
            }
            _size += strlen(str);
        }

        const char *c_str() const
        {
            return _str;
        }

        size_t size()
        {
            return _size;
        }
    };

    void TestString()
    {
        string s1("HelloWord");
        cout << s1.c_str() << endl;
        string s2 = "HelloWord";
        cout << s2.c_str() << endl;
        s2[5]++;
        cout << s2.c_str() << endl;

        string s3 = s2;
        cout << s3.c_str() << endl;

        cout << (s3 > s2) << endl;
        cout << (s3 >= s2) << endl;
        cout << (s3 <= s1) << endl;
        cout << (s3 == s1) << endl;
        cout << (s3 != s1) << endl;

        s3.push_back('1');
        cout << s3.c_str() << endl;

        s3.append("23456");
        cout << s3.c_str() << endl;

        s3 += 'H';
        s3 += "appyEveryDay";
        cout << s3.c_str() << endl;

        s3.insert(5, '!');
        cout << s3.c_str() << endl;

        s3.insert(5, "!!!!!");
        cout << s3.c_str() << endl;
    }

}