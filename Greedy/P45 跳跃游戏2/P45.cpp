#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums){
	if(nums.size() == 1)return 0;
	int curDistance = 0;
	int ans = 0;
	int nextDistance = 0;
	for(int i = 0;i < nums.size();i++){
		nextDistance = max(nums[i] + i, nextDistance);
		if(i == curDistance){
			ans++;
			curDistance = nextDistance;
			if(nextDistance >= nums.size() - 1)break;
		}
	}
	return ans;
}
int main(){
	return 0;
}