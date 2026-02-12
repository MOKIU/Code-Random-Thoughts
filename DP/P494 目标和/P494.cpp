#include <bits/stdc++.h>
using namespace std;

// dp[i]：背包容量为i时能装的数最接近i的数
// 但此题不适合使用一维数组，因为dp[bagweight]表示背包容量的最大价值,
// 如果有符合的答案，最大价值一定是=bagweight的,我们要统计=bagweight的个数需要知道过程,
// 而一维数组只有结果
int findTargetSumWays(vector<int>& nums, int target){
	int sum = 0;
	int res = 0;
	for(int i = 0;i < nums.size();i++){
		sum += nums[i];
	}
	int bagweight = (sum + target) / 2;
	vector<int> dp(bagweight + 1, 0);
	for(int i = 0;i < nums.size();i++){
		for(int j = bagweight;j >= nums[i];j--){
			dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			if(dp[j] == bagweight){
				res++;
			}
		}
	}
	return res;
}
// dp[i][j]：使用下标为0-i的nums[i]能够凑满j容量的背包有dp[i][j]种方法
int findTargetSumWays(vector<int>& nums, int target){
	int sum = 0;
	for(int i = 0;i < nums.size();i++){
		sum += nums[i];
	}
	// 无解情况
	if((target + sum) % 2 == 1 || abs(target) > sum)return 0;
	int bagSize = (target + sum)/2;
	
	vector<vector<int>> dp(nums.size(), vector<int>(bagSize + 1, 0));
	
	// 初始最上行
	if(nums[0] <= bagSize)dp[0][nums[0]] = 1;
	
	// 初始化最左列
	dp[0][0] = 1;
	int numZero = 0;
	for(int i = 0;i < nums.size();i++){
		if(nums[i] == 0)numZero++;
		dp[i][0] = (int)pow(2.0, numZero);
	}
	
	for(int i = 1;i < nums.size();i++){
		for(int j = 1;j <= bagSize;j++){
			if(nums[i] > j)dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]]; 
		}
	}
	return dp[nums.size() - 1][bagSize];
}
int main(){
	return 0;
}