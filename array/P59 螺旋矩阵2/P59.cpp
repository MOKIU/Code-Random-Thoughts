#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/spiral-matrix-ii/submissions/655213800/
vector<vector<int>> generateMatrix(int n){
	int count = n - 1;// 用于判断螺旋是否结束
	int len = n - 1;// 用于定位待赋值元素位置
	int num = 1;
	vector<vector<int>> arr(n, vector<int>(n));
	while(count > 0){
		for(size_t j = 0;j < size_t(count);j++){
			arr[n-len-1][j+n-len-1] = num++;
		}
		for(size_t i = 0;i < size_t(count);i++){
			arr[i+n-len-1][len] = num++;
		}
		for(size_t j = len;j > size_t(len - count);j--){
			arr[len][j] = num++;
		}
		for(size_t i = len;i > size_t(len - count);i--){
			arr[i][n-len-1] = num++;
		}
		count -= 2;
		len--;
	}
	if(count == 0){
		arr[n/2][n/2] = num;
	}
	return arr;
}
int main(){
	int n;
	cin >> n;
	vector<vector<int>> res = generateMatrix(n);
	for(size_t i = 0;i < size_t(n);i++){
		for(size_t j = 0;j < size_t(n);j++){
			cout << res[i][j] << " ";
		}
	}
	return 0;
}