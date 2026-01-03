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
// 利用二叉搜索树的中序遍历是一个递增序列这一顺序来实现
vector<int> vec;
void traversal(TreeNode* cur){
	if(cur == nullptr)return;
	traversal(cur->left);
	vec.push_back(cur->val);
	traversal(cur->right);
}
bool isVaildBST(TreeNode* root){
	if(root == nullptr)return false;
	traversal(root);
	for(int i = 1;i < vec.size();i++){
		if(vec[i] <= vec[i - 1])return false;
	}
	return true;
}
int main(){
	return 0;
}