#include <bits/stdc++.h>
using namespace std;

// nums[i]即是数字的权重也是价值
bool canPartition(vector<int>& nums){
	// 先求数组和,得到数组和的一半
	int sum = 0;
	vector<int> dp(10001, 0);
	for(int i = 0;i < nums.size();i++){
		sum += nums[i];
	}
	// 无法平分
	if(sum % 2 == 1)return false;
	int target = sum / 2;
	for(int i = 0;i < nums.size();i++){
		for(int j = target;j >= nums[i];j--){
			dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
		}
	}
	if(dp[target] == target)return true;
	return false;
}
int main(){
	return 0;
}