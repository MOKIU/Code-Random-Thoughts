#include <bits/stdc++.h>
using namespace std;

// 非常巧妙的位运算
int singleNumber(vector<int>& nums) {
	int ret = 0;
	for(int num : nums){
		ret ^= num;
	}
	return ret;
}
int main(){
	return 0;
}