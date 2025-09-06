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
ListNode* swapPairs(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    else
    {
        ListNode* p = head;
        ListNode* q = head->next;
        p->next = q->next;
        q->next = p;
        head = q;
        ListNode* tmp = p;
        while (p->next != nullptr && p->next->next != nullptr)
        {
            q = p->next->next;
            p = p->next;
            p->next = q->next;
            q->next = p;
            tmp->next = q;
            tmp = p;
        }
        return head;
    }
}
int main()
{
    return 0;
}