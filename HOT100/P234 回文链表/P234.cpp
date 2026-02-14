#include <bit/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr){}
	ListNode(int x): val(x), next(nullptr){}
	ListNode(int x, ListNode* next): val(x), next(next){}
};
bool isPalindrome(ListNode* head){
	// 通过快慢指针找逆置节点,将后半段逆置,头指针为tail,然后遍历比较
	// 找到逆置起始起点
	ListNode* slow = head;
	ListNode* fast = head;
	while(fast->next != nullptr && fast->next->next != nullptr){
		slow = slow->next;
		fast = fast->next->next;
	}
	
	// 将后半段链表逆置
	ListNode* p = slow;
	ListNode* q = nullptr;
	ListNode* tmp = nullptr;
	while(p != nullptr){
		tmp = p->next;
		p->next = q;
		q = p;
		p = tmp;
	}
	// 比较
	ListNode* start = head;A
	ListNode* end = q;
	while(start != nullptr){
		if(start->val != end->val){
			return false;
		}
		start = start->next;
		end = end->next;
	}
	return true;
}
int main(){
	return 0;
}