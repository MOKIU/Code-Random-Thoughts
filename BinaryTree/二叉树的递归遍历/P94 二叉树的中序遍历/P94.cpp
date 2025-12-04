#include <bits/stdc++.h>
using namespace std;
// 中序遍历
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
void traversal(TreeNode* cur, vector<int>& vec)
{
    if (cur == nullptr) return;
    traversal(cur->left, vec);
    vec.push_back(cur->val);
    traversal(cur->right, vec);
}
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> res;
    traversal(root, res);
    return res;
}
int main()
{
    return 0;
}