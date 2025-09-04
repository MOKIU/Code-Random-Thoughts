#include <bits/stdc++.h>
using namespace std;

// 由于某些成员函数需要对边界进行一些判断,所以维护一个size变量
// 实现链表设计主要有两种方法,一种是原地修改链表,一种是使用一个虚拟头节点
// 后者的实现更方便,原地修改链表如果要是删除操作的话还要判断是否动的是头节点,如果是要修改头指针位置
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
    };

    LinkedNode* head;
    int size;
    // 链表初始化函数
    MyLinkedList()
    {
        // 创建一个空节点作为头节点
        this->head = new LinkedNode(0);
        this->size =
            0; // this是一个MyLinkedList*类型的指针,要使用->访问其成员变量
    }
    // 获取链表特定位置节点值
    int get(int index)
    {
        LinkedNode* p = head->next;
        if (index >= this->size)
        {
            return -1;
        }
        // 简化代码,避免冗余遍历
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        return p->val;
        // for (int i = 0; i < this->size; i++)
        // {
        // if (index == i)
        // {
        // return p->val;
        // }
        // else
        // {
        // p = p->next;
        // }
        // }
    }
    // 在链表头部添加一个节点
    void addAtHead(int val)
    {
        // if (this->size == 0)
        // {
        // // 使用虚拟头节点,不原地修改,下面写法会有空指针错误
        // // this->head->next->val = val;
        // this->size++;
        // }
        // else
        // {
        // LinkedNode* p = new LinkedNode(val);
        // p->next = head->next;
        // head->next = p;
        // this->size++;
        // }
        // 使用虚拟头节点后,就不用特殊判断了,同意都放在虚拟头节点之后
        LinkedNode* p = new LinkedNode(val);
        p->next = this->head->next;
        this->head->next = p;
        this->size++;
    }
    // 在链表尾部添加添加一个节点
    void addAtTail(int val)
    {
        // if (this->size == 0)
        // {
        // this->head->next->val = val;
        // this->size++;
        // }
        // else
        // {
        // LinkedNode* p = new LinkedNode(val);
        // LinkedNode* q = head->next;
        // for (int i = 0; i < this->size; i++)
        // {
        // q = q->next;
        // }
        // q->next = p;
        // }
        // 同样无需特殊判断,只需要让一个指针指向head,然后根据size遍历到尾部添加节点即可
        LinkedNode* p = this->head;
        LinkedNode* q = new LinkedNode(val);
        for (int i = 0; i < this->size; i++)
        {
            p = p->next;
        }
        p->next = q;
        this->size++;
    }
    // 在链表特定位置添加节点
    void addAtIndex(int index, int val)
    {
        // //
        // 实现思路:首先一个指针指向头节点,然后根据index遍历该指针到特定位置,再用另一个指针保存下一个节点的位置,然后连接节点
        // LinkedNode* p = head->next;
        // int count = index;
        // while (count--)
        // {
        // p = p->next;
        // }
        // // 判断插入位置是否会超出链表范围
        // if (index <= this->size)
        // {
        // LinkedNode* q = p->next;
        // LinkedNode* k = new LinkedNode(val);
        // p->next = k;
        // k->next = q;
        // this->size++;
        // }
        if (index <= this->size)
        {
            LinkedNode* q = new LinkedNode(val);
            LinkedNode* p = head;
            while (index--)
            {
                p = p->next;
            }
            q->next = p->next;
            p->next = q;
            this->size++;
        }
    }
    // 删除链表特定位置节点
    void deleteAtIndex(int index)
    {
        // //
        // 实现思路:首先判断删除的是否是第一个节点,如果是将要修改头指针的位置,否则需要遍历指针到待删除的节点再删除
        // if (index == 0)
        // {
        // this->head->next = this->head->next->next;
        // }
        // else
        // {
        // LinkedNode* p = head->next;
        // LinkedNode* q = head;
        // while (index--)
        // {
        // p = p->next;
        // q = q->next;
        // }
        // q->next = p->next;
        // }
        if (index < this->size)
        {
            LinkedNode* p = head;
            if (this->size == 1)
            {
                p->next = nullptr;
            }
            else
            {
                while (index--)
                {
                    p = p->next;
                }
                p->next = p->next->next;
            }
            this->size--;
        }
    }
} 

int main()
{
    return 0;
}