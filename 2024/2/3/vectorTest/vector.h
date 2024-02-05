#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace wzf
{
    template <class T>
    class vector
    {

    public:
        typedef T *iterator;
        typedef const T *const_iterator;

        vector()
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
        }

        void swap(vector<T> &v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        vector(size_t n, const T &value = T())
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
            reserve(n);
            for (size_t i = 0; i < n; ++i)
            {
                push_back(value);
            }
        }

        //[first,last)
        template <class InputIterator>
        vector(InputIterator *first, InputIterator *last)
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        // v1(v2)
        vector(const vector<T> &v)
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
        {
            vector<T> tmp(v.begin(), v.end());
            swap(tmp);
        }

        // v2=v1
        vector<T> &operator=(const vector<T> &v)
        {
            swap(v);
            return *this;
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _end_of_storage - _start;
        }

        void reserve(size_t n)
        {
            // 空间不够
            if (n > capacity())
            {
                size_t sz = size();
                // 分配新空间
                T *tmp = new T[n];

                if (_start) // 检查旧空间是否为空
                {
                    for (size_t i = 0; i < sz; ++i)
                        tmp[i] = _start[i];
                    delete[] _start;
                }

                _start = tmp;
                _finish = _start + sz;
                _end_of_storage = _start + n;
            }
        }

        void push_back(const T &x)
        {
            if (_finish == _end_of_storage)
            {
                reserve(capacity() == 0 ? 4 : 2 * capacity());
            }
            *_finish = x;
            ++_finish;
        }

        void resize(size_t n, T val = T())
        {
            if (n < size())
                _finish = _start + n;
            else
            {
                if (n > capacity())
                    reserve(n);

                // 添加数据
                while (_finish != _start + n)
                {
                    *_finish = val;
                    ++_finish;
                }
            }
        }

        // insert
        iterator insert(iterator pos, const T &val)
        {
            assert(pos >= _start);
            assert(pos <= _finish);

            // 检查扩容
            if (_finish == _end_of_storage)
            {
                size_t len = pos - _start;
                reserve(capacity() == 0 ? 4 : 2 * capacity());
                // 更新pos
                pos = _start + len;
            }

            iterator end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *end;
                --end;
            }

            *pos = val;
            ++_finish;

            return pos;
        }

        bool empty() const
        {
            return _start == _finish;
        }

        iterator erase(iterator pos)
        {
            assert(pos >= _start);
            assert(pos <= _finish);

            iterator start=pos+1;
            while (start!=_finish)
            {
                *(start-1)=*start;
                ++start;
            }
            --_finish;
            return pos;
        }

        void pop_back()
        {
            assert(!empty());
            --_finish;
        }

        T& operator[](size_t pos)
        {
            assert(pos<=size());
            return _start[pos];
        }

        const T& operator[](size_t pos)const
        {
            assert(pos<=size());
            return _start[pos];
        }

        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator begin() const
        {
            return _start;
        }

        const_iterator end() const
        {
            return _finish;
        }

    private:
        iterator _start;
        iterator _finish;
        iterator _end_of_storage;
    };

    void func(const vector<int> &v)
    {
        cout << "--func--" << endl;
        vector<int>::const_iterator it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        cout << "--func--" << endl;
    }

    void test_vector1()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        func(v1);

        vector<int> v2(10, 5);
        func(v2);

        vector<int> v3(v1.begin(), v1.end());
        func(v3);
    }

    void test_vector2()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        func(v1);

        vector<int> v2(v1);
        func(v2);

        vector<int> v3 = v1;
        func(v3);
    }
    void test_vector3()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        func(v1);
        cout << "v1 size = " << v1.size() << endl;
        cout << "v1 capacity = " << v1.capacity() << endl;
        v1.resize(2);
        func(v1);
        cout << "v1 size = " << v1.size() << endl;
        cout << "v1 capacity = " << v1.capacity() << endl;
    }

    void test_vector4()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        func(v1);

        // v1.pop_back();
        // v1.pop_back();


        v1.erase(v1.begin()+2);
        func(v1);

        vector<int>::iterator pos=find(v1.begin(),v1.end(),2);
        if (pos!=v1.end())
        {
            v1.erase(pos);
        }
        func(v1);

        cout<<v1[1]<<endl;
        cout<<v1[0]<<endl;
        // cout<<v1[3]<<endl;
    }

} // namespace wzf
