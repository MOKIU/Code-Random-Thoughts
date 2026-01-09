#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<int> path;
void backtracking(int n, int k, int startIndex){
	if(path.size() == k){
		result.push_back(path);
		return;
	}
	// k - path.size()是还需要几个
	// i要找的是还需要的这几个的头一个,所以他的位置不能超过这个极限头一个的位置
	// 极限头一个位置：n - (k - path.size()) + 1
	for(int i = startIndex;i <= n - (k - path.size()) + 1;i++){
		path.push_back(i);
		backtracking(n, k, i+1);
		path.pop_back();
	}
}
vector<vector<int>> combine(int n, int k){
	backtracking(n, k, 1);
	return result;
}
int main(){
		return 0;
}