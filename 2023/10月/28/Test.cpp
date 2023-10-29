#include <iostream>
using namespace std;
class Date
{
public:
    // 构造函数
    Date(int year = 1, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _year = year;
    }

    // 拷贝构造
    Date(const Date &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    void Print()
    {
        cout << _year << "/" << _month << "/" << _day << endl;
    }

private:
    // 成员变量
    int _year;
    int _month;
    int _day;
};
class Stack
{
public:
    //构造函数  
    Stack(size_t _capacity = 10)
    {
        cout << "Stack(size_t _capacity)" << endl;
        _array = (int *)malloc(sizeof(int) * _capacity);
        if (nullptr == _array)
        {
            perror("malloc is fail");
            exit(-1);
        }
        _size = 0;
        _capacity = _capacity;
    }

    void Push(const int &data)
    {
        _array[_size] = data;
        _size++;
    }

    //拷贝构造
    Stack(const Stack &st)
    {
        cout<<"Stack(const Stack& st)"<<endl;
        _array = (int *)malloc(sizeof(int) * st._capacity);
        if (nullptr == _array)
        {
            perror("malloc is fail");
            exit(-1);
        }
        memcpy(_array, st._array, sizeof(int) * st._size);
        _size = st._size;
        _capacity = st._capacity;
    }

    ~Stack()
    {
        cout<<"~Stack()"<<endl;

        if (_array)
        {
            delete[] _array;
            _array = nullptr;
            _capacity = 0;
            _size = 0;
        }
    }

private:
    int *_array;
    int _size;
    int _capacity;
};

class MyQueue
{
    //默认生成构造 ->生成定义在Stack中的默认构造函数
    //默认生成析构
    //默认生成的拷贝构造

private:
    Stack _pushST;
    Stack _popST;
    //int _size = 0;
};

int main()
{
    Stack st1;
    st1.Push(1);
    st1.Push(2);
    st1.Push(3);

    Stack st2(st1);
    st2.Push(4);
    st2.Push(5);
    cout<<"====="<<endl;
    MyQueue q;
   // MyQueue q1(q);

    return 0;
}

// Date d1;
// d1.Print();

// Date d2;
// d2.Print();