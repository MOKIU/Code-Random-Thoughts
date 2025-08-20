#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/binary-search/description/
int search(vector<int>& nums, int target){
	int left = 0;
	int right = nums.size() - 1;
	while(left <= right){
		int mid = (left + right)/2;
		if(nums[mid] > target){
			right = right - 1;
		}else if(nums[mid] < target){
			left = left + 1;
		}else{
			return mid;
		}
	}
	return -1;
}
int main(){
	vector<int> nums = {1,4,8,10,12};
	int result = search(nums,13);
	cout << result;
	return 0;
}