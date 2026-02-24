#include<bits/stdc++.h>
using namespace std;

// dp[i][j]:表示i+1行j+1列方格的岛屿数量
void dfs(vector<vector<char>>& grid, int i, int j){
	if(!inArea(grid, i, j))return;
	if(grid[i][j] == '1'){
		grid[i][j] = '2';
		dfs(grid, i-1, j);
		dfs(grid, i+1, j);
		dfs(grid, i, j-1);
		dfs(grid, i, j+1);
	}
}
bool inArea(vector<vector<char>>& grid, int i, int j){
	int n = grid.size();
	int m = grid[0].size();
	if(i < 0 || i > n-1 || j < 0 || j > m-1){
		return false;
	}
	return true;
}
int numIslands(vector<vector<char>>& grid){
	int res = 0;
	int n = grid.size();
	int m = grid[0].size();
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(grid[i][j] == '1'){
				res++;
				dfs(grid, i, j);
			}
		}
	}
	return res;
	// vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
	// // 初始化
	// dp[0][0] = grid[0][0] - '0';
	// for(int j = 1;j < grid[0].size();j++){
		// if(grid[0][j-1] == '0' && grid[0][j] == '1'){
			// dp[0][j] = dp[0][j-1] + 1;
		// }else{
			// dp[0][j] = dp[0][j-1];
		// }
	// }
	// for(int i = 1;i < grid.size();i++){
		// if(grid[i-1][0] == '0' && grid[i][0] == '1'){
			// dp[i][0] = dp[i-1][0] + 1;
		// }else{
			// dp[i][0] = dp[i-1][0];
		// }
	// }
	// for(int i = 1;i < grid.size();i++){
		// for(int j = 1;j < grid[0].size();j++){
			// if(grid[i][j - 1] == '0' && grid[i-1][j] == '0' && grid[i][j] == '1'){
				// dp[i][j] = dp[i-1][j-1] + (dp[i-1][j] - dp[i-1][j-1]) + (dp[i][j-1] - dp[i-1][j-1]) + 1;
			// }else if(grid[i][j - 1] == '1' && grid[i-1][j] == '1' && grid[i][j] == '1'){
				// // 这个考虑情况太复杂了就不知道怎么走了
			// }else{
				// dp[i][j] = dp[i-1][j-1] + (dp[i-1][j] - dp[i-1][j-1]) + (dp[i][j-1] - dp[i-1][j-1]);
			// }
		// }
	// }
	// return dp[grid.size()-1][grid[0].size()-1];
}
int main(){
	return 0;
}