#include <bits/stdc++.h>
using namespace std;
// 先序遍历
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
void traversal(TreeNode* cur, vector<int>& vec)
{
    if (cur == nullptr) return;
    vec.push_back(cur->val);
    traversal(cur->left, vec);
    traversal(cur->right, vec);
}
vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> res;
    traversal(root, res);
    return res;
}
int main()
{
    return 0;
}