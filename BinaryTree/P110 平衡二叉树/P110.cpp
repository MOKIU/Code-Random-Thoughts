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
// 平衡二叉树:每个节点的左右两个子树的高度差绝对值不超过1
// 写程序的时候有个疑问,为什么左右两个子树的高度差绝对值不超过1就满足
// 以这个节点为根节点的二叉树是平衡二叉树
// 如果左子树有一条最短边,右子树有一条最长边,那么他们的差会不会超过1呢
// 好像理解错误了,二叉树的定义就是左右子树高度(最长的边)相减
int getHeight(TreeNode* node){
	if(node == nullptr){
		return 0;
	}
	int leftHeight = getHeight(node->left);
	if(leftHeight == -1)return -1;
	int rightHeight = getHeight(node->right);
	if(rightHeight == -1)return -1;
	if(abs(leftHeight - rightHeight) > 1)return -1;
	else return 1 + max(leftHeight, rightHeight);
}
bool isBalanced(TreeNode* root){
	if(getHeight(root) == -1)return false;
	else return true;
}
int main(){
	return 0;
}