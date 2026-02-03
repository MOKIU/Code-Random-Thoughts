#include <bits/stdc++.h>
using namespace std;

// 二维递归,每放入一个数字判断是否有效
bool isValid(vector<vector<char>>& board, int raw, int col, char k){
	// 检查同行有没有冲突
	for(int i = 0;i < 9;i++){
		if(board[raw][i] == k){
			return false;
		}
	}
	// 检查同列有没有冲突
	for(int i = 0;i < 9;i++){
		if(board[i][col] == k){
			return false;
		}
	}
	// 检查所处3*3方格有没有冲突
	// 通过/3*3获取所处方格起始点的所在行和列
	int startraw = (raw / 3) * 3;
	int startcol = (col / 3) * 3;
	for(int i = startraw;i < startraw + 3;i++){
		for(int j = startcol;j < startcol + 3;j++){
			if(board[i][j] == k){
				return false;
			}
		}
	}
	return true;
}
bool backtracking(vector<vector<char>>& board){
	for(int i = 0;i < board.size();i++){
		for(int j = 0;j < board[0].size();j++){
			if(board[i][j] != '.')continue;
			for(char k = '1';k <= '9';k++){
				if(isValid(board, i, j, k)){
					board[i][j] = k;
					if(backtracking(board))return true;
					board[i][j] = '.';
				}
			}
			return false;
		}
	}
	return true;
}
void solveSudoku(vector<vector<char>>& board){
	backtracking(board);
}
