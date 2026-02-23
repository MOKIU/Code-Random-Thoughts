#include <bit/stdc++.h>
using namespace std;

// 参数列表的k:要找的下标为k的元素
int quickSelect(vector<int> nums, int l, int r, int k){
	if(l == r)return nums[l]; // 说明要找的元素就是这个只有一个元素的区间,此时k=l=r
	int i = l - 1; // 找大于划分值的元素指针
	int j = r + 1; // 找小于划分值的元素指针
	int partition = nums[l];
	while(i < j){
		do i++; while(nums[i] < partition); // 这一步顺便把第一个划分值元素也交换到中间去了
		do j--; while(nums[j] > partition);
		if(i < j)swap(nums[i], nums[j]);
	}A
	if(k <= j)return quickSelect(nums, l, j, k);
	else return quickSelect(nums, j + 1, r, k);
}
int findKthLargest(vector<int> nums, int k){
	int n = nums.size();
	return quickSelect(nums, 0, n - 1, n - k); // n - k为下标
}
int main(){
	return 0;
}