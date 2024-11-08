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
    // // 1.iterator
    // template <class T>
    // struct __list_iterator
    // {
    //     typedef list_node<T> node;
    //     typedef __list_iterator<T> self;
    //     node *_node;

    //     __list_iterator(node *n)
    //         : _node(n)
    //     {
    //     }

    //     T &operator*()
    //     {
    //         return _node->_data;
    //     }

    //     self &operator++()
    //     {
    //         _node = _node->_next;
    //         return *this;
    //     }
    //     self &operator++(int) // 后置++
    //     {
    //         self tmp = *this;
    //         _node = _node->_next;
    //         return tmp;
    //     }

    //     self &operator--()
    //     {
    //         _node = _node->_prev;
    //         return *this;
    //     }
    //     self &operator--(int)
    //     {
    //         self tmp = *this;
    //         _node = _node->_prev;
    //         return tmp;
    //     }

    //     bool operator!=(const self &s)
    //     {
    //         return _node != s._node;
    //     }

    //     bool operator==(const self &s)
    //     {
    //         return _node == s._node;
    //     }
    // };
    // // 2.const_iterator
    // template <class T>
    // struct __list_const_iterator
    // {
    //     typedef list_node<T> node;
    //     typedef __list_const_iterator<T> self;
    //     node *_node;

    //     __list_const_iterator(node *n)
    //         : _node(n)
    //     {
    //     }

    //     const T &operator*() // 与1区别的地方，加const不能修改数据
    //     {
    //         return _node->_data;
    //     }

    //     self &operator++()
    //     {
    //         _node = _node->_next;
    //         return *this;
    //     }
    //     self &operator++(int) // 后置++
    //     {
    //         self tmp = *this;
    //         _node = _node->_next;
    //         return tmp;
    //     }

    //     self &operator--()
    //     {
    //         _node = _node->_prev;
    //         return *this;
    //     }
    //     self &operator--(int)
    //     {
    //         self tmp = *this;
    //         _node = _node->_prev;
    //         return tmp;
    //     }

    //     bool operator!=(const self &s)
    //     {
    //         return _node != s._node;
    //     }

    //     bool operator==(const self &s)
    //     {
    //         return _node == s._node;
    //     }
    // };

    // template <class T,class Ref>
    // struct __list_iterator
    // {
    //     typedef list_node<T> node;
    //     typedef __list_iterator<T,Ref> self;
    //     node *_node;

    //     __list_iterator(node *n)
    //         : _node(n)
    //     {
    //     }

    //     Ref &operator*()
    //     {
    //         return _node->_data;
    //     }

    //     self &operator++()
    //     {
    //         _node = _node->_next;
    //         return *this;
    //     }
    //     self &operator++(int)
    //     {
    //         self tmp = *this;
    //         _node = _node->_next;
    //         return tmp;
    //     }

    //     self &operator--()
    //     {
    //         _node = _node->_prev;
    //         return *this;
    //     }
    //     self &operator--(int) // 后置++
    //     {
    //         self tmp = *this;
    //         _node = _node->_prev;
    //         return tmp;
    //     }

    //     bool operator!=(const self &s)
    //     {
    //         return _node != s._node;
    //     }

    //     bool operator==(const self &s)
    //     {
    //         return _node == s._node;
    //     }
    // };
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
        self &operator--(int) // 后置--
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
        /*
        "const T&"表示迭代器所指向元素的引用类型，
        而"const T*"表示迭代器所指向元素的指针类型。
        这样定义迭代器的目的是为了在const成员函数中
        使用该迭代器，并保证在遍历列表时不会修改列表中的元素
        */
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

        // 构造函数， 迭代器区间
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
        // 拷贝构造
        // lt2(lt1)
        // list(const list<T> &lt)
        // {
        //     empty_init();
        //     const_iterator it = lt.begin();
        //     while (it != lt.end())
        //     {
        //         push_back(*it);
        //         ++it;
        //     }
        // }
        list(const list<T> &lt)
        {
            empty_init();
            list<T> temp(lt.begin(), lt.end());
            swap(temp);
        }

        // 赋值操作符
        // lt3=lt2
        // 不能使用&，而是传值调用拷贝构造,拷贝lt2，赋值给lt3
        list<T> &operator=(const list<T> lt)
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

        // void push_back(const T &x)
        // {
        //     node *tail = _head->_prev;
        //     node *new_node = new node(x);

        //     tail->_next = new_node;
        //     new_node->_prev = tail;
        //     new_node->_next = _head;
        //     _head->_prev = new_node;
        // }
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
        /*
        在该函数的最后一行，返回了一个迭代器对象 `iterator(next)`。
        这是因为在 C++ STL 中，通常情况下，删除一个元素后，我们希望返回
        删除元素的下一个位置作为新的迭代器。直接返回 `next` 的话，可能会
        暴露内部实现细节，使得用户可以直接操作指针 `next`，可能导致潜在的问题。
        为了隐藏底层指针的细节，通常会将其封装在迭代器对象中返回。因此
        ，返回 `iterator(next)` 的方式可以提供更好的封装性和安全性，
        使用户能够使用迭代器对象来操作返回的下一个位置，而不需要直接访问底层的指针。
        这也符合 C++ STL 设计的一般原则，即通过迭代器提供统一的接口，隐藏底层的具体实现细节。
        */

    private:
        node *_head; // ListNode<T>是类型 ， ListNode是类名
    };
    void test_list1()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        lt.print_list(lt);
    }

    struct AA
    {
        int _a1;
        int _a2;

        AA(int a1 = 0, int a2 = 0)
            : _a1(a1), _a2(a2)
        {
        }
    };
    void test_list2()
    {
        list<AA> lt;
        lt.push_back(AA(1, 2));
        lt.push_back(AA(3, 4));
        lt.push_back(AA(5, 6));

        list<AA>::iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << it->_a1 << " " << it._node->_data._a2 << endl;
            cout << it.operator->()->_a1 << " " << it.operator->()->_a2 << endl;
            cout << it.operator->() << endl
                 << endl; // 地址值
            ++it;
        }
    }

    void test_list3()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);

        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        it = lt.begin();
        list<int>::iterator pos = lt.begin();
        ++pos;
        lt.insert(pos, 20);

        lt.print_list(lt);

        cout << endl;
    }

    void test_list4()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.print_list(lt);
        cout << endl;
        lt.push_back(100);
        lt.push_front(99);
        lt.print_list(lt);
        cout << endl;

        lt.pop_back();
        lt.pop_front();
        lt.print_list(lt);
        cout << endl;
    }

    void test_list5()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.print_list(lt);
        cout << endl;

        lt.clear();
        lt.push_back(20);

        lt.print_list(lt);
    }

    void test_list6()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.print_list(lt);
        cout << endl;

        // list<int> lt2(lt);
        // lt2.print_list(lt2);
        // cout << endl;
        list<int> lt2 = lt;
        lt2.print_list(lt2);
        lt.print_list(lt);
    }
}
