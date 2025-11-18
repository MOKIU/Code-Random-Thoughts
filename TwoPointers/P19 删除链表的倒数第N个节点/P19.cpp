#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    ListNode* p = head;
    ListNode* q = head;
    while (n-- > 0)
    {
        q = q->next;
    }
    if (q == nullptr)
    {
        head = head->next;
        return head;
    }
    while (q->next != nullptr)
    {
        p = p->next;
        q = q->next;
    }
    p->next = p->next->next;
    return head;
}
int main()
{
    return 0;
}
