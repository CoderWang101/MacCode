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
void TestBSTree4()
{
    int a[] = {8, 3, 1, 10, 6, 4, 7, 14, 19};

    BSTree<int> t1;
    for (auto e : a)
        t1.InsertR(e);
    t1.InOrder();
    
    cout<<"===COPY==="<<endl;
    BSTree<int> copy(t1);
    BSTree<int> copy2=t1;

    // t1.EraseR(10);
    // t1.EraseR(14);
    // t1.Erase(13);
    copy.InOrder();
    copy2.InOrder();

    // for (auto e : a)
    // {
    //     t1.Erase(e);
    //     t1.InOrder();
    // }
    //t1.InOrder();
}

int main()
{
    TestBSTree4();

    return 0;
}