#include <bits/stdc++.h>
using namespace std;

int wiggleMaxLength(vector<int>& nums){
	int n = nums.size();
	if(n < 2)return 1;
	int up = 1;
	int down = 1;
	for(int i = 1;i < n;i++){
		if(nums[i] > nums[i-1]){
			up = down + 1;
		}
		if(nums[i] < nums[i-1]){
			down = up + 1;
		}
	}
	return up > down ? up : down;
}
int main(){
	return 0;
}