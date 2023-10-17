#include<iostream>
using namespace std;

int main()
{
    int a=10;
    int& k=a;
    int& j=k;

    cout<< &a<< endl;
    cout<< &k<< endl;
    cout<< &j<< endl;

    return 0;
}