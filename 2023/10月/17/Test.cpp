#include <iostream>
using namespace std;

// void Swap(int &left, int &right)
// {
//     int temp = left;
//     left = right;
//     right = temp;
// }

// int &Count()
// {
//     static int n = 0;
//     n++;
//     return n;
// }

// // int main()
// // {
// // 	int a=0, b=1;
// // 	swap(a,b);
// //     printf("%d %d \n",a,b);

// // 	return 0;
// // }

// #include <assert.h>

// #define N 10
// typedef struct Array
// {
//     int a[N];
//     int size;
// } AY;

// // 引用返回
// // 1，减少拷贝
// // 2，调用者可以修改返回对象
// int &PosAt(AY &ay, int i)
// {
//     assert(i < N);

//     return ay.a[i]; // 此处返回的就是a的第i个位置的别名
// }
// // int ret=Count();

// // AY ay;
// // for (int i = 0; i < N; i++)
// // {
// //     PosAt(ay,i)=i*10;
// // }
// // for (int i = 0; i < N; i++)
// // {
// //     cout<<PosAt(ay,i)<<" ";
// // }
// // cout<<endl;;

// int& Add(int a, int b)
// {
//     int c = a + b;
//     return c;
// }

// int main()
// {
//     int &ret = Add(1, 2);
//     //Add(3, 4);
//     cout << "Add(1,2) is :" << ret << endl;
//     cout << "Add(1,2) is :" << ret << endl;

//     return 0;
// }

// // inline int Add(int x,int y)
// // {
// //     return x+y;
// // }

// // int main()
// // {

// //     return 0;
// // }