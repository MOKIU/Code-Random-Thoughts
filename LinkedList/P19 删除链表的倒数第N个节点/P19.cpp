#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode():val(0),next(nullptr){};
	ListNode(int val):val(val),next(nullptr){};
	ListNode(int val,ListNode* next):val(val),next(nullptr){};
}
ListNode* removeNthFromEnd(ListNode* head,int n){
	ListNode* p = head;
	ListNode* q = head;
	while(n--){
		q = q->next;
	}
	if(q == nullptr){
		head = head->next;
	}else{
		while(q->next != nullptr){
			p = p->next;
			q = q->next;
		}
		p->next = p->next->next;
	}
	return head;
}
int main(){
	return 0;
}