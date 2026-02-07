#include <bits/stdc++.h>
using namespace std;

//dp[i]：分拆数字i，可以得到的最大乘积为dp[i]
int integerBreak(int n){
	vector<int> dp(n+1);
	dp[1] = 0;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= i/2;j++){
			dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
		}
	}
	return dp[n];
}
int main(){
	return 0;
}