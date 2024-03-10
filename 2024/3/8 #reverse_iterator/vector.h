#pragma once
#include "iterator.h"
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

        //反向迭代器
        typedef ReverseIterator<iterator,T&, T* > reverse_iterator;
        typedef ReverseIterator<iterator,const T& , const T* > const_reverse_iterator;

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }

        vector()
            : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) // 全部初始化为空
        {
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

        // v2(v1)
        vector(const vector<T> &v)
        {
            vector<T> tmp(v.begin(), v.end());
            swap(tmp);
        }

        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        //v2=v1
        vector<T>& operator=(const vector<T> &v)
        {
            swap(v);
            return *this;
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
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

        // 开空间
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
                    // memcpy(tmp, _start, sizeof(T) * size());//浅拷贝
                    for (size_t i = 0; i < sz; ++i)
                        tmp[i] = _start[i];
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
            // 空间满了
            if (_finish == _end_of_storage)
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }
            *_finish = x;
            ++_finish;
        }

        // 缩容
        void resize(size_t n, T val = T()) // T():匿名对象调用默认构造
        {
            //检查空间大小
            if (n < size())
            {
                // 删除数据
                _finish = _start + n;
            }
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


        iterator insert(iterator pos, const T &val)
        {
            assert(pos >= _start);
            assert(pos <= _finish);

            // 如果扩容
            if (_finish == _end_of_storage)
            {
                // 计算需要扩容的大小
                size_t len = pos - _start;
                // 扩容
                reserve(capacity() == 0 ? 4 : capacity() * 2);

                // 扩容后,更新pos,防止迭代器失效(野指针)
                pos = _start + len;
            }

            // 把pos位置的元素移动到_finish位置
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

        iterator erase(iterator pos)
        {
            assert(pos >= _start);
            assert(pos < _finish);

            iterator start = pos + 1;
            while (start != _finish)
            {
                *(start - 1) = *start;
                ++start;
            }
            --_finish;
            return pos;
        }

        // 删除
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
        const T &operator[](size_t pos) const
        {
            assert(pos <= size());
            return _start[pos];
        }

    private:
        // 指针
        iterator _start;
        iterator _finish;
        iterator _end_of_storage;
    };

    void func(const vector<int> &v)
    {
        // 迭代器访问
        vector<int>::const_iterator it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        cout << "--func--" << endl;
    }



    void test_verctor()
    {
        wzf::vector<int> v1;

        v1.push_back(10);
        v1.push_back(11);
        v1.push_back(33);
        v1.push_back(100);
        v1.push_back(90);

        func(v1);

        // /vector<int>::reverse_iterator ->reverse_iterator是适配器 
        wzf::vector<int>::reverse_iterator rit=v1.rbegin();
        while (rit!=v1.rend())
        {
            cout<<*rit<<" ";
            ++rit;
        }
        
    }
}