#pragma once
#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;

namespace wzf
{

    template <class T>
    class vector
    {
    public:
        typedef T *iterator;

        vector()
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) // 全部初始化为空
        {
        }

        //~vector();

        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t sz = size();
                // 分配新的存储空间
                T *tmp = new T[n];
                if (_start) // 检查旧空间是否为空
                {
                    // 将内容复制到新空间
                    memcpy(tmp, _start, sizeof(T) * size());
                    delete[] _start;
                }
                // 更新指针
                _start = tmp;
                //_finish = tmp + size();//_finish - _start
                _finish = _start + sz; //_finish - _start
                _end_of_storage = _start + n;
            }
        }
        void push_back(const T &x)
        {
            if (_finish == _end_of_storage)
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }
            *_finish = x;
            ++_finish;
        }

        //删除
        void pop_back()
        {
            assert(!empty());
            --_finish;
        }

        bool empty() const
        {
            return _start == _finish;
        }

        size_t capacity() const
        {
            return _end_of_storage - _start;
        }

        size_t size() const
        {
            return _finish - _start;
        }

        T &operator[](size_t pos)
        {
            assert(pos <= size());
            return _start[pos];
        }

    private:
        iterator _start;
        iterator _finish;
        iterator _end_of_storage;
    };

    void test_vector1()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);

        for (size_t i = 0; i < v1.size(); ++i)
        {
            cout << v1[i] << " ";
        }
        cout << endl;

        v1.pop_back();
        v1.pop_back();
        v1.pop_back();

        vector<int>::iterator it = v1.begin();
        while (it != v1.end())
        {
            cout << *it << " ";
            ++it;
        }
    }
}