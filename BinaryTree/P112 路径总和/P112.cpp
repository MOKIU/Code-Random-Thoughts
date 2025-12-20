#include <bits/stdc++.h>
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