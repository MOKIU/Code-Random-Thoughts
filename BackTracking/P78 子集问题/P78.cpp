#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int> nums, int startIndex, vector<bool>& used){
	result.push_back(path);
	for(int i = startIndex;i < nums.size();i++){
		if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false){
			continue;
		}
		path.push_back(nums[i]);
		used[i] = true;
		backtracking(nums, i+1, used);
		used[i] = false;
		path.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums){
	vector<bool> used(nums.size(), false);
	sort(nums.begin(), nums.end());
	backtracking(nums, 0, used);
	return result;
}
int main(){
	return 0;
}