#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<int> path;
int sum = 0;
// 1 2 2 2 5 t:5
void backtracking(vector<int> candidates, int target, int startIndex, vector<bool>& used){
	if(sum == target){
		result.push_back(path);
		return;
	}
	for(int i = startIndex;i < candidates.size();i++){
		if(i > 0 && !used[i-1] && candidates[i] == candidates[i-1]){
			continue;
		}else{
			used[i] = true;
			path.push_back(candidates[i]);
			sum += candidates[i];
			if(sum > target){
				used[i] = false;
				sum -= candidates[i];
				path.pop_back();
				return;
			}
			backtracking(candidates, target, i+1, used);
			used[i] = false;
			sum -= candidates[i];
			path.pop_back();
		}
	}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
	sort(candidates.begin(), candidates.end());
	vector<bool> used(candidates.size());
	backtracking(candidates, target, 0, used);
	return result;
}
int main(){
	return 0;
}