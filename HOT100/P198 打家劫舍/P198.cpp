#include <bits/stdc++.h>
using namespace std;

// dp[i]:偷第i个房屋,共0~i个房屋,能偷盗的最多金额
int rob(vector<int>& nums){
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	if(nums.size() == 1)return dp[0];
	dp[1] = nums[1] > nums[0] ? nums[1] : nums[0];
	if(nums.size() == 2)return dp[1];
	dp[2] = nums[2] + nums[0] > nums[1] ? nums[2] + nums[0] : nums[1]; 
	for(int i = 3;i < nums.size();i++){
		// 选择i偷有两种情况,前面隔两个偷,或前面隔一个偷
		if(dp[i-3] + nums[i] > dp[i-2] + nums[i]){
			dp[i] = dp[i-3] + nums[i];
		}else{
			dp[i] = dp[i-2] + nums[i];
		}
	}
	// 最后两个要么选倒数第一个,要么选倒数第二个,必然的选择
	return max(dp[nums.size() - 1], dp[nums.size() - 2]);
}
int main(){
	return 0;
}