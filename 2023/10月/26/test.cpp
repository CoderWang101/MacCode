#include <iostream>
#include <assert.h>
using namespace std;
// //c++兼容C结构体用法
// typedef struct ListNode
// {
//     int val;
//     struct ListNode* next;
// }LTN;

// //C的结构体类型是 struct ListNode

// //C++把结构体升级成了类

// struct Stack
// {
//     //成员函数
//     void Init(int n=4)
//     {
//         a=(int*)malloc(sizeof(int)*n);
//         if(nullptr==a)
//         {
//             perror("malloc is fail");
//             return;
//         }

//         capacity=n;
//         size=0;
//     }

//     //成员变量  位置任意
//     int* a;
//     int size;
//     int capacity;
// };

// class Person
// {
// public:
//     void Show()
//     {
//         //...
//     }

// public:
//     char* _name;
//     char* _sex;
//     int _age;
// };

// class Stack
// {
//     //成员函数
//     void Init(int n=4);
//     void Push(int x);

//     //成员变量
//     int* a;
//     int size;
//     int capacity;
// };

//
// class Stack
// {
// public:
//     //成员函数
//     void Init(int year,int month,int day)
//     {
//         _year=year;
//         _month=month;
//         _year=year;
//     }

// private:
//     //成员变量
//     int _year;
//     int _month;
//     int _day;
// };
// class Person
// {
// public:
//     void PrintPersonInfo();
// private:
//     char _name[20];
//     char _gender[3];
//     int  _age;
// };
// // 这里需要指定PrintPersonInfo是属于Person这个类域
//  void Person::PrintPersonInfo()
// {
//     cout << _name << " "<< _gender << " " << _age << endl;
// }// public:
//     //成员函数
//     void Init(int year,int month,int day)
//     {
//         _year=year;
//         _month=month;
//         _year=year;
//     }

// //private:
//     //声明
//     int _year;
//     int _month;
//     int _day;

// 类中既有成员变量，又有成员函数
// class A1
// {
// public:
//     void f1(){}
// private:
//     int _a;
// };

// // 类中仅有成员函数
// class A2
// {
// public:
//    void f2()
//    {

//    }
// };

// // 类中什么都没有---空类
// class A3
// {

// };

// int main()
// {

//     return 0;
// }

// Data._year=1;
// Data::_year=1;
// Data d1;
// Data d2;

// d1.Init(2077,2,2);
// d1._year++;

// cout<<sizeof(d1)<<endl;//12
// Stack st;
//  st.Init();
//  st.Push(1);
//  st.Push(2);
//  st.Push(3);

// class Date
// {
// public:
//     void Init(int year, int month, int day)
//     {
//         cout << this << endl;

//         this->_year = year;
//         this->_month = month;
//         this->_day = day;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// int main()
// {
//     // 年 // 月 // 日
//     Date d1, d2;
//     d1.Init(2022, 1, 11);
//     d2.Init(2022, 1, 12);
//     // d1.Print();
//     // d2.Print();
//     return 0;
// }

// 1.下面程序编译运行结果是? A、编译报错 B、运行崩溃 C、正常运行
// class Date
// {
// public:

//     void Init(int year,int month,int day)
//     {
//         cout << this << endl;

//         this->_year = year;
//         this->_month = month;
//         this->_day = day;
//     }

//     void Print()
//     {
//         cout << this << endl;
//         cout << "Print()" << endl;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// int main()
// {
//     Date* ptr = nullptr;

//     // ptr->Print();//正常运行
//     // (*ptr).func();//正常运行

//     return 0;
// }

// typedef int DataType;
// typedef struct Stack
// {
//     DataType *array;
//     int capacity;
//     int size;
// } Stack;
// void StackInit(Stack *ps)
// {
//     assert(ps);
//     ps->array = (DataType *)malloc(sizeof(DataType) * 3);
//     if (NULL == ps->array)
//     {
//         assert(0);
//         return;
//     }
//     ps->capacity = 3;
//     ps->size = 0;
// }
// void StackDestroy(Stack *ps)
// {
//     assert(ps);
//     if (ps->array)
//     {
//         free(ps->array);
//         ps->array = NULL;
//         ps->capacity = 0;
//         ps->size = 0;
//     }
// }
// void CheckCapacity(Stack *ps)
// {
//     if (ps->size == ps->capacity)
//     {
//         int newcapacity = ps->capacity * 2;
//         DataType *temp = (DataType *)realloc(ps->array,
//                                              newcapacity * sizeof(DataType));
//         if (temp == NULL)
//         {
//             perror("realloc申请空间失败!!!");
//             return;
//         }
//         ps->array = temp;
//         ps->capacity = newcapacity;
//     }
// }
// void StackPush(Stack *ps, DataType data)
// {
//     assert(ps);
//     CheckCapacity(ps);
//     ps->array[ps->size] = data;
//     ps->size++;
// }
// int StackEmpty(Stack *ps)
// {
//     assert(ps);
//     return 0 == ps->size;
// }
// void StackPop(Stack *ps)
// {
//     if (StackEmpty(ps))
//         return;
//     ps->size--;
// }
// DataType StackTop(Stack *ps)
// {
//     assert(!StackEmpty(ps));
//     return ps->array[ps->size - 1];
// }
// int StackSize(Stack *ps)
// {
//     assert(ps);
//     return ps->size;
// }
// int main()
// {
//     Stack s;
//     StackInit(&s);
//     StackPush(&s, 1);
//     StackPush(&s, 2);
//     StackPush(&s, 3);
//     StackPush(&s, 4);
//     printf("%d\n", StackTop(&s));
//     printf("%d\n", StackSize(&s));
//     StackPop(&s);
//     StackPop(&s);
//     printf("%d\n", StackTop(&s));
//     printf("%d\n", StackSize(&s));
//     StackDestroy(&s);
//     return 0;
// }

typedef int DataType;
class Stack
{
public:
    void Init()
    {
        _array = (DataType *)malloc(sizeof(DataType) * 3);
        if (NULL == _array)
        {
            perror("malloc申请空间失败!!!");
            return;
        }
        _capacity = 3;
        _size = 0;
    }
    void Push(DataType data)
    {
        CheckCapacity();
        _array[_size] = data;
        _size++;
    }
    void Pop()
    {
        if (Empty())
            return;
        _size--;
    }
    DataType Top()
    {
        return _array[_size - 1];
    }
    int Empty()
    {
        return 0 == _size;
    }
    int Size()
    {
        return _size;
    }
    void Destroy()
    {
        if (_array)
        {
            free(_array);
            _array = NULL;
            _capacity = 0;
            _size = 0;
        }
    }

private:
    void CheckCapacity()
    {
        if (_size == _capacity)
        {
            int newcapacity = _capacity * 2;
            DataType *temp = (DataType *)realloc(_array, newcapacity *
                                                             sizeof(DataType));
            if (temp == NULL)
            {
                perror("realloc申请空间失败!!!");
                return;
            }
            _array = temp;
            _capacity = newcapacity;
        }
    }

private:
    DataType *_array;
    int _capacity;
    int _size;
};
int main()
{
    Stack s;
    
    s.Init();
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    printf("%d\n", s.Top());
    printf("%d\n", s.Size());
    s.Pop();
    s.Pop();
    printf("%d\n", s.Top());
    printf("%d\n", s.Size());
    s.Destroy();
    return 0;
}