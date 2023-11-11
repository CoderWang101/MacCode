#include <iostream>

// void Test()
// {
//     int *p1 = (int *)malloc(sizeof(int));
//     free(p1);

//     int *p2 = (int *)calloc(4, sizeof(int));
//     int *p3 = (int *)realloc(p2, sizeof(int) * 10);

//     free(p3);
// }

void Test()
{
    // 动态申请一个int类型的空间
    int *ptr4 = new int;

    // 动态申请一个int类型的空间并初始化为10
    int *ptr5 = new int(10);

    // 动态申请10个int类型的空间
    int *ptr6 = new int[3];
    
    delete ptr4;
    delete ptr5;
    delete[] ptr6;
}

int main()
{
    int *p1 = new int(10); // 申请一个int ,初始化10

    return 0;
}