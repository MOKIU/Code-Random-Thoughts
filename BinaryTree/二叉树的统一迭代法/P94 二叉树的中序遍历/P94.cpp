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
// 放入栈的顺序是放入结果集的倒序
// 先放右节点,再放中节点,然后放空指针,最后放左节点
// 遇到null说明两种情况:1.没有左右孩子了 2.中节点
// 第一种情况代表可以直接加入结果集了
// 第二种情况代表前面的左节点都加入完了,该加入中节点了,也可直接加入结果集
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
            st.push(node);
            st.push(nullptr);
            if (node->left) st.push(node->left);
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