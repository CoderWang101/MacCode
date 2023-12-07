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

        size_t capcacity() const
        {
            return _capacity;
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

        // 缩容
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

        // 开空间
        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char *tmp = new char[n + 1]; //+1是为了存放"\0"
                strcpy(tmp, _str);           // 拷贝
                delete[] _str;               // 销毁_str空间
                _str = tmp;
                _capacity = n;
            }
        }

        void push_back(char ch)
        {
            // if (_size + 1 > _capacity)
            // {
            //     reserve(_capacity * 2);
            // }
            // _str[_size] = ch; // 将字符插入
            // ++_size;
            // _str[_size] = '\0';
            insert(_size, ch);
        }

        void append(const char *str)
        {
            // size_t len = strlen(str); // 计算要插入字符的长度

            // if (_size + len > _capacity)
            // {
            //     reserve(_size + len);
            // }

            // strcpy(_str + _size, str); // _str 指针所指向的内存块中找到要插入字符串的位置(+_size)
            // _size += len;

            insert(_size, str);
        }

        // 任意位置插入
        string &insert(size_t pos, char ch) // 与void &insert(size_t pos, char ch)效果差不多，string& 可用于获取对象
        {
            assert(pos <= _size);
            if (_size + 1 > _capacity)
            {
                reserve(2 * _capacity);
            }
            size_t end = _size + 1; // 防止size_t end=-1->整形最大值
            while (end > pos)
            {
                _str[end] = _str[end - 1];
                --end;
            }
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

            // 挪动数据

            // 方法一
            size_t end = _size + len;
            while (end > pos + len - 1)
            {
                _str[end - len] = _str[end];
                --end;
            }
            /*
            //方法二
            size_t n=_size+1;
            size_t end=_size;
            for (size_t i = 0; i < n; ++i)
            {
                _str[end+len]=_str[end];
                --end;
            }
            */
            // 拷贝插入
            strncpy(_str + pos, str, end);
            _size += len;

            return *this;
        }

        // 任意位置删除
        string &erase(size_t pos, size_t len = npos)
        {
            assert(pos < _size);
            if (len == npos || pos + len >= _size)
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

        size_t find(char ch, size_t pos = 0)
        {
            assert(pos < _size);

            for (size_t i = pos; i < _size; ++i)
            {
                if (_str[i] == ch)
                {
                    return i;
                }
            }
            return npos;
        }

        size_t find(const char *str, size_t pos = 0)
        {
            assert(pos < _size);

            char *p = strstr(_str + pos, str);
            if (p == nullptr)
            {
                return npos;
            }
            else
            {
                return p - _str;
            }
        }

        // 交换
        void swap(string &s)
        {
            std::swap(_str, s._str);
            std::swap(_capacity, s._capacity);
            std::swap(_size, s._size);
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

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

    private:
        char *_str;
        size_t _size;
        size_t _capacity;

        static size_t npos;
    };

    size_t string::npos = -1;

    // 流插入
    ostream &operator<<(ostream &out, const string &s)
    {
        for (size_t i = 0; i < s.size(); ++i)
        {
            out << s[i];
        }
        return out;
    }

    // 流提取
    istream &operator>>(istream &in, string &s)
    {
        s.clear();
        char ch = in.get(); // 获取一个字符
        char buff[128];
        size_t i = 0;

        while (ch != ' ' && ch != '\n')
        {
            buff[i++] = ch;
            if (i == 127) // 若已存满
            {
                buff[127] = '\0';
                s += buff;
                i = 0; // 再次从buff[0]开始
            }

            ch = in.get();
        }

        if (i != 0) // 防止循环结束还有数据没有进行增加
        {
            buff[i] = ch;
            buff[i + 1] = '\0';
            s += buff;
        }

        return in;
    }

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
    void test_string6()
    {
        string s1("HelloWord");
        s1.insert(5, 'x');
        cout << s1.c_str() << endl;
    }
    void test_string7()
    {
        string s1;
        s1.resize(20, 'x');
        cout << s1.c_str() << endl;

        s1.resize(30, 'y');
        cout << s1.c_str() << endl;

        s1.resize(10);
        cout << s1.c_str() << endl;
    }
    void test_string8()
    {
        string s1("0123456789");

        cout << s1.c_str() << endl;

        s1.erase(2, 3);
        cout << s1.c_str() << endl;

        s1.erase(4, 30);
        cout << s1.c_str() << endl;
        s1.erase(2);
        cout << s1.c_str() << endl;
    }
    void test_string9()
    {
        string s1("0123456789");
        cout << s1.c_str() << endl;
        cout << s1 << endl;

        cin >> s1;
        cout << s1 << endl;
        
    }
}


int main()
{
    try // char* tmp = new char[s._capacity + 1];是否开辟异常
    {
        wzf::test_string9();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}