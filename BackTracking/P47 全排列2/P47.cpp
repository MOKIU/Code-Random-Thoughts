#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int>& nums, vector<bool>& used){
	if(path.size() == nums.size()){
		result.push_back(path);
		return;
	}
	for(int i = 0; i < nums.size();i++){
		if(i > 0 && used[i-1] == false && nums[i] == nums[i-1]){
			continue;
		}
		if(used[i] == true)continue;
		used[i] = true;
		path.push_back(nums[i]);
		backtracking(nums, used);
		path.pop_back();
		used[i] = false;
	}
}
vector<vector<int>> permute(vector<int>& nums){
	sort(nums.begin(), nums.end());
	vector<bool> used(nums.size(), false);
	backtracking(nums, used);
	return result;
}