// 顺序存储栈的实现

#include <iostream>
using namespace std;

#define maxsize 10 // 定义栈的最大容量为 10

// 定义顺序栈的结构体
typedef struct
{
    int data[maxsize]; // 用于存储栈中元素的数组
    int top;           // 栈顶指针，指向栈顶元素的位置
} sq;

// 初始化栈
void stackinit(sq &s)
{
    s.top = -1; // 栈初始为空，栈顶指针设为 -1
}

// 判断栈是否为空
bool stackempty(sq s)
{
    if (s.top == -1) // 栈顶指针为 -1 说明栈为空
        return true;
    else
        return false;
}

// 入栈操作
bool push(sq &s, int x)
{
    if (s.top == maxsize - 1) // 如果栈顶指针等于最大容量 - 1，栈已满，返回 false
        return false;
    s.data[++s.top] = x; // 将新元素 x 压入栈中，并更新栈顶指针
    return true;         // 成功入栈，返回 true
}

// 出栈操作
void pop(sq &s)
{
    if (s.top == -1) // 如果栈为空，输出提示信息
        cout << "栈空" << endl;
    else
        s.top--; // 若栈不为空，栈顶指针减一，删除栈顶元素
}

// 获取栈顶元素的值
int gettop(sq s)
{
    int x;
    if (s.top == -1) // 如果栈为空，返回 -1
        return -1;
    x = s.data[s.top]; // 获取栈顶元素的值
    return x;          // 返回栈顶元素
}

// 销毁栈
void destorystack(sq &s)
{
    // 这里不需要 free(s.data) 因为 data 是在栈内存中分配的，不是在堆中
    s.top = -1; // 将栈顶指针置为 -1，表示栈已清空
}

// 主函数
int main()
{
    sq s1;         // 定义一个顺序栈变量
    stackinit(s1); // 初始化栈

    // 将 0 到 9 的数依次压入栈中
    for (int i = 0; i < 10; i++)
    {
        push(s1, i); // 入栈操作
    }

    // 输出栈中的元素（从栈顶到栈底）
    while (!stackempty(s1)) // 当栈不为空时
    {
        cout << gettop(s1) << " "; // 获取并输出栈顶元素
        s1.top--;                  // 将栈顶指针减一
    }
    cout << endl; // 输出换行

    // 再次将 0 到 9 的数依次压入栈中
    for (int i = 0; i < 10; i++)
    {
        push(s1, i); // 入栈操作
    }

    pop(s1); // 弹出栈顶元素

    // 输出栈中的元素（从栈顶到栈底）
    while (!stackempty(s1)) // 当栈不为空时
    {
        cout << gettop(s1) << " "; // 获取并输出栈顶元素
        s1.top--;                  // 将栈顶指针减一
    }

    destorystack(s1); // 销毁栈
    return 0;         // 返回 0，程序正常结束
}