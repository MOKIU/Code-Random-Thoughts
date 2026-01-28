#include <bits/stdc++.h>
using namespace std;

// 局部最优规则[0-i]区间累加不会出现负数,如果出现负数则[0-i]都不可以作为起始位置,此时更新起始位置为i+1
// 全局最优就是[0-i]区间覆盖到全局范围
int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
	int curSum = 0;
	int totalSum = 0;
	int start = 0;
	for(int i = 0;i < cost.size();i++){
		curSum += gas[i] - cost[i];
		totalSum += gas[i] - cost[i];
		if(curSum < 0){
			start = i + 1;
			curSum = 0;
		}
	}
	if(totalSum < 0)return  -1;
	return start;
}
int main(){
	return 0;
}