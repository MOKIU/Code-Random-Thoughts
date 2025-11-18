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
ListNode* reverseList(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode* p = head;
    ListNode* q = head->next;
    while (q != nullptr)
    {
        ListNode* tmp = q->next;
        q->next = p;
        p = q;
        q = tmp;
    }
    head->next = nullptr;
    head = p;
    return head;
}
int main()
{
    return 0;
}