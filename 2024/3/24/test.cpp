#include <iostream>
#include <string>
using namespace std;

class A {public:int _a;};

class B : virtual public A {public:   int _b;};

class C : virtual public A  {public: int _c; };

class D : public B, public C   {public:int _d;};

int main()
{   
    D d;
    d.B::_a = 9;
    d.C::_a = 10;
    d._b = 8;
    d._c = 6;
    d._d = 5;
    return 0;
}

// class A
// {
// public:
//     string name;
// };

// class B : public A
// {
// public:
//     int age;
// };

// class C : public A
// {
// public:
//     string sex;
// };

// class D : public B, public C
// {
// public:
//     int id;
// };
// int main()
// {
//     D student;
//     //student.name = "小明";
//     student.B::name = "小明";

//     student.age = 18;
//     student.sex = "男";
//     student.id = 666;
//     return 0;
// }

// class Person{};

// class Teacher: public Person {};

// class Student:public Person {};

// class Graduate : public Student, public Teacher {};

// void TestPerson()
// {
//     Student s1;
//     cout<<"人数 :"<<Person::_count<<" ";
//     Student s2;
//     cout<<Person::_count<<" ";

//     Student s3;
//     cout<<Person::_count<<" ";

//     Graduate s4;
//     cout<<Person::_count<<" ";

//     Student ::_count = 0;
//     cout <<endl<< "人数 :" << Person ::_count << endl;
// }

// int main()
// {
//     TestPerson();

//     return 0;
// }
// class Student;

// class Person
// {
// public:
//     friend void Display(const Person &p, const Student &s);

// protected:
//     string _name; // 姓名
// };

// class Student : public Person
// {
// protected:
//     int _stuNum; // 学号
// };

// void Display(const Person &p, const Student &s)
// {
//     cout << p._name << endl;
//     cout << s._stuNum << endl;
// }
// int main()
// {
//     Person p;
//     Student s;
//     Display(p, s);

//     return 0;
// }

// class Person
// {
// public:
//     Person(string name = "Father")
//         : _name(name)
//     {    }

//     Person &operator=(const Person &p)
//     {
//         if (this != &p)
//         {
//             cout << "调用父类" << endl;
//             _name = p._name;
//         }
//         return *this;
//     }

// protected:
//     string _name;
// };

// class student : public Person
// {
// public:
//     student(string name, int age)
//         : _age(age)
//     {    }
//     student &operator=(const student &s)
//     {
//         if (this != &s)
//         {
//             cout << "调用子类" << endl;
//             Person::operator=(s); // 必须调用父类运算符
//             _age = s._age;
//             _name = s._name;
//         }
//         return *this;
//     }

// protected:
//     int _age;
// };

// int main()
// {
//     student st("小红", 18); student st3("小刚", 16);
//     st = st3;

//     return 0;
// }

// class Person
// {
// public:
//     Person(string name = "Father")
//         : _name(name)
//     {
//         cout << name << endl;
//     }

// protected:
//     string _name;
// };

// class student : public Person
// {
// public:
//     student(string name, int age)
//         : _age(age)
//     {
//         cout << name << "  "
//              << age << endl;
//     }

//     student(student &s)
//         : Person(s) // 直接将st传过来通过切片拿到父类中的值
//           ,
//           _age(s._age) // 拿除了父类之外的值
//     {
//         cout << s._age << endl << s._name << endl;
//     }

// protected:
//     int _age;
// };

// int main()
// {
//     student st("Son", 18);
//     student st2(st);
//     return 0;
// }

// class Person
// {
// public:
//     Person(string name = "Father") // 先调用：父类默认构造调用一个print打印name
//         : _name(name)
//     {
//         cout << name << endl;
//     }

//     ~Person()
//     {
//         cout << "~Father" << endl;
//     }

// protected:
//     string _name;
// };

// class student : public Person
// { // 后调用：子类默认构造调用一个print打印name和age
// public:
//     student(string name, int age)
//         : _age(age)
//     {
//         cout << name << "  "
//              << age << endl;
//     }

//     student(student &s)
//         : Person(s) // 直接将st传过来通过切片拿到父类中的值
//           ,
//           _age(s._age) // 拿除了父类之外的值
//     {
//         cout << s._age << endl << s._name << endl;
//     }
//     ~student()
//     {
//         cout << "~Son" << endl;
//     }

// protected:
//     int _age;
// };

// int main()
// {
//     student st("Son", 18);
//     student st2(st);
//     return 0;
// }

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
//     //b若要访问父类fun,就需要加上修饰
//    // b.A::fun(99);

// };

// // Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
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
//         cout << " 学号:" << _num << endl;
//     }

// protected:
//     int _num = 999; // 学号
// };

// void Test()
// {
//     Student s1;
//     s1.Print();
// };

// int main()
// {
//     Test();
//     return 0;
// }
// class Person
// {
// public:
//     void Print()
//     {
//         cout << "name:" << _name << endl;
//         cout << "age:" << _age << endl<<endl;
//     }

// protected:
//     string _name = "father"; // 姓名
//     int _age = 18;          // 年龄
// };

// class Student : public Person
// {

// protected:
//     int _stuid; // 学号
// };

// int main()
// {
//     Student s;
//     Person* p=&s;

//     //p=s;

//     //cout<<'s'<<endl;
//     // s.Print();
//     //p=s;
//     //p.Print();
//     //s=p;

//     return 0;
// }

// class Person
// {
// public:
//     void Print()
//     {
//         cout << "name:" << _name << endl;
//         cout << "age:" << _age << endl<<endl;
//     }

// protected:
//     string _name = "peter"; // 姓名
//     int _age = 18;          // 年龄
// };

// // 继承后父类的Person的成员(成员函数+成员变量)都会变成子类的一部分。
// // 这里体现出了 Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，
// // 可以看到变量的复用。调用Print可以看到成员函数的复用。
// class Student : public Person
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
