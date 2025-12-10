#include <bits/stdc++.h>
using namespace std;

// 迭代后序遍历
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

vector<int> preorderTraversal(TreeNode* root)
{
        // 在前序遍历的基础上修改,由中左右变为右左中的逆置
    stack<TreeNode*> st;
    vector<int> res;
    if (root == nullptr) return res;
    st.push(root);
    while (!st.empty())
    {
        TreeNode* left = st.top()->left;
        TreeNode* right = st.top()->right;
        res.push_back(st.top()->val);
        st.pop();
        if (left != nullptr) st.push(left);
        if (right != nullptr) st.push(right);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    return 0;
}