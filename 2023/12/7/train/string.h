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

        const_iterator begin() const
        {
            return _str;
        }
        const_iterator end() const
        {
            return _str + _size;
        }

        string(const char *str = "")
            : _size(strlen(str))
        {
            _capacity = _size = 0 ? 3 : _size;
            _str = new char[_size + 1];
            strcpy(_str, str);
        }

        // 拷贝
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

        string &operator=(const string &s)
        {
            if (this != &s)
            {
                char *tmp = new char[s._capacity + 1];
                strcpy(tmp, s._str);
                delete[] _str;
                _str = tmp;
                _size = s._size;
                _capacity = s._capacity;
            }
            return *this;
        }

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

        bool operator<(string &s) const
        {
            return strcmp(_str, s._str) < 0;
        }
        bool operator==(string &s) const
        {
            return strcmp(_str, s._str) == 0;
        }
        bool operator<=(string &s) const
        {
            return *this < s || *this == s;
        }
        bool operator>(string &s) const
        {
            return !(*this <= s);
        }
        bool operator>=(string &s) const
        {
            return !(*this < s);
        }
        bool operator!=(string &s) const
        {
            return !(*this == s);
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
            // 判断大小
            if (_size + 1 > _capacity)
            {
                reserve(2 * _capacity);
            }
            size_t end = _size + 1;

            while (end > pos)
            {
                _str[end] = _str[end + 1];
                end--;
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
            size_t end = _size + len;
            while (end > pos + len - 1)
            {
                _str[end - len] = _str[end];
                --end;
            }
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

        string &erase(size_t pos, size_t len = npos)
        {
            assert(pos < _size);
            if (len == npos || len >= _size)
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
                _size = n;
                _str[_size] = '\0';
            }
            else if (n > _size)
            {
                if (n > _capacity)
                {
                    reserve(n);
                }
                size_t i = _size;
                while (i < n)
                {
                    _str[i] = ch;
                    ++i;
                }
                _size = n;
                _size = '\0';
            }
        }

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

        const char *c_str()
        {
            return _str;
        }
        //?
        size_t size() const // const?
        {
            return _size;
        }
        size_t capacity() const
        {
            return _capacity;
        }
    };
    size_t string::npos = -1;

    ostream &operator<<(ostream &out, const string &s)
    {
        for (size_t i = 0; i < s.size(); ++i)
        {
            out << s[i];
        }
        return out;
    }

    istream &operator>>(istream &in, string &s)
    {
        s.clear();
        char ch = in.get();
        char buff[128];
        size_t i = 0;

        while (ch != ' ' && ch != '\n')
        {
            buff[i++] = ch;
            if (i == 127)
            {
                buff[127] = '\0';
                s += buff;
                i = 0;
            }
            ch = in.get();
        }

        if (i != 0)
        {
            buff[i] = ch;
            buff[i + 1] = '\0';
            s += buff;
        }
        return in;
    }

    void TestString1()
    {
        string s1("Hello");
        cout << s1.c_str() << endl;
        string s2 = s1;
        string s3(s1);
        cout << s3.c_str() << endl;
        s1[0]++;
        cout << s1.c_str() << endl;
    }
    void TestString2()
    {
        string s1("Hello");
        cout << s1.c_str() << endl;
        string s2("NI");
        cout << (s1 > s2) << endl;
        cout << (s1 >= s2) << endl;
        cout << (s1 == s2) << endl;
        cout << (s1 != s2) << endl;
        cout << (s1 <= s2) << endl;
    }
    void TestString3()
    {
        string s1("Hello");
        cout << s1.c_str() << endl;
        s1 += '!';
        s1 += "2345";
        cout << s1.c_str() << endl;
    }
    void TestString4()
    {
        string s1("HelloWord");
        string s2("HelloWord");
        s1.erase(3, 1);
        cout << s1.c_str() << endl;
        s1.erase(3, 100);
        cout << s1.c_str() << endl;
        s2.resize(4);
        cout << s2.c_str() << endl;
        s2.resize(10, 'x');
        cout << s2.c_str() << endl;
    }
    void TestString5()
    {
        string s1("HelloWord");
        cout << s1 << endl;
        cin >> s1;
        string::iterator it = s1.begin();
        while (it != s1.end() - 1)
        {
            cout << *it << "";
            ++it;
        }
        cout << endl;
    }
}
