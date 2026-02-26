#include <bits/stdc++.h>
using namespace std;

stack<int> xsk;
stack<int> msk;
MinStack(){
	msk.push(INT_MAX);
}
void push(int val){
	xsk.push(val);
	if(val <= msk.top())msk.push(val);
}
void pop(){
	if(msk.top() == xsk.top())msk.pop();
	xsk.pop();
}
int top(){
	return xsk.top();
}
int getMin(){
	return msk.top();
}
int main(){
	return 0;
}