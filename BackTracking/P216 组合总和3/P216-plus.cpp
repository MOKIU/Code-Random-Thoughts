#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<int> path;
void backtracking(int k, int n, int startIndex, int sum){
	if(path.size() == k){
		if(sum == n){
			result.push_back(path);
		}
		return;
	}
	for(int i = startIndex;i <= 9 - (k - path.size()) + 1;i++){
		path.push_back(i);
		sum += i;
		if(sum > n){
			sum -= i;
			path.pop_back();
			return;
		}
		backtracking(k, n, i+1, sum);
		sum -= i;
		path.pop_back();	
	}
}
vector<vector<int>> combinationSum3(int k, int n){
	backtracking(k, n, 1, 0);
	return result;
}
int main(){
	return 0;
}