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
        : val(x), left(left), right(right){}
};
// 反中序遍历
TreeNode* pre = nullptr;
void traversal(TreeNode* cur){
	if(cur == nullptr){
		return;
	}
	traversal(cur->right);
	if(pre){
		cur->val += pre->val;
	}
	pre = cur;
	traversal(cur->left);
}
TreeNode* converBST(TreeNode* root){
	traversal(root);
	return root;
}
int main(){
	return 0;
}