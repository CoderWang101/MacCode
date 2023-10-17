#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;

//缺省参数
void Func(int a = 10, int b = 20, int c = 30)
{
	cout << a << " ";
	cout << b << " ";
	cout << c << " ";
	printf("\n");
}

int main()
{
	Func();//		10 20 30
	Func(1,2,3);//	1 2 3
	Func(1);//		1 20 30
	//Func( ,3, );ֻ只能从头依次更改，不能任意位置进行更改
	
	return 0;
}
void _name()
{
	while (true)
	{

		/* code */
	}
	
}