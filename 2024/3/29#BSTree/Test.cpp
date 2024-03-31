#include "BSTree.h"

void TestBSTree1()
{
    int a[] = {8, 3, 1, 10, 6, 4, 7, 14, 19};

    BSTree<int> t1;
    for (auto e : a)
        t1.Insert(e);
    t1.InOrder();
}

void TestBSTree2()
{
    int a[] = {8, 3, 1, 10, 6, 4, 7, 14, 19};

    BSTree<int> t1;
    for (auto e : a)
        t1.Insert(e);
    t1.InOrder();

    t1.Erase(10);
    t1.Erase(14);
    t1.Erase(13);
    t1.InOrder();

    for (auto e : a)
    {
        t1.Erase(e);
        t1.InOrder();
    }
    //t1.InOrder();
}

void TestBSTree3()
{
    int a[] = {8, 3, 1, 10, 6, 4, 7, 14, 19};

    BSTree<int> t1;
    for (auto e : a)
        t1.InsertR(e);
    t1.InOrder();

    t1.EraseR(10);
    t1.EraseR(14);
    t1.Erase(13);
    t1.InOrder();

    for (auto e : a)
    {
        t1.Erase(e);
        t1.InOrder();
    }
    //t1.InOrder();
}

int main()
{
    TestBSTree3();

    return 0;
}