#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace wzf
{
    // 创建链表
    template <class T>
    struct list_node
    {
        list_node *_prev;
        list_node *_next;
        T _date;

        list_node(const T &x = T())
            : _next(nullptr), _prev(nullptr), _date(x)
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

        self &operator++()
        {
            _node = _node->_next;
            return *this;
        }
        self &operator++(int)
        {
            self tmp = *this;
            _node = _node->_next;
            return *this;
        }

        self &operator--()
        {
            _node = _node->_prev;
            return *this;
        }
        self &operator--(int)
        {
            self tmp = *this;
            _node = _node->_prev;
            return *this;
        }

        Ref &operator*()
        {
            return _node->_date;
        }

        Ptr &operator&()
        {
            return &(_node->_date);
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

        void empty_init()
        {
            _head = new node;
            _head->_prev = _head;
            _head->_next = _head;
        }
        list()
        {
            empty_init();
        }

        // 迭代器区间
        template <class Iterator>
        list(const Iterator first, const Iterator last)
        {
            empty_init();
            for (Iterator it = first; it != last; ++it)
                push_back(*it);
        }

        void swap(list<T> &temp)
        {
            std::swap(_head, temp._head);
        }

        // 拷贝构造
        list(const list<T> &lt)
        {
            empty_init();
            list<T> temp(lt.begin(), lt.end());
            swap(temp);
        }

        // 赋值重载
        list<T> &operator=(const list<T> lt)
        {
            swap(lt);
            return *this;
        }

        // 析构函数
        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }

        // insert
        void insert(iterator pos, const T &x)
        {
            node *cur = pos._node;
            node *prev = cur->_prev;

            node *new_node = new node(x);

            prev->_next = new_node;
            new_node->_prev = prev;
            new_node->_next = cur;
            cur->_prev = new_node;
        }

        void push_back(const T &x)
        {
            insert(end(), x);
        }
        void push_front(const T &x)
        {
            insert(begin(), x);
        }

        // erase
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

        void pop_back()
        {
            erase(--end());
        }
        void pop_front()
        {
            erase(begin());
        }

        void clear()
        {
            iterator it = begin();
            while (it != end())
                it = erase(it);
        }

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

        void print_list(const list<T> &lt)
        {
            cout << "---list---" << endl;
            list<int>::const_iterator it = lt.begin();
            while (it != lt.end())
            {
                cout << *it << " ";
                ++it;
            }
            cout << endl
                 << "---list---" << endl;
        }

    private:
        node *_head;
    };

    void test_list1()
    {
        list<int> l1;
        l1.push_back(1);
        l1.push_back(2);
        l1.push_back(3);
        l1.push_front(4);
        l1.print_list(l1);

        list<int> l2(l1.begin(), l1.end());
        l1.print_list(l1);
    }

    void test_list2()
    {
        list<int> l1;
        l1.push_back(1);
        l1.push_back(2);
        l1.push_back(3);
        l1.push_front(4);
        l1.print_list(l1);

        l1.pop_back();
        l1.pop_front();
        l1.print_list(l1);
    }

    void test_list3()
    {
        list<int> l1;
        l1.push_back(1);
        l1.push_back(2);
        l1.push_back(3);
        l1.push_front(4);
        l1.print_list(l1);

        list<int> l2(l1);
        l2.push_front(100);
        l2.print_list(l2);
        l1.print_list(l1);

        list<int> l3 = l1;
        l3.push_front(90);
        l3.print_list(l3);
        // l1.print_list(l1);

        l3.clear();
        l3.print_list(l3);
    }

    void test_list4()
    {
        list<int> l1;
        l1.push_back(1);
        l1.push_back(2);
        l1.push_back(3);
        l1.push_front(4);
        l1.print_list(l1);

        list<int> l2(l1);
        l2.push_front(100);
        l2.print_list(l2);
        l1.print_list(l1);

        list<int> l3 = l1;
        l3.push_front(90);
        l3.print_list(l3);
    }

} // namespace wzf。
