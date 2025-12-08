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
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    queue<TreeNode*> que;
    vector<vector<int>> res;
    if (root != nullptr) que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vector<int> tmp;
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = que.front();
            tmp.push_back(node->val);
            que.pop();
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        res.push_back(tmp);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    return 0;
}