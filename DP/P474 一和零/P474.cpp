#include <bit/stddc++.h>
using namespace std;

// 01背包问题,只不过重量有两个维度(m,n)
// dp[i][j]：m容量为i(0),n容量为j(1)的背包最多子集个数
int findMaxForm(vector<string>& strs, int m,int n){
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for(string str: strs){
		int oneNum = 0, zeroNum = 0;
		for(char c : str){
			if(c == '1')oneNum++;
			else zeroNum++;
		}
		for(int i = m;i >= zeroNum;i--){
			for(int j = n;j >= oneNum;j--){
				dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
			}
		}
	}
	return dp[m][n];
}
int main(){
	return 0;
}