#include <iostream>
#include <assert.h>
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode *next;
	QDataType data;
} QNode;

typedef struct Queue
{
	// 定义两个指针，tail方便尾插
	// 方便对头出数据，尾入数据
	QNode *head;
	QNode *tail;
} Queue;

// 入队
void QueueDestory(Queue *pq)
{
	assert(pq);
	// QNode* cur = pq->head;`：创建一个指针 `cur`，
	// 并将其初始化为指向队列的头节点。这将是遍历队列的起点
	QNode *cur = pq->head;
	while (cur)
	{
		// 创建一个指针 `next`，将其指向当前节点 `cur` 的下一个节点。
		// 这是为了保留对下一个节点的引用，以便在释放当前节点后继续访问。
		QNode *next = cur->next;
		free(cur);
		cur = next;
	}
	// 在循环结束后，将队列的头指针 `pq->head`
	// 和尾指针 `pq->tail` 都设置为 NULL，表示队列为空。
	pq->head = pq->tail = NULL;
}

// 向队列尾部插入数据
void QueuePush(Queue* pq, QDataType x)
{
    assert(pq); // 确保队列指针不为空

    // 为新节点分配内存
    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    if (newnode == NULL) // 检查内存分配是否成功
    {
        printf("malloc fail\n"); // 输出错误信息
        exit(-1); // 退出程序，表示分配失败
    }

    // 初始化新节点的数据和指针
    newnode->data = x; // 设置新节点的数据域
    newnode->next = NULL; // 新节点的下一个节点初始化为 NULL

    if (pq->tail == NULL) // 检查队列是否为空
    {
        // 如果队列为空，新的节点同时成为头和尾
        pq->head = pq->tail = newnode;
    }
    else // 如果队列不为空
    {
        pq->tail->next = newnode; // 让当前的尾节点指向新节点
        pq->tail = newnode; // 更新队列的尾指针为新节点
    }
}