#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int> candiates, int target, int sum, int startIndex){
	if(sum == target){
		result.push_back(path);
		return;
	}else if(sum > target){
		return;
	}
	for(int i = startIndex;i < candiates.size();i++){
		path.push_back(candiates[i]);
		sum += candiates[i];
		backtracking(candiates, target, sum, i);
		sum -= candiates[i];
		path.pop_back();
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
	backtracking(candidates, target, 0, 0);
	return result;
}
int main(){
	return 0;
}