#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {};
};
TreeNode* constructMaximumBinaryTree(vector<int>& nums){
	TreeNode* node = new TreeNode(0);
	if(nums.size() == 1){
		node->val = nums[0];
		return node;
	}
	int maxIndex = 0;
	int max = nums[0];
	for(int i = 0;i < nums.size();i++){
		if(nums[i] > max){
			maxIndex = i;
			max = nums[i];
		}
	}
	node->val = nums[maxIndex];
	vector<int> left(nums.begin(), nums.begin()+maxIndex);
	vector<int> right(nums.begin()+maxIndex+1, nums.end());
	if(left.size() != 0)node->left = constructMaximumBinaryTree(left);
	if(right.size() != 0)node->right = constructMaximumBinaryTree(right);
	return node;
}
int main(){
	return 0;
}