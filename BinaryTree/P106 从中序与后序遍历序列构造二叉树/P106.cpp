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
void traversal(TreeNode*& root, vector<int> inorder, vector<int> postorder){
	int size = postorder.size();
	if(size == 0)return;
	// 首先先找到后序数组的最后一个元素,作为分割中序数组的标记
	int insplit = postorder[size-1];
	int isplitindex = find(inorder.begin(), inorder.end(), insplit) - inorder.begin();
	vector<int> inleft;
	vector<int> inright;
	// 利用标记得到中序数组的左分支数组和右分支数组
	for(int i = 0;i < size;i++){
		if(i < isplitindex)inleft.push_back(inorder[i]);
		if(i > isplitindex)inright.push_back(inorder[i]);
	}
	// 对应得到后序数组的左分支数组和后分支数组
	postorder.resize(postorder.size()-1);
	vector<int> pleft(postorder.begin(), postorder.begin()+inleft.size());
	vector<int> pright(postorder.begin()+inleft.size(), postorder.end());
	// for(int i = 0;i < size;i++){
		// if(find(inleft.begin(), inleft.end(), postorder[i]) != inleft.end()){
			// pleft.push_back(postorder[i]);
		// }else if(find(inright.begin(), inright.end(), postorder[i]) != inright.end()){
			// pright.push_back(postorder[i]);
		// }
	// }
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	// 由后序数组的左分支数组和后分支数组的最后一个元素确定左右子节点
	if(pleft.size() != 0){
		left = new TreeNode(pleft[pleft.size()-1]);
	}
	if(pright.size() != 0){
		right = new TreeNode(pright[pright.size()-1]);
	}
	root->left = left;
	root->right = right;
	traversal(root->left, inleft, pleft);
	traversal(root->right, inright, pright);
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
	// 首先先找到后序数组的最后一个元素,作为分割中序数组的标记
	int size = postorder.size();
	if(size == 0)return nullptr;
	TreeNode* root = new TreeNode(postorder[size-1]);
	traversal(root, inorder, postorder);
	return root;
}
int main(){
	return 0;
}