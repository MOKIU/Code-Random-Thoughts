#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* detectCycle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    if (head == nullptr) return nullptr;
    do
    {
        if (slow->next != nullptr)
        {
            slow = slow->next;
        }
        else
        {
            return nullptr;
        }
        if (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next;
            fast = fast->next;
        }
        else
        {
            return nullptr;
        }
    } while (slow != fast);
    ListNode* pos = head;
    while (pos != fast)
    {
        pos = pos->next;
        fast = fast->next;
    }
    return pos;
}
int main()
{
    return 0;
}