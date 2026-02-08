#include <bits/stdc++.h>
using namespace std;

// // 计算阶乘,用于计算组合数据
// int factorial(int n){
	// if(n == 1 || n == 0)return 1;
	// return n * factorial(n-1);
// }
// // dp[i]:n=i时二叉搜索树状态个数
// // 因为新增的永远比前一个大,所以加的地方是固定的,要么右上角,要么右下角,要么两个都有
// // 除此次意外,还会在中间插入,只加载右分支,看右分支孩子,从上到下是有序的才能折断中间插入(sum)
// int numTrees(int n){
	// if(n == 1)return 1;
	// vector<int> dp(n + 1);
	// dp[1] = 1;
	// for(int i = 2;i <= n;i++){
		// int sum = 0;
		// for(int j = i - 2;j >= 1;j--){
			// int k = i - 2 - j;
			// sum += factorial(i-2)/(factorial(k) * factorial(j)) * j;
		// }
		// dp[i] = dp[i-1] * 2 + sum;
	// }
	// return dp[n];
// }
int numTrees(int n){
	vector<int> dp(n + 1);
	dp[0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}
	return dp[n];
}
int main(){
	return 0;
}