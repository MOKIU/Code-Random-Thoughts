#include <bits/stdc++.h>
using namespace std;

static bool cmp(const vector<int>&a, const vector<int>&b){
	return a[0] < b[0];
}
vector<vetor<int>> merge(vector<vector<int>>& intervals){
	vector<vector<int>> res;
	sort(intervals.begin(), intervals.end(), cmp);
	int left = intervals[0][0];
	int right = intervals[0][1];
	for(int i = 0;i < intervals.size() - 1;i++){
		if(right < intervals[i+1][0]){
			res.push_back({left, right});
			left = intervals[i+1][0];
			right = intervals[i+1][1];
		}else{
			right = max(intervals[i+1][1],right);
		}
	}
	res.push_back({left, right});
	return res;
}
int main(){
	return 0;
}