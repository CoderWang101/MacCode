#pragma once
#include <iostream>
using namespace std;

template <class K>
struct BSTreeNode
{
    BSTreeNode<K> *_left;
    BSTreeNode<K> *_right;
    K _key;

    // 构造函数
    BSTreeNode(const K &key)
        : _left(nullptr), _right(nullptr), _key(key)
    {
    }
};

template <class K>
class BSTree
{
    typedef BSTreeNode<K> Node;

public:
    bool Insert(const K &key)
    {
        if (_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }

        Node *parent = nullptr;
        Node *cur = _root;
        while (cur)
        {
            if (cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
                return false;
        }
        cur = new Node(key);

        // 链接
        if (parent->_key < key)
            parent->_right = cur;
        else
            parent->_left = cur;

        return true;
    }

    bool Find(const K &key)
    {
        Node *cur = _root;
        while (cur)
        {
            if (cur->_key < key)
                cur = cur->_right;
            else if (cur->key > key)
                cur = cur->_left;
            else
                return true;
        }
        return false;
    }

    // 删除
    bool Erase(const const K &key)
    {
        Node *parent = nullptr;
        Node *cur = _root;

        while (cur)
        {
            if (cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                // 删除
                // 1.左为空
                if (cur->_left == nullptr)
                {
                    if (parent->_left == cur)
                        parent->_left = cur->_right;
                    else
                        parent->_right = cur->_right;
                } // 2.右为空
                else if (cur->_right == nullptr)
                {
                    if (parent->_left == cur)
                        parent->_left = cur->_left;
                    else
                        parent->_right = cur->_left;
                }

                return true;
            }
        }
        return false;
    }

    void InOrder()
    {
        _InOrder(_root);
    }

    void _InOrder(Node *root)
    {
        if (root == nullptr)
            return;
        // 中序
        _InOrder(root->_left);
        cout << root->_key << " ";
        _InOrder(root->_right);
    }

private:
    Node *_root = nullptr;
};