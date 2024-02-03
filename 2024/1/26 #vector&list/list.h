#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace wzf
{
    // 节点
    template <class T>
    struct list_node
    {
        list_node<T> *_prev;
        list_node<T> *_next;
        T _data;

        // 构造函数，创建链表
        list_node(const T &x = T()) // 用匿名对象做缺省值(调用默认构造)，以存储收其他类型的元素
            : _next(nullptr), _prev(nullptr), _data(x)
        {
        }
    };

    // 迭代器
    template <class T, class Ref, class Ptr>
    struct __list_iterator
    {
        typedef list_node<T> node;
        typedef __list_iterator<T, Ref, Ptr> self;
        node *_node;

        __list_iterator(node *n)
            : _node(n)
        {
        }

        Ref &operator*()
        {
            return _node->_data;
        }

        Ptr operator->()
        {
            return &(_node->_data); // 取地址
        }

        self &operator++()
        {
            _node = _node->_next;
            return *this;
        }
        self &operator++(int)
        {
            self tmp = *this;
            _node = _node->_next;
            return tmp;
        }

        self &operator--()
        {
            _node = _node->_prev;
            return *this;
        }
        self &operator--(int) // 后置++
        {
            self tmp = *this;
            _node = _node->_prev;
            return tmp;
        }

        bool operator!=(const self &s)
        {
            return _node != s._node;
        }

        bool operator==(const self &s)
        {
            return _node == s._node;
        }
    };


    template <class T>
    class list
    {
        typedef list_node<T> node;

    public:
        typedef __list_iterator<T, T &, T *> iterator;
        typedef __list_iterator<T, const T &, const T *> const_iterator;
        // typedef __list_const_iterator<T> const_iterator;

        iterator begin()
        {
            return iterator(_head->_next);
        }

        iterator end()
        {
            return iterator(_head);
        }

        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }

        const_iterator end() const
        {
            return const_iterator(_head);
        }

        void empty_init()
        {
            _head = new node;
            _head->_next = _head;
            _head->_prev = _head;
        }
        list()
        {
            empty_init();
        }

        // 模版构造函数， 迭代器区间
        template <class Iterator>
        list(const Iterator first, const Iterator last)
        {
            empty_init(); // 创建头节点
            for (Iterator it = first; it != last; ++it)
                push_back(*it);
        }

        void swap(list<T> &temp)
        {
            std::swap(_head, temp._head);
        }

        list(const list<T> &lt)
        {
            empty_init();
            list<T> temp(lt.begin(), lt.end());
            swap(temp);
        }

        // 赋值操作符
        // lt3=lt2
        list<T> &operator=(const list<T> &lt)
        {
            swap(lt);
            return *this;
        }

        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }

        // 清除头节点以外的数据
        void clear()
        {
            iterator it = begin();
            while (it != end())
                it = erase(it); // erase(it++);//后置++返回的是前一个的拷贝，不会失效
        }
        void push_back(const T &x)
        {
            insert(end(), x);
        }
        void push_front(const T &x)
        {
            insert(begin(), x);
        }

        void pop_back()
        {
            erase(--end());
        }
        void pop_front()
        {
            erase(begin());
        }

        void print_list(const list<T> &lt)
        {
            cout << "---list---" << endl;
            // list<int>::const_iterator it = lt.begin();
            list<int>::const_iterator it = lt.begin();
            while (it != lt.end())
            {
                cout << *it << " ";
                ++it;
            }
            cout << endl
                 << "---list---" << endl;
        }

        void insert(iterator pos, const T &x)
        {
            node *cur = pos._node;   // .访问pos内的成员变量_node
            node *prev = cur->_prev; // ->访问指针所指向的节点的成员

            node *new_node = new node(x);

            prev->_next = new_node;
            new_node->_prev = prev;
            new_node->_next = cur;
            cur->_prev = new_node;
        }

        iterator erase(iterator pos)
        {
            assert(pos != end());

            node *prev = pos._node->_prev;
            node *next = pos._node->_next;

            prev->_next = next;
            next->_prev = prev;
            delete pos._node;

            return iterator(next);
        }
    private:
        node *_head; // ListNode<T>是类型 ， ListNode是类名
    };
}
