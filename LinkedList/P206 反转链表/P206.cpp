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
    // 思路：使用p,q两个指针,p前q后,p初始位于head节点,p位于head->next,依次往后遍历
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    else
    {
        ListNode* p = head;
        ListNode* q = head->next;
        p->next = nullptr;
        while (q->next != nullptr)
        {
            ListNode* tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        q->next = p;
        head = q;
        return head;
    }
}
int main() {}