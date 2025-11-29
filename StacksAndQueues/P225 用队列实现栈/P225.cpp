#include <bit/stdc++.h>
using namespace std;

class MyStack(){
	queue<int> que;
	MyStack(){
		
	}
	void() push(int x){
		que.push(x);
	}
	int pop(){
		int size = que.size();
		while(--size > 0){
			int tmp = que.front();
			que.pop();
			que.push(tmp);
		}
		int tmp = que.front();
		que.pop();
		return tmp;
	}
	int top(){
		return que.back();
	}
	bool empty(){
		if(que.empty())return true;
		else return false;
	}
}
int main(){
	return 0;
}