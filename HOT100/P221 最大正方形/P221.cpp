#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
	int maxSideLength = 0;
	vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
	for(int i = 0;i < matrix.size();i++){
		if(matrix[i][0] == '1'){
			dp[i][0] = 1;
			maxSideLength = 1;
		}
	}
	for(int j = 0;j < matrix[0].size();j++){
		if(matrix[0][j] == '1'){
			dp[0][j] = 1;
			maxSideLength = 1;
		}
	}
	for(int i = 1;i < matrix.size();i++){
		for(int j = 1;j < matrix[0].size();j++){
			if(matrix[i][j] == '1'){
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
			}else{
				dp[i][j] = 0;
			}
			maxSideLength = max(maxSideLength, dp[i][j]);
		}
	}
	return maxSideLength * maxSideLength;
}
int main()
{
    return 0;
}