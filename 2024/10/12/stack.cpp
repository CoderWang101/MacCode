//链式存储
#include <iostream>
using namespace std;

// 定义链表节点结构体
struct Linknode
{
    int data;              // 存储数据
    struct Linknode *next; // 指向下一个节点的指针
};

// 初始化链表头节点
void initlink(Linknode *head)
{
    // 如果头节点为空，输出分配失败信息（此处的逻辑实际上不正确，因为头节点应该在调用此函数之前已经分配）
    if (head == nullptr)
        cout << "分配失败" << endl;
    else
        head->next = nullptr; // 将头节点的 next 指针置为空
}

// 判断链表是否为空
bool isempty(Linknode *head)
{
    // 如果头节点的 next 指针为空，说明链表为空
    if (head->next == nullptr)
        return true;
    else
        return false;
}

// 在链表头部插入一个新节点
void enqueue(Linknode *head, int x)
{
    Linknode *L = new Linknode[sizeof(Linknode)]; // 分配新节点
    L->data = x;                                  // 设置新节点的数据
    L->next = head->next;                         // 新节点的 next 指针指向原头节点的 next
    head->next = L;                               // 头节点的 next 指针指向新节点
}

// 从链表头部删除一个节点
void dequeue(Linknode *head)
{
    Linknode *L = head->next; // 获取要删除的节点
    head->next = L->next;     // 头节点的 next 指针指向下一个节点
    delete[] L;               // 释放被删除节点的内存
}

// 获取链表头节点的数据
void gethead(Linknode *head)
{
    int x;
    x = head->next->data; // 获取头节点的数据
    cout << x << endl;    // 输出数据
}

// 销毁链表
void DestroyStack(Linknode *head)
{
    Linknode *p = head->next; // 获取第一个节点
    if (!isempty(head))       // 如果链表不为空
    {
        while (head->next != nullptr) // 遍历链表
        {
            head->next = p->next; // 头节点的 next 指针指向下一个节点
            delete[] p;           // 释放当前节点的内存
            p = head->next;       // p 指针指向下一个节点
        }
    }
    delete[] p; // 释放最后一个节点的内存
}

int main()
{
    Linknode *h = new Linknode[sizeof(Linknode)]; // 分配头节点
    initlink(h);                                  // 初始化链表
    if (isempty(h))
        cout << "链表空" << endl; // 输出链表为空的信息
    for (int i = 0; i < 10; i++)
    {
        enqueue(h, i); // 插入十个节点
    }
    gethead(h);      // 获取并输出头节点数据
    dequeue(h);      // 删除头节点
    gethead(h);      // 再次获取并输出头节点数据
    DestroyStack(h); // 销毁链表
    return 0;
}