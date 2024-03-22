#include <iostream>
using namespace std;

class Car
{
public:
    virtual void Drive() = 0;
};

class Benz : public Car
{
public:
    virtual void Drive(){ cout << "Benz-舒适" << endl; }
};
class BMW : public Car
{
public:
    virtual void Drive(){ cout << "BMW-操控" << endl; }
};

void test()
{
    Car *pBenz = new Benz;
    pBenz->Drive();
    
    Car *pBMW = new BMW;
    pBMW->Drive();
}

// class A
// {
// public:
//     virtual void func(int val=1){ std::cout<<"A->"<<val<<std::endl;}
// };

// class B : public A
// {
// public:
//     virtual void func(int val=0){ std::cout<<"B->"<<val<<std::endl;}

//     virtual void test(){ func(); }
// };

// int main(int argc , char* argv[])
// {
//     B* p=new B;
//     p->test();

//     return 0;
// }