#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace wzf
{
    class string
    {
    private:
        char *_str;
        size_t _size;
        size_t _capacity;

        static size_t npos;

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

        string(const char *str = "")
            : _size(strlen(str))
        {
            _capacity = _size == 0 ? 3 : _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        // 拷贝构造
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

        const char *c_str()
        {
            return _str;
        }

        size_t size()
        {
            return _size;
        }

        size_t capacity()
        {
            return _capacity;
        }

        char &operator[](size_t pos)
        {
            return _str[pos];
        }

        const char &operator[](size_t pos) const
        {
            return _str[pos];
        }

        string &operator=(const string &s)
        {
            if (this != &s)
            {
                char *tmp = new char[s._capacity + 1];
                strcpy(tmp, s._str);
                delete _str;
                _str = tmp;
                _capacity = s._capacity;
                _size = s._size;
            }
            return *this;
        }

        bool operator<(const string &s) const
        {
            return strcmp(_str, s._str) < 0;
        }
        bool operator==(const string &s) const
        {
            return strcmp(_str, s._str) == 0;
        }
        bool operator<=(const string &s) const
        {
            return *this < s || *this == s;
        }
        bool operator>(const string &s) const
        {
            return !(*this <= s);
        }
        bool operator>=(const string &s) const
        {
            return !(*this < s);
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

        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char *tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }

        string &insert(size_t pos, char ch)
        {
            assert(pos <= _size);

            // 检查空间是否足够
            if (_size + 1 > _capacity)
            {
                reserve(2 * _capacity);
            }

            // 挪动数据
            size_t end = _size + 1;
            while (pos < end)
            {
                _str[end] = _str[end - 1];
                end--;
            }

            // 赋值
            _str[pos] = ch;
            ++_size;

            return *this;
        }

        string &insert(size_t pos, const char *str)
        {
            assert(pos <= _size);
            size_t len = strlen(str);

            if (_size + len > _capacity)
            {
                reserve(_size + len);
            }

            // 挪数据
            size_t end = _size + len;
            while (end > pos + len - 1)
            {
                _str[end - len] = _str[end];
                --end;
            }
            // 拷贝字符串
            strncpy(_str + pos, str, end);
            _size += len;

            return *this;
        }

        void push_back(char ch)
        {
            insert(_size, ch);
        }

        void append(const char *str)
        {
            insert(_size, str);
        }

        string &erase(size_t pos, size_t len = npos)
        {
            assert(pos < _size);

            if (pos == len || pos + len >= _size)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                strcpy(_str + pos, _str + pos + len);
                _size -= len;
            }

            return *this;
        }

        void resize(size_t n, char ch = '\0')
        {
            if (n < _size)
            {
                // 删除数据 -- 保留前n个
                _size = n;
                _str[_size] = '\0';
            }
            else if (n > _size) // n=_size不处理
            {
                if (n > _capacity)
                {
                    reserve(n);
                }

                size_t i = _size;
                while (i < n) // 从size位置开始填字符
                {
                    _str[i] = ch;
                    ++i;
                }
                _size = n;
                _str[_size] = '\0';
            }
        }


        // 交换
        void swap(string &s)
        {
            std::swap(_str, s._str);
            std::swap(_capacity, s._capacity);
            std::swap(_size, s._size);
        }
    };

    static size_t npos = -1;

    void test_string1()
    {
        string s1("abcdef");
        cout << s1.c_str() << endl;

        string s2("efg");
        string s3 = s1;
        cout << s2.c_str() << endl;
        cout << s3.c_str() << endl;
        // cout<<(s1>s2)<<endl;
        // cout<<(s1>=s2)<<endl;
        // cout<<(s1<s2)<<endl;
        //  cout<<(s1!=s2)<<endl;
        // cout<<(s1<=s3)<<endl;
        // cout<<(s1>s3)<<endl;
        // cout<<(s1>=s3)<<endl;
        // cout<<(s1!=s3)<<endl;
        // cout<<(s1==s3)<<endl;
    }
    void test_string2()
    {
        string s1("abcdef");
        cout << s1.c_str() << endl;

        s1.push_back('!');
        cout << s1.c_str() << endl;
        s1.append("ABCDEF!");
        cout << s1.c_str() << endl;
        s1 += '2';
        cout << s1.c_str() << endl;
        s1 += "Hello!";
        cout << s1.c_str() << endl;
        s1.erase(2, 5);
        cout << s1.c_str() << endl;
        s1.erase(3, 100);
        cout << s1.c_str() << endl;
    }

    void test_string3()
    {
        string s1("abcdef");
        cout << s1.c_str() << endl;
        s1.resize(7,'x');
        cout << s1.c_str() << endl;
        string s2;
        s2.resize(10,'x');
        cout << s2.c_str() << endl;


    }

}
