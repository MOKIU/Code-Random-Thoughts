#include <bits/stdc++.h>
using namespace std;

class Trie
{
	bool isEnd; // 表示该节点是不是单词的结尾
	Trie* next[26];
    Trie() {
    	isEnd = false;
    	memset(next, 0, sizeof(next));
    }
    void insert(string word) {
    	Trie* node = this;
    	for(char c : word){
    		if(node->next[c-'a'] == nullptr){
    			node->next[c-'a'] = new Trie();
    		}
    		node = node->next[c-'a'];
    	}
    	node->isEnd = true;
    }
    bool search(string word) {
    	Trie* node = this;
    	for(char c : word){
    		node = node->next[c-'a'];
    		if(node == nullptr){
    			return false;
    		}
    	}
    	return node->isEnd;
    }
    bool startsWith(string prefix) {
    	Trie* node = this;
    	for(char c : prefix){
    		node = node->next[c-'a'];
    		if(node == nullptr){
    			return false;
    		}
    	}
    	return true;
    }
};
int main(){
	
}