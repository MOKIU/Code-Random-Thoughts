#include <bits/stdc++.h>
using namespace std;

// dp1[i]:0-i选i的连续子数组最大值
// dp2[i]:0-i选i的连续子数组最小值
// 如上设计的原因是因为数有正负,防止遗漏负数造成一些最大结果的形成,即负负得正
int maxProduct(vector<int>& nums) {
    vector<int> dp1(nums.size());
    vector<int> dp2(nums.size());
    // 初始化都是第一个元素
    dp1[0] = nums[0];
    dp2[0] = nums[0];
    
    int max = dp1[0];
    for(int i = 1;i < nums.size();i++){
    	if(nums[i] > 0){
    		dp1[i] = dp1[i-1] > 0 ? dp1[i-1] * nums[i] : nums[i];
    		dp2[i] = dp2[i-1] < 0 ? dp2[i-1] * nums[i] : nums[i];
    	}else if(nums[i] < 0){
    		dp1[i] = dp2[i-1] < 0 ? dp2[i-1] * nums[i] : nums[i];
    		dp2[i] = dp1[i-1] > 0 ? dp1[i-1] * nums[i] : nums[i];
    	}else{
    		dp1[i] = 0;
    		dp2[i] = 0;
    	}
    	if(max < dp1[i]){max = dp1[i];}
    }
    
    return max;
}