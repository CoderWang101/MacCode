#include "BSTree.h"

void TestBSTree1()
{
    int a[]={8,3,1,10,6,4,7,14,19};

    BSTree<int> t1;
    for(auto e:a)
        t1.Insert(e);
    t1.InOrder();
    
}

int main()
{
    TestBSTree1();

    return 0;
}