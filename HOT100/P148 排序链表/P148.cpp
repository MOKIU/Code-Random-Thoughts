#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr){}
	ListNode(int x): val(x), next(nullptr){}
	ListNode(int x, ListNode* next): val(x), next(next){}
};
ListNode* sortList(ListNode* head) {
    ListNode* res;// 不带数据的头结点,方便合并
    ListNode* pre;// 从res开始,用于合并时尾指针加元素
    ListNode* h1; // 左合并区间的起点
    ListNode* h2; // 右合并区间的起点
    ListNode* h = head; // 记录下一个左合并区间在哪
    
    res = new ListNode(0);
    res->next = head;
    
    int curr_len = 1; // 合并目标区间的长度,初始为1,每完成一轮遍历后*2
    int len = 0;
    int i;
    
    while(h){ // 获取链表长度
    	len++;
    	h = h->next;
    }
    
    while(curr_len < len){ // 当合并目标区间长度变大到比链表长度长时停止
    	pre = res;
    	h = pre->next;
    	while(h){
    		
    		i = curr_len;
    		h1 = h;
    		
    		while(i > 0 && h){ // 让h到右区间起始起点
    			i--;
    			h = h->next;
    		}
    		if(i > 0){ // i>0说明是h到头了退出循环的,此时剩下的不够一个区间(已经有序),无需合并,直接进入下一轮即可
    			break;
    		}
    		
    		h2 = h;
    		i = curr_len;
    		int num2 = 0; // 右合并区间大小
    		
    		while(i > 0 && h){ // 让h到下一个合并两区间的左区间起始位置
    			i--;
    			h = h->next;
    			num2++; // 计算右区间长度(有可能不够curr_len)
    		}
    		
    		int num1 = curr_len;; // 左合并区间大小
    		
    		while(num1 > 0 && num2 > 0){ // 合并区间
    			if(h1->val <= h2->val){
    				pre->next = h1;
    				h1 = h1->next;
    				num1--;
    			}else{
    				pre->next = h2;
    				h2 = h2->next;
    				num2--;
    			}
    			pre = pre->next;
    		}
    		
    		if(num1 > 0){ // 合并时其中一个区间都合并完了,剩下那个区间全落下来
    			pre->next = h1;
    		}else if(num2 > 0){
    			pre->next = h2;
    		}
    		
    		while(num1 > 0 || num2 > 0){ // 移动pre指针到组末尾
    			pre = pre->next;
    			num1--;
    			num2--;
    		}
    		
    		pre->next = h; // 连接下一组起点
    	}
    	
    	curr_len *= 2;
    }
    return res->next;
}