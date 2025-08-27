#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val, ListNode* next) : val(val), next(next) {};
};

ListNode* removeElements(ListNode* head, int val)
{
    ListNode *p = head, *q = head;
    while (head != nullptr && head->val == val)
    {
        p = head->next;
        delete head;
        head = p;
    }
    if (p != nullptr)
    {
        q = p->next;
        while (q != nullptr)
        {
            if (q->val == val)
            {
                p->next = q->next;
                delete q;
                q = p->next;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
    }
    return head;
}

// 初始化链表函数
ListNode* initLinkedList(int* arr, int size)
{
    if (size == 0)
    {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    int data[] = {1, 3, 3, 4};
    ListNode* head = initLinkedList(data, 4);
    ListNode* p = removeElements(head, 3);
    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}