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
        // vector(const vector<T> &v)
        // {
        //     reserve(v.capacity());
        //     memcpy(_start, v._start, v.size() * sizeof(T));
        //     _finish = _start + v.size();
        // }
        // vector(const vector<T> &v)
        // {
        //     _start= new T[v.capacity()];
        //     memcpy(_start, v._start, v.size() * sizeof(T));
        //     _finish = _start + v.size();
        //     _end_of_storage = _start + v.capacity();
        // }

        //传统写法
        // vector(const vector<T> &v)
        // {
        //     _start = new T[v.capacity()];
        //     // memcpy(_start, v._start, v.size() * sizeof(T));
        //     for (size_t i = 0; i < v.size(); ++i)
        //     {
        //         _start[i] = v._start[i];//复制重载 vv深拷贝
        //     }
        //     _finish = _start + v.size();
        //     _end_of_storage = _start + v.capacity();
        // }
        vector(const vector<T> &v)
                : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
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

        /*
        void insert(iterator& pos, const T &val)
        在v1.insert(v1.begin(), 0);v1.begin()具有常性,无法调用insert
        */
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
        cout << "--func--" << endl;
        // for (size_t i = 0; i < v.size(); ++i)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << endl;

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

        func(v1);

        v1.pop_back();
        v1.pop_back();
        v1.pop_back();

        // 迭代器访问
        vector<int>::iterator it = v1.begin();
        while (it != v1.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        
    }
    void test_vector2()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);

        cout << "v1 size = " << v1.size() << endl;
        cout << "v1 capacity = " << v1.capacity() << endl;

        cout << "*resize*" << endl;
        v1.resize(10);

        cout << "v1 size = " << v1.size() << endl;
        cout << "v1 capacity = " << v1.capacity() << endl;
        func(v1);

        cout << endl;

        cout << "*保留前3个*" << endl;
        v1.resize(3);
        cout << "v1 size = " << v1.size() << endl;
        cout << "v1 capacity = " << v1.capacity() << endl;
        func(v1);
    }

    void test_vector3()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        func(v1);

        v1.insert(v1.begin(), 0);
        func(v1);

        vector<int>::iterator pos = find(v1.begin(), v1.end(), 3); // find找到3的位置
        if (pos != v1.end())
        {
            pos = v1.insert(pos, 30);
        }
        func(v1);
        /*
        insert后我们认为pos失效了,不能在使用
        (*pos)++;
        func(v1);
        */
    }
    void test_vector4()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        func(v1);

        v1.insert(v1.begin(), 0);
        func(v1);

        vector<int>::iterator pos = find(v1.begin(), v1.end(), 2); // find找到3的位置
        if (pos != v1.end())
        {
            v1.erase(pos);
        }
        func(v1);
        // 库中,调用erase,pos会失效,不能访问并且强制检查
        // 若删除最后一个元素,访问pos会造成野指针,故erase后不要访问pos
    }
    void test_vector5()
    {
        vector<int> v1;
        v1.push_back(10);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        v1.push_back(50);

        vector<int>::iterator it = v1.begin();
        while (it != v1.end())
        {
            cout << *it << " ";

            if (*it % 2 == 0)
            {
                it = v1.erase(it);
            }
            else
            {
                ++it;
            }
        }

        cout << endl;

        for (it = v1.begin(); it != v1.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    void test_vector6()
    {
        // 调用拷贝构造
        vector<int> v1(10, 5);
        vector<int>::iterator it = v1.begin();
        for (it = v1.begin(); it != v1.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        vector<int> v2(v1.begin(), v1.end());
        for (it = v2.begin() + 1; it != v2.end() - 1; ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    void test_vector7()
    {
        // 没写拷贝构造，编译器默认生成拷贝构造，完成值拷贝/欠拷贝
        vector<int> v1(10, 5);
        vector<int> v2(v1);
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        vector<std::string> v3(3, "HelloHelloHelloHello");
        vector<std::string> v4(v3);
        for (vector<std::string>::iterator it = v4.begin(); it != v4.end(); ++it)
        {
            cout << *it << "----";
        }
        cout << endl;
        v4.push_back("≠2024!±");
        v4.push_back("≠2024!±");
        v4.push_back("≠≠2024!±");
        v4.push_back("≠2024!±");
        for (vector<std::string>::iterator it = v4.begin(); it != v4.end(); ++it)
        {
            cout << *it << "----";
        }
        cout << endl;
    }
}