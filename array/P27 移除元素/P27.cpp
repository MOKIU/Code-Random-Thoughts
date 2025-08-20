#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/remove-element/description/
int removeElement(vector<int>& nums, int val){
	int res = 0;
	int k = nums.size();
	for(int i = 0;i < k;i++){
		if(nums[i] == val){
			for(int j = i + 1;j < k;j++){
				nums[j - 1] = nums[j]; 
			}
			i--;
			k--;
		}else{
			res++;
		}
	}
	return res;
}


int main(){
	vector<int> nums = {3,13,5,12,1,2,3};
	int res = removeElement(nums, 3);
	cout << res;
}