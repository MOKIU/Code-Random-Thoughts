#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>&nums, int target){
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	for(int i = 0;i < (int)nums.size() - 3;i++){
		if(nums[i] > target && (nums[i] >= 0 || target >= 0)){
			break;
		}
		if(i > 0 && nums[i] == nums[i - 1]){// a去重
			continue;
		}
		for(int j = i + 1;j < (int)nums.size() - 2;j++){
			if(nums[i] + nums[j] > target && (nums[j] >= 0 || target >= 0)){
				break;
			}
			if(j > i + 1 && nums[j] == nums[j - 1]){// b去重
				continue;
			}
			int left = j + 1;
			int right = nums.size() - 1;
			while(left < right){
				if((long)nums[i] + nums[j] + nums[left] + nums[right] < target)left++;
				else if((long)nums[i] + nums[j] + nums[left] + nums[right] > target)right--;
				else{
					result.push_back({nums[i], nums[j], nums[left], nums[right]});
					while(left < right && nums[left] == nums[left + 1])left++;
					while(left < right && nums[right] == nums[right - 1])right--;
					left++;
					right--;
				}
			}
		}
	}
	return result;
}
int main(){
	return 0;
}