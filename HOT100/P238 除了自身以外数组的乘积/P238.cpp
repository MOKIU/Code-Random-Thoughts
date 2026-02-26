#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
	// O(n)时间,O(1)空间,由于输出数组不占空间复杂度(就是返回数组),所以用输出数组
	// 先作为左乘积存储,然后从后遍历元素计算乘上右乘积得到结果数组
	int length = nums.size();
	vector<int> answer(length);
	answer[0] = 1;
	for(int i = 1;i < length;i++){
		answer[i] = nums[i-1] * answer[i-1];
	}
	int r = 1;
	for(int i = length - 1;i >=0;i--){
		answer[i] *= r;
		r *= nums[i];   
	}
	return answer;
}
int main(){
	return 0;
}