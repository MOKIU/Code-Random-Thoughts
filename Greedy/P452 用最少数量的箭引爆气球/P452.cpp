#include <bits/stdc++.h>
using namespace std;

// 贪心：在起点有序的情况下射击,能中的重叠区间的最小右边界
static bool cmp(const vector<int>&a ,const vector<int>&b){
	return a[0] < b[0];
}
int findMinArrowShots(vector<vector<int>>& points){
	int arrowNum = 1; // 后续最后一个重叠箭/单独箭不会加上,所以加上,或者可以理解为起始就有一个
	// 将points按起点排序,学会使用sort函数
	sort(points.begin(), points.end(), cmp);
	int minRightB = points[0][1]; // 目前最小右边界
	for(int i = 0;i < points.size() - 1;i++){
		// 只有在最小右边界小于后一个左边界时才证明不重叠,箭数才加1
		if(minRightB < points[i+1][0]){
			arrowNum++;
			minRightB = points[i+1][1];
		}else if(minRightB > points[i+1][1]){
			// 起始气球右边界比后一个大,找最小右边界
			minRightB = points[i+1][1]; // 更新最小右边界,不射击
		}
	}
	return arrowNum;
}
int main(){
	return 0;
}