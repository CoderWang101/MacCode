#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode* cur1=pHead1,*cur2=pHead2;
        while (cur1!=cur2)
        {
            cur1=cur1!=nullptr?cur1->next:pHead2;
            cur2=cur2!=nullptr?cur2->next:pHead1;
        }
        return cur1;
    }
};

//方法二:
// class Solution
// {
// public:
//     ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
//     {
//         if (!pHead1 || !pHead2)
//             return nullptr;

//         int len_a = 0, len_b = 0;
//         ListNode *cur_a = pHead1, *cur_b = pHead2;
//         while (cur_a)
//         {
//             len_a++;
//             cur_a = cur_a->next;
//         }
//         while (cur_b)
//         {
//             len_b++;
//             cur_b = cur_b->next;
//         }

//         // 重制
//         cur_a = pHead1;
//         cur_b = pHead2;
//         if (len_a > len_b)
//         {
//             int differ = len_a - len_b;

//             while (differ--)
//                 cur_a = cur_a->next;
//         }
//         else
//         {
//             int differ = len_b - len_a;
//             while (differ--)
//                 cur_b = cur_b->next;
//         }
//         // 找到公共节点
//         int pos = 0;
//         while (cur_a && cur_b && cur_a != cur_b)
//         {
//             pos++;
//             cur_a = cur_a->next;
//             cur_b = cur_b->next;
//         }
//         while (cur_a)
//         {
//             cout << cur_a->val << ",";
//             cur_a = cur_a->next;
//         }
//         return cur_a;
//     }
// };
// 遍历链表计算长度
// 减去差值即为共同长度