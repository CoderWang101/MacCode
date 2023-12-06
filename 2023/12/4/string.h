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
        string(const char *str = "")
            : _size(strlen(str))
        {
            _capacity = _size == 0 ? 3 : _size;
            _str = new char[_size + 1];
            strcpy(_str, str);
        }

        string(const string &s)
            : _size(s._size), _capacity(s._capacity)
        {
            _str = new char[s._capacity];
            strcpy(_str, s._str);
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _capacity = _size = 0;
        }

        string &operator=(const string s)
        {
            if (this != &s)
            {
                char *tmp = new char[s._capacity + 1];
                strcpy(tmp, s._str);
                delete[] _str;
                _str = tmp;
                _capacity = s._capacity;
                _size = s._size;
            }
        }

        const char *c_str()
        {
            return _str;
        }
        size_t size() const
        {
            return _size;
        }
        size_t capacity() const
        {
            return _capacity;
        }
        char &operator[](size_t pos)
        {
            assert(pos <= _size);
            return _str[pos];
        }

        const char &operator[](size_t pos) const
        {
            assert(pos <= _size);
            return _str[pos];
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
            return *this < s._str || *this == s._str;
        }
        bool operator>(const string &s) const
        {
            return !(*this <= s._str);
        }
        bool operator>=(const string &s) const
        {
            return !(*this < s._str);
        }
        bool operator!=(const string &s) const
        {
            return !(*this == s._str);
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
            if (_size + 1 > _capacity)
            {
                reserve(2 * _capacity);
            }

            size_t end = _size + 1;
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

            size_t end = len + _size;
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

        string &erase(size_t pos, size_t len = npos)
        {
            assert(pos <= _size);

            if (len == pos || len + pos >= _size)
            {
                _str[_size] = '\0';
                _size = pos;
            }
            else
            {
                strcpy(_str + pos, _str + pos + len);
                _size -= len;
            }
            return *this;
        }

        size_t fiund(char ch, size_t pos = 0)
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
        size_t fiund(const char *str, size_t pos = 0)
        {
            assert(pos < _size);

            char *p = strstr(_str + pos, str);
            if (p = nullptr)
            {
                return npos;
            }
            else
            {
                return p - _str;
            }
        }

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
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


}
