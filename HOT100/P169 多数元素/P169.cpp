#include <bits/stdc++.h>
using namespace std;

// 使用O(n)时间复杂度,O(1)空间复杂度
int majorityElement(vector<int>& nums){
	int candidate = -1;
	int count = 0;
	for(int num : nums){
		if(num == candidate){
			count++;
		}else if(--count < 0){
			candidate = num;
			count = 1;
		}
	}
	return candidate;
}
int main(){
	return 0;
}