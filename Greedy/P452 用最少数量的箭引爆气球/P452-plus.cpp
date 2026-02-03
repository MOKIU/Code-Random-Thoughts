#include <bits/stdc++.h>
using namespace std;

static bool cmp(const vector<int>&a ,const vector<int>&b){
	return a[1] < b[1];
}
int findMinArrowShots(vector<vector<int>>& points){
	int arrowNum = 1;
	sort(points.begin(), points.end(), cmp);
	int minRightB = points[0][1];
	for(int i = 0;i < points.size() - 1;i++){
		if(minRightB < points[i+1][0]){
			arrowNum++;
			minRightB = points[i+1][1];
		}
	}
	return arrowNum;
}
int main(){
	return 0;
}