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
int findBottomLeftValue(TreeNode* root){
	queue<TreeNode*> que;
	int result = 0;
	if(root != nullptr)que.push(root);
	while(!que.empty()){
		TreeNode* node = que.front();
		result = node->val;
		int size = que.size();
		for(int i = 0;i < size;i++){
			node = que.front();
			que.pop();
			if(node->left)que.push(node->left);
			if(node->right)que.push(node->right);
		}
	}
	return result;
}
int main(){
	return 0;
}