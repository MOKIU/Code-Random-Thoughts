#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> result;
// 因为放入该Q时,raw以下的行还没放皇后所以不用检查
bool isVaild(vector<string> path, int raw, int col, int n){
	// 判断是否有同列
	for(int i = raw-1;i >= 0;i--){
		if(path[i][col] == 'Q'){
			return false;
		}
	}
	// 判断是否有同左斜边
	for(int i = raw-1, j = col+1;i >= 0 && j < n;i--, j++){
		if(path[i][j] == 'Q'){
			return false;
		}
	}
	// 判断是否有同右斜边
	for(int i = raw-1, j = col-1;i >= 0 && j >= 0;i--, j--){
		if(path[i][j] == 'Q'){
			return false;
		}
	}
	return true;
}
void backtracking(int n, int raw, vector<string> path){
	if(raw == n){
		result.push_back(path);
		return;
	}
	for(int col = 0;col < n;col++){
		path[raw][col] = 'Q';
		if(isVaild(path, raw, col, n)){
			backtracking(n, raw+1, path);
		}else{
			path[raw][col] = '.';
			continue;
		}
		path[raw][col] = '.';
	}
}
vector<vector<string>> solveNQueens(int n){
	vector<string> tmp(n, string(n, '.'));
	backtracking(n, 0, tmp);
	return result;
}
int main(){
	return 0;
}