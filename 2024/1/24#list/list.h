#pragma once
#include <iostream>

namespace name
{
    template <class T>
    struct ListNode
    {
        ListNode<T> *_prev;
        ListNode<T> *_next;
        T _data;
    };
 
    template <class T>
    class list
    {
    public:
        list()
        {
            _head = new ListNode<T>;
            _head->_new = _head;
            _head->_prev = _head;
        }
        ~list()
        {
        }

    private:
        ListNode<T> *_head;//ListNode<T>是类型 ， ListNode是类名 
    };

}
