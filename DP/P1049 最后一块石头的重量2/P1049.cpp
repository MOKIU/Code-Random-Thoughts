#include<bits/stdc++.h>
using namespace std;

// dp[i]：容量为i的背包能装石块的最大价值
int lastStoneWeight2(vector<int>& stones){
	int sum = 0;
	for(int i = 0;i < stones.size();i++){
		sum += stones[i];
	}
	int bagweight = sum / 2;
	vector<int> dp(bagweight + 1, 0);
	for(int i = 0;i < stones.size();i++){
		for(int j = bagweight;j >= stones[i];j--){
			dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
		}
	}
	return (sum - dp[bagweight]) - dp[bagweight];
}
int main(){
	return 0;
}  