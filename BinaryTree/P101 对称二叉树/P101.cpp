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
// 我最先想到的是在层序遍历上修改,每一层加到这一层的数组之后,将其反转,然后比较,单个方法可能比较耗时,估计需要三层循环
bool isSymmetric(TreeNode* root){
	queue<TreeNode*> que;
	if(root != nullptr)que.push(root);
	while(!que.empty()){
		vector<TreeNode*> tmp;
		int size = que.size();
		for(int i = 0;i < size;i++){
			TreeNode* node = que.front();
			tmp.push_back(node);
			que.pop();
			if(node != nullptr){
				que.push(node->left);
				que.push(node->right);
			}
		}
		int left = 0;
		int right = tmp.size() - 1;
		while(left < right){
			if(tmp[left] != nullptr && tmp[right] != nullptr && tmp[left]->val != tmp[right]->val)return false;
			if(tmp[left] == nullptr && tmp[right] != nullptr)return false;
			if(tmp[left] != nullptr && tmp[right] == nullptr)return false;
			left++;
			right--;
		}
	}
	return true;
}
int main(){
	return 0;
}