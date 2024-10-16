#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; // 定义元素类型

/* 结点结构 */
typedef struct QNode
{
    ElemType data;      // 数据域
    struct QNode *next; // 指针域，指向下一个节点
} QNode, *QNodePtr;

/* 链队列结构 */
typedef struct
{
    QNodePtr front; // 队头指针，指向队列的第一个节点
    QNodePtr rear;  // 队尾指针，指向队列的最后一个节点
} LinkQueue, *LinkQueuePtr;

/* 初始化一个空队列 */
int Init_LinkQueue(LinkQueuePtr *Q)
{
    *Q = (LinkQueuePtr)malloc(sizeof(LinkQueue));    // 分配队列结构体内存
    QNodePtr head = (QNodePtr)malloc(sizeof(QNode)); // 创建头节点

    if (head != NULL && *Q != NULL)
    {
        head->next = NULL;  // 头节点的next指针为空
        (*Q)->front = head; // 队头指向头节点
        (*Q)->rear = head;  // 队尾指向头节点
    }
    return (*Q != NULL && head != NULL) ? 1 : 0; // 初始化成功返回1，失败返回0
}

/* 判空 */
int LinkQueue_Empty(LinkQueuePtr Q)
{
    return Q->front == Q->rear; // 如果队头和队尾指针相等，说明队列为空
}

/* 入队操作 */
int Enter_LinkQueue(LinkQueuePtr Q, ElemType e)
{
    QNodePtr s = (QNodePtr)malloc(sizeof(QNode)); // 创建新节点
    if (s == NULL)
    {
        return 0; // 内存分配失败
    }
    // 初始化新节点
    s->data = e;
    s->next = NULL; // 新节点的next指针为空

    // 建立新联系
    Q->rear->next = s; // 将新节点链接到队尾
    Q->rear = s;       // 更新队尾指针指向新节点

    return 1; // 入队成功
}

/* 出队操作 */
int Delete_LinkQueue(LinkQueuePtr Q, ElemType *e)
{
    QNodePtr p;
    if (LinkQueue_Empty(Q))
    {
        return 0; // 如果队列为空，返回0
    }

    // 保留删除节点的信息
    p = Q->front->next; // 获取队头的下一个节点
    *e = p->data;       // 将出队元素的值赋给e

    // 建立新联系
    Q->front->next = p->next; // 前移队头指针

    if (Q->rear == p)
    {                       // 如果出队的是最后一个节点
        Q->rear = Q->front; // 队尾也指向头节点
    }

    free(p); // 释放出队节点的内存

    return 1; // 出队成功
}

/* 测试代码 */
int main()
{
    LinkQueuePtr queue;
    if (Init_LinkQueue(&queue))
    { // 初始化链队列
        printf("Queue initialized successfully.\n");

        // 入队操作
        for (int i = 0; i < 5; i++)
        {
            if (Enter_LinkQueue(queue, i))
            {
                printf("Inserted: %d\n", i);
            }
            else
            {
                printf("Failed to insert: %d\n", i);
            }
        }

        // 出队操作
        ElemType e;
        while (!LinkQueue_Empty(queue))
        {
            if (Delete_LinkQueue(queue, &e))
            {
                printf("Deleted: %d\n", e);
            }
        }

        // 释放队列内存
        free(queue->front); // 释放头节点
        free(queue);        // 释放队列结构体
    }
    else
    {
        printf("Failed to initialize queue.\n");
    }

    return 0;
}