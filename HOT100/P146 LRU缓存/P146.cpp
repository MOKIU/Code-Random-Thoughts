#include <bits/stdc++.h>
using namespace std;

// 双向链表
struct DLinkedNode{
	int key, value;
	DLinkedNode* prev;
	DLinkedNode* next;
	DLinkedNode():key(0), value(0), prev(nullptr), next(nullptr){}
	DLinkedNode(int key, int value):key(key), value(value), prev(nullptr), next(nullptr){}
};

unordered_map<int, DLinkedNode*> cache; // 这样设计方便直接通过哈希表找到节点在链表的地址
DLinkedNode* head;
DLinkedNode* tail;
int size;
int capacity;

LRUCache(int capacity):capacity(capacity), size(0) {
    head = new DLinkedNode();// 伪头部节点,方便插入元素,不需要操作头指针
    tail = new DLinkedNode();// 伪尾部节点,方便删除元素,不需要操作尾指针
    head->next = tail;
    tail->prev = head;
}
    
int get(int key) {
    if(!cache.count(key)){ // key不存在
    	return -1;
    }
    // key存在,先通过哈希表定位,再将节点插入到头部
    DLinkedNode* node = cache[key];
    moveToHead(node);
    return node->value;
}
    
void put(int key, int value) {
    if(!cache.count(key)){
    	DLinkedNode* node = new DLinkedNode(key, value);
    	cache[key] = node;
    	addToHead(node); // 新建的节点添加至头部
    	size++;
    	if(size > capacity){ // 超出容量
    		// 淘汰最不经常访问的节点,并获取这个节点,将其从双链表和哈希表中删除
    		DLinkedNode* removed = removeTail();
    		cache.erase(removed->key);
    		delete removed;
    		size--;
    	}
    }else{
    	DLinkedNode* node = cache[key]; // 存在则更新将其移动到头部
    	node->value = value;
    	moveToHead(node);
    }
}

void addToHead(DLinkedNode* node){
	node->prev = head;
	node->next = head->next;
	head->next->prev = node;
	head->next = node;
}

void removeNode(DLinkedNode* node){ // 传入的就是指向待删节点的指针,所以无需遍历寻找
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

void moveToHead(DLinkedNode* node){
	removeNode(node);
	addToHead(node);
}

DLinkedNode* removeTail(){
	DLinkedNode* node = tail->prev;
	removeNode(node);
	return node;
}