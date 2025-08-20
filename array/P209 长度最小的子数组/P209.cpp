#include <bits/stdc++.h>
using namespace std;

// 此题对子数组理解有误,子数组必须是原数组的一个连续片段
// 下面这个方法当数据量大时会爆tle
// int minSubArrayLen(int target, vector<int>& nums) {
	// int len = nums.size();
	// for(size_t i = 0;i < nums.size();i++){
		// int value = target;
		// for(size_t j = i;j < nums.size();j++){
			// value -= nums[j];
			// if(value <= 0 && j-i+1 < len){
				// len = j-i+1;
				// break;
			// }
		// }
	// }
	// if(len < nums.size()){
		// return len;
	// }else{
		// int tmp = target;
		// for(size_t i = 0;i < nums.size();i++){
			// tmp -= nums[i];
		// }
		// if(tmp <= 0)return len;
		// else return 0;
	// }
// }

// 本题使用滑动窗口解决,上述方法我每次移动窗口左边界时都重新计算和,这样导致了重复计算现象 
// 下面用的方法避免了重复计算,移动边界后两个重复的部分不用重新加和,只需减去上一个左边界在从有边界往后加和即可
int minSubArrayLen(int target, vector<int>& nums){
    int left = 0;
    int len = INT_MAX;
    int sum = 0;
    for (size_t right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum >= target) {
            int tmp = right - left + 1;
            len = len < tmp ? len : tmp;
            sum -= nums[left++];
        }
    }
    return len == INT_MAX ? 0 : len;
}

int main(){
	vector<int> arr = {12,28,83,4,25,26,25,2,25,25,25,12};
	cout << minSubArrayLen(213, arr) << endl;
}