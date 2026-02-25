#include <bits/stdc++.h>
using namespace std;
class Trie
{
	set<string> wset;
    Trie() {
    	
    }
    void insert(string word) {
    	wset.insert(word);
    }
    bool search(string word) {
    	if(wset.find(word) == wset.end()){
    		return false;
    	}else{
    		return true;
    	}
    }
    bool startsWith(string prefix) {
    	for(string word : wset){
    		bool tmp = true;
    		for(int i = 0;i < prefix.size();i++){
    			if(word[i] != prefix[i]){
    				tmp = false;
    				break;
    			}
    		}
    		if(tmp == true)return true;
    	}
    	return false;
    }
};
int main()
{
    return 0;
}