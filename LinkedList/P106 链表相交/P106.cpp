#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val, ListNode* next) : val(val), next(nullptr) {};
}

ListNode*
getIntersectionNode(ListNode* headA, ListNode* headB)
{
    ListNode* p = headA;
    ListNode* q = headB;
    while (p->next != nullptr && q->next != nullptr)
    {
        p = p->next;
        q = q->next;
    }
    if (p->next == nullptr)
    {
        while (q->next != nullptr)
        {
            headB = headB->next;
            q = q->next;
        }
    }
    else if (q->next == nullptr)
    {
        while (p->next != nullptr)
        {
            headA = headA->next;
            p = p->next;
        }
    }
    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
int main()
{
    return 0;
}