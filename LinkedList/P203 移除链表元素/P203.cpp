#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr);
	ListNode(int val):val(val),next(nullptr);
	ListNode(int val,ListNode* next):val(val),next(nullptr);
}

ListNode* removeElements(ListNode* head,int val){
    ListNode *p = head, *q = head;
    while (head != nullptr && head->val == val) {
        p = head->next;
        delete head;
        head = p;
    }
    if (p != nullptr) {
        q = p->next;
        while (q != nullptr) {
            if (q->val == val) {
                p->next = q->next;
                delete q;
                q = p->next;
            } else {
                p = p->next;
                q = q->next;
            }
        }
    }
    return head;
}

int main(){
	return 0;
}