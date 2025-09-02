#include <bits/stdc++.h>
using namespace std;

// 由于某些成员函数需要对边界进行一些判断,所以维护一个size变量
// 链表节点下标从0开始
class MyLinkedList
{
public:
        // 链表节点结构体
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int val) : val(val), next(nullptr) {};
    }

    LinkedNode* head;
    int size;
        // 链表初始化函数
    MyLinkedList()
    {
                // 创建一个空节点
        this->head = new LinkedNode(0);
        this.size = 0;
    }
        // 获取链表特定位置节点值
    int get(int index)
    {
        LinkNode* p = head;
        if (index >= size)
        {
            return -1;
        }
        for (int i = 0; i < size; i++)
        {
            if (index == i)
            {
                return p->val;
            }
            else
            {
                p = p->next;
            }
        }
        return -1;
    }
        // 在链表头部添加一个节点
    void addAtHead(int val)
    {
        if (this.size == 0)
        {
            this->head->val = val;
            this.size++;
        }
        else
        {
            LinkedNode* p = new LinkedNode(val);
            p->next = head;
            head = p;
            this.size++;
        }
    }
        // 在链表尾部添加添加一个节点
    void addAtTail(int val)
    {
        if (this.size == 0)
        {
            this->head->val = val;
            this.size++;
        }
        else
        {
            LinkedNode* p = new LinkedNode(val);
            LinkedNode* q = head;
            for (int i = 0; i < this.size; i++)
            {
                q = q->next;
            }
            q->next = p;
        }
    }
        // 在链表特定位置添加节点
    void addAtIndex(int index, int val) {}
        // 删除链表特定位置节点
    void deleteAtIndex(int index) {}
} int main() {}