#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    bool res = false;
    while(fast && fast->next){
    	fast = fast->next->next;
    	slow = slow->next;
    	if(fast == slow){
    		res = true;
    		break;
    	}
    }
    return res;
}
int main(){
	return 0;
}