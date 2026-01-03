#include <bits.stdc++.h>
using namespace std;

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
vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
    stack<TreeNode*> st;
    if (root != nullptr) st.push(root);
    while (!st.empty())
    {
        TreeNode* node = st.top();
        if (node != nullptr)
        {
            st.pop(); // 把重复放入的中节点pop出去
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            st.push(node);
            st.push(nullptr);
        }
        else
        { // 没有子节点了或者是中节点
            st.pop();
            res.push_back(st.top()->val);
            node = st.top();
            st.pop();
        }
    }
    return res;
}
int main()
{
    return 0;
}