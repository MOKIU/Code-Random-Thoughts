#include <bits/stdc++.h>
using namespace std;

void traversal(TreeNode* cur, int& sum, int targetSum, bool& result){
	if(!cur)return;
	if(cur->left == nullptr && cur->right == nullptr){
		sum += cur->val;
		if(sum == targetSum)result = true;
		return;
	}
	sum += cur->val;
	if(cur->left){
		traversal(cur->left, sum, targetSum, result);
		sum -= cur->left->val;
	}
	if(cur->right){
		traversal(cur->right, sum, targetSum, result);
		sum -= cur->right->val;
	}
}
bool hasPathSum(TreeNode* root, int targetSum){
	int sum = 0;
	bool result = false;
	traversal(root, sum, targetSum, result);
	return result;
}
int main(){
	return 0;
}