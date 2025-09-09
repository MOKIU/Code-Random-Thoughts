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
detectCycle(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    bool hasCycle = false;
    int index = 0;
    while (fast != nullptr && slow != nullptr)
    {
        if (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
        }
        else
        {
            break;
        }
        if (slow->next != nullptr)
        {
            slow = slow->next;
        }
        else
        {
            break;
        }
        if (fast == slow)
        {
            hasCycle = true;
            break;
        }
    }
    if (hasCycle)
    {
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
            index++;
        }
        return fast;
    }
    else
    {
        return nullptr;
    }
}
int main()
{
    return 0;
}