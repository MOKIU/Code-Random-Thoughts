#include <bits/stdc++.h>
using namespace std;

// 一直更新更够到达的最远目的地
bool canJump(vector<int>& nums){
	int cover = 0;
	if(nums.size() == 1)return true;
	for(int i = 0;i <= cover;i++){
		cover = max(i + nums[i], cover);
		if(cover >= nums.size() - 1)return true;
	}
	return false;
}
int main(){
	return 0;
}