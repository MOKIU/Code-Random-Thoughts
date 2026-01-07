#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    ListNode* p = headA;
    ListNode* q = headB;
    while (p != nullptr && q != nullptr)
    {
        p = p->next;
        q = q->next;
    }
    if (p == nullptr)
    {
        while (q != nullptr)
        {
            headB = headB->next;
            q = q->next;
        }
    }
    else if (q == nullptr)
    {
        while (p != nullptr)
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