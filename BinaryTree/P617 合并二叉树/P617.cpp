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
TreeNode* traversal(TreeNode*& cur1, TreeNode*& cur2){
	if(cur1 == nullptr)return cur2;
	if(cur2 == nullptr)return cur1;
	cur1->val += cur2->val;
	cur1->left = traversal(cur1->left, cur2->left);
	cur1->right = traversal(cur1->right, cur2->right);
	return cur1;
}
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2){
	return traversal(root1, root2);
}
int main(){
	return 0;
}