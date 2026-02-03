#include <bits/stdc++.h>
using namespace std;

static bool cmp(const vector<int>&a, const vector<int>&b){
	return a[1] < b[1];
}
// 看右边界,根据右边界确定该区间多重叠多少个区间,多重叠的都是要删除的
// 所以多重叠的个数就是答案
int eraseOverlapIntervals(vector<vector<int>>& intervals){
	int res = 0;
	sort(intervals.begin(), intervals.end(), cmp);
	int minRightB = intervals[0][1];
	for(int i = 0;i < intervals.size() - 1;i++){
		if(minRightB > intervals[i+1][0]){
			res++;
		}else{
			minRightB = intervals[i+1][1]; 
		}
	}
	return res;
}
int main(){
	return 0;
}