#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right);
};

int result = INT_MAX;
TreeNode* pre = nullptr;
void traversal(TreeNode* cur){
	if(cur == nullptr)return;
	traversal(cur->left);
	if(pre != nullptr){
		result = min(result, cur->val - pre->val);
	}
	pre = cur;
	traversal(cur->right);
}
int getMinimumDifference(TreeNode* root){
	traversal(root);
	return result;
}
int main(){
	return 0;
}