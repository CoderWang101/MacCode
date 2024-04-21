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
    BSTree() : _root(nullptr) {}

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
                return false;//已经存在相同值
        }
        cur = new Node(key);//new节点

        // 链接-链接新节点
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
        else if (cur->_key > key)
            cur = cur->_left;
        else
            return true;
    }
    return false;
}

    // 删除
    bool Erase(const K &key)
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
                /*
                  若右/左子树为NUll,则可直接用左/右的第一个节点当头节点
                  或用左子树最右(大)节点or左子树最左(小)节点
                  */
                // 删除
                // 1.左为空
                if (cur->_left == nullptr)
                {
                    if (cur == _root)
                        _root = cur->_right;
                    else
                    {
                        if (parent->_left == cur)
                            parent->_left = cur->_right;
                        else
                            parent->_right = cur->_right;
                    }
                } // 2.右为空
                else if (cur->_right == nullptr)
                {
                    if (cur == _root)
                        _root = cur->_left;
                    else
                    {
                        if (parent->_left == cur)
                            parent->_left = cur->_left;
                        else
                            parent->_right = cur->_left;
                    }
                }
                else
                {

                    // 找左子树最右(大)节点or左子树最左(小)节点
                    Node *pminRight = cur;
                    Node *minRight = cur->_right;
                    while (minRight->_left)
                    {
                        pminRight=minRight;
                        minRight = minRight->_left;
                    }
                    cur->_key = minRight->_key;
                    if (pminRight->_left == minRight)
                        pminRight->_left = minRight->_right;
                    else
                        pminRight->_right = minRight->_right;

                    delete minRight;
                }

                return true;
            }
        }
        return false;
    }

    bool _FindR(Node* root,const K& key)
    {
        if(root==nullptr)
            return false;
        if(root->_key == key)
            return true;
        if(root->_key<key)
            return _FindR(root->_right,key);
        else
            return _FindR(root->_left,key);
    }

    //递归
    bool FindR(const K& key)
    {   
        return _FindR(_root, key);
    }

    bool InsertR(const K& key)
    {
        return _InsertR(_root,key);
    }
    //Node*& root [*&] 利用引用进行链接
    bool _InsertR(Node*& root,const K& key)
    {
        if(root==nullptr)
        {
            root=new Node(key);
            return true;
        }

        if(root->_key<key)
            return _InsertR(root->_right,key);
        else if(root->_key>key) 
            return _InsertR(root->_left,key);
        else
            return false;
    }

    bool EraseR(const K &key)
    {
        return _EraseR(_root,key);
    }
    bool _EraseR(Node*& root, const K& key)
    {
        if(root==nullptr)
            return false;
        
        if(root->_key<key)
            return _EraseR(root->_right,key);
        else if (root->_key>key)
            return _EraseR(root->_left,key);
        else
        {
            Node* del=root;
            //删除
            if(root->_right==nullptr)         
                root=root->_left;
            else if (root->_left==nullptr)
                root=root->_right;
            else
            {
                Node* maxleft=root->_left;
                while(maxleft->_right)
                    maxleft=maxleft->_right;
                swap(root->_key,maxleft->_key);

                return _EraseR(root->_left, key);
            }
            delete del;
            
            return true;
        }

        return true;
    }

    void InOrder()
    {
        _InOrder(_root);
        cout<<endl<<"==="<< endl;
    }

    void _InOrder(Node *root)
    {
        if (root == nullptr)
            return;
        // 中序遍历
        _InOrder(root->_left);
        cout << root->_key << " ";
        _InOrder(root->_right);
    }

    //BSTree(){}
    //BSTree()=default;

    BSTree(const BSTree<K>& t)
    {
        _root=Copy(t._root);
    }

    ~BSTree()
    {
        Destory(_root);    
    }

    BSTree<K>& operator=(BSTree<K> t)
    {
        swap(_root,t._root);
        return *this;
    }

private:
    Node* Copy(Node* root)
    {
        if (root==nullptr)
            return nullptr;

        Node* newRoot=new Node(root->_key);
        newRoot->_left=Copy(root->_left);        
        newRoot->_right=Copy(root->_right);        

        return newRoot;
    }

    void Destory(Node*& root)
    {
        if (root==nullptr)
            return;
        Destory(root->_left);        
        Destory(root->_right);        
        delete root;
        root=nullptr;
    }

private:
    //Node *_root = nullptr;
    Node *_root;
};