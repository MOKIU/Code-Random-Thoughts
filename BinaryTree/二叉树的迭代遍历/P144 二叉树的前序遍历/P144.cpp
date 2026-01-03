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
        : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode* root)
{
        // 迭代遍历,先把节点放入栈中,出栈时放入数组,再放右孩子入栈,再放左孩子入栈
    stack<TreeNode*> st;
    vector<int> res;
    if (root == nullptr) return res;
    st.push(root);
    while (!st.empty())
    {
        res.push_back(st.top()->val);
        TreeNode* left = st.top()->left;
        TreeNode* right = st.top()->right;
        st.pop();
        if (right != nullptr) st.push(right);
        if (left != nullptr) st.push(left);
    }
    return res;
}
int main()
{
    return 0;
}