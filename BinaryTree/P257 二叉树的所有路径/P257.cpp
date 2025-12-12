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
void traversal(TreeNode* cur, vector<int>& path, vector<string>& result){
	if(cur->left == nullptr && cur->right == nullptr){
		path.push_back(cur->val);
		string s = "";
		for(int i = 0;i < path.size()-1;i++){
			s += to_string(path[i]);
			s += "->";
		}
		s += to_string(path[path.size()-1]);
		result.push_back(s);
		return;
	}
	path.push_back(cur->val);
	if(cur->left){
		traversal(cur->left, path, result);
		path.pop_back();
	}
	if(cur->right){
		traversal(cur->right, path, result);
		path.pop_back();
	}
}
vector<string> binaryTreePaths(TreeNode* root){
	vector<int> path;
	vector<string> result;
	traversal(root, path, result);
	return result;
}
int main(){
	return 0;
}