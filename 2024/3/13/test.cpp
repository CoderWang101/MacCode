#include <iostream>
#include <string>
using namespace std;

// class Person
// {
// public:
//     void Print()
//     {
//         cout << "name:" << _name << endl;
//         cout << "age:" << _age << endl;
//     }

// protected:
//     string _name = "peter"; // 姓名
//     int _age = 18;          // 年龄
// };

// // 继承后父类的Person的成员(成员函数+成员变量)都会变成子类的一部分。
// // 这里体现出了 Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，
// // 可以看到变量的复用。调用Print可以看到成员函数的复用。
// class Student : public Person//class Student : Person 私有继承,main函数无法调用s.Print()
// {
// protected:
//     int _stuid; // 学号
// };

// class Teacher : public Person
// {
// protected:
//     int _jobid; // 工号
// };

// int main()
// {
//     Student s;
//     Teacher t;
//     s.Print();
//     t.Print();
//     return 0;
// }
// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
// class Person
// {
// protected:
//     string _name = "小李子"; // 姓名
//     int _num = 111;          // 身份证号
// };
// class Student : public Person
// {
// public:
//     void Print()
//     {
//         cout << " 姓名:" << _name << endl;
//         cout << " 身份证号:" << Person::_num << endl;
//         cout << " 学号:" << _num << endl;//_num访问的是派生类的
//     }

// protected:
//     int _num = 999; // 学号
// };
// void Test()
// {
//     Student s1;
//     s1.Print();
// };

// int mian()
// {
//     Student s;
//     s.Print();

//     return 0;
// }

// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
// class A
// {
// public:
//     void fun()
//     {
//         cout << "func()" << endl;
//     }
// };
// class B : public A
// {
// public:
//     void fun(int i)
//     {
//         A::fun();
//         cout << "func(int i)->" << i << endl;
//     }
// };

// void Test()
// {
//     B b;
//     b.fun(10);
//     //访问父类A中的fun()
//     b.A::fun();
// }

class Person
{
public:
    Person(const char *name = "peter")
        : _name(name)
    {
        cout << "Person()" << endl;
    }
    Person(const Person &p)
        : _name(p._name)
    {
        cout << "Person(const Person& p)" << endl;
    }
    Person &operator=(const Person &p)
    {
        cout << "Person operator=(const Person& p)" << endl;
        if (this != &p)
            _name = p._name;
        return *this;
    }
    ~Person()
    {
        cout << "~Person()" << endl;
    }

protected:
    string _name; // 姓名
};

class Student : public Person
{
public:
    Student(const char *name, int num)
        : Person(name), _num(num)
    {
        cout << "Student()" << endl;
    }
    Student(const Student &s)
        : Person(s), _num(s._num)
    {
        cout << "Student(const Student& s)" << endl;
    }
    Student &operator=(const Student &s)
    {
        cout << "Student& operator= (const Student& s)" << endl;
        if (this != &s)
        {
            Person::operator=(s);//Persong:: 指定作用域
            _num = s._num;
        }
        return *this;
    }
    ~Student()
    {
        cout << "~Student()" << endl;
    }

protected:
    int _num; // 学号
};
void Test()
{
    Student s1("jack", 18);
    Student s2(s1);
    Student s3("rose", 17);
    s1 = s3;
}

// int main()
// {
//    Test();

//     return 0;
// }