#include <iostream>
using namespace std;

// int main()
// {
//     int * p1=(int*)malloc(sizeof(int));
//     if(p1==NULL)
//     {
//         perror("malloc is fail");
//     }

//     free(p1);

//     return 0;
// }

void Test()
{
    // 动态申请一个int类型的空间
    int *ptr4 = new int;

    // 动态申请一个int类型的空间并初始化为10
    int *ptr5 = new int(10);

    // 动态申请10个int类型的空间
    int *ptr6 = new int[10];

    delete ptr4;
    delete ptr5;
    delete[] ptr6;
}

// int main()
// {
//    // int *p1 = new int(10); // 申请一个int ,初始化10

//     return 0;
// }
// /*
// operator new:该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回;
// 申请空间 失败，尝试执行空 间不足应对措施，
// 如果改应对措施用户设置了，则继续申请，否 则抛异常。
// */
// void *__CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
// {
//     // try to allocate size bytes
//     void *p;
//     while ((p = malloc(size)) == 0)
//         if (_callnewh(size) == 0)
//         {
//             // report no memory
//             // 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//             static const std::bad_alloc nomem; _RAISE(nomem);
//         }
//     return (p);
// }
// /*
// operator delete: 该函数最终是通过free来释放空间的
// */
// void operator delete(void *pUserData)
// {
//     _CrtMemBlockHeader *pHead;
//     RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//     if (pUserData == NULL)
//         return;
//     _mlock(_HEAP_LOCK); /* block other threads */
//     __TRY
//     /* get a pointer to memory block header */
//     pHead = pHdr(pUserData);
//     /* verify block type */
//     _ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//     _free_dbg(pUserData, pHead->nBlockUse);
//     __FINALLY
//     _munlock(_HEAP_LOCK); /* release other threads */
//     __END_TRY_FINALLY
//     return;
// }
// /*
// free的实现
// */
// #define free(p)
// _free_dbg(p, _NORMAL_BLOCK)

class A
{
public:
    A(int a = 0)
        : _a(a)
    {
        cout << "A():" << this << endl;
    }
    ~A()
    {
        cout << "~A():" << this << endl;
    }

private:
    int _a;
};
   // int *p1 = new int[10];
    // free(p1);

    // A *p2 = new A;
    // free(p2);
// // 申请失败会抛出异常
// int *p1 = (int *)operator new(sizeof(int *));

// // 失败返回nullptr
// int *p2 = (int *)malloc(sizeof(int *));
// if (p2 == NULL)
// {
//     perror("malloc is fail");
// }

// 申请空间 operator nwe -> 封装malloc
// // 调用构造函数
// A *p3 = new A;

// // 先调用析构函数,在释放p3指向的空间
// delete p3;

// // 申请空间: operator new[]-> operator new -> malloc封装
// A *p4 = new A[10];

// // 先调用10次析构函数,在释放p4指向的空间
// delete[] p4; //[]只是为了匹配

class Stack
{
private:
    int* _a;
    int _size;
    int _capacity;

public:
    Stack()
    {
        cout << "Stack():" << this << endl;
        _a=new int[4];
        _size=0;
        _capacity =4;
    }

    ~Stack()
    {
        cout << "~Stack():" << this << endl;
        delete[] _a;
        _size=_capacity=0;
    }
};

int main()
{
    //st为自定义类型,出了函数会自动调用析构函数
    Stack st;

    //pst为指针,是内置类型,不会自动调用
    Stack* pst;
    delete pst;

    return 0;
}