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
// 两种写法,返回值不同
int traversal(TreeNode* cur, bool isLeft){
	if(!cur)return 0;
	if(cur->left == nullptr && cur->right == nullptr){
		if(isLeft)return cur->val;
		else return 0;
	}
	return traversal(cur->left, true) + traversal(cur->right, false);
}
void traversal(TreeNode* cur, bool isLeft, int& result){
	if(!cur)return;
	if(cur->left == nullptr && cur->right == nullptr){
		if(isLeft)result += cur->val;
		return;
	}
	traversal(cur->left, true, result);
    traversal(cur->right, false, result);
}
int sumOfLeftLeaves(TreeNode* root){
	int result = 0;
	traversal(root, false, result);
	return result;
	// return traversal(root, false);
}
int main(){
	return 0;
}