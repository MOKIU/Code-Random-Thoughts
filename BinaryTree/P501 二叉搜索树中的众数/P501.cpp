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
int maxCount = 0;
int count = 0;
TreeNode* pre = nullptr;
vector<int> result;
void traversal(TreeNode* cur){
	if(cur == nullptr)return;
	
	traversal(cur->left);
	
	if(pre == nullptr){
		count = 1;
	}else if(pre->val == cur->val){
		count++;
	}else{
		count = 1;
	}
	pre = cur;
	
	if(count == maxCount){
		result.push_back(cur->val);
	}
	
	if(count > maxCount){
		maxCount = count;
		result.clear();
		result.push_back(cur->val);
	}
	
	traversal(cur->right);
}
vecotr<int> findMode(TreeNode* root){
	count = 0;
	maxCount = 0;
	pre = nullptr;
	result.clear();
	traversal(root);
	return result;
}
int main(){
	return 0;
}