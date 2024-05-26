//100%
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;

        // 定义优先级队列，按照节点值从小到大排序
        priority_queue<int, vector<int>, greater<int> > pq;

        // 将每个链表的节点值插入优先级队列中
        for (ListNode *list : lists)
        {
            ListNode *pos = list;
            while (pos != nullptr)
            {
                pq.push(pos->val);
                pos = pos->next;
            }
        }

        // 构建合并后的链表
        ListNode *dummy = new ListNode(0); // 虚拟头节点
        ListNode *tail = dummy;            // 当前链表的最后一个节点

        while (!pq.empty())
        {
            tail->next = new ListNode(pq.top()); // 创建新节点
            tail = tail->next;                   // 更新尾部指针
            pq.pop();                            // 移除队列中的最小值
        }

        ListNode *result = dummy->next; // 合并后的链表头节点
        delete dummy;                   // 释放虚拟头节点
        return result;
    }
};

// class Solution
// {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      *
//      * @param lists ListNode类vector
//      * @return ListNode类
//      */
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         if(lists.size()==0)
//             return nullptr;

//         //插入优先级队列
//         priority_queue<int> q;
//         for (int i = 0; i < lists.size(); i++)
//         {
//             ListNode* pos=lists[i];

//             while (pos!=nullptr)
//             {
//                 q.push(pos->val);
//                 pos=lists[i]->next;
//             }
//         }
//         ListNode* head=nullptr;
//         ListNode* cur=head;
//         while (!q.empty())
//         {
//             cur->val=q.top();
//             q.pop();
//             cur=cur->next;
//         }
//         return head;
//     }
// };
