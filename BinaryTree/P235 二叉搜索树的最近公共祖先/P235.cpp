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
        : val(x), left(left), right(right)
    {
    }
};
// 由于二叉搜索树的特性,从上向下遍历,遇到的第一个节点值在p和q之间的就是最近公共祖先
// 最近公共祖先肯定是p,q分别位于左右子树,假设不是最近,下面还有公共子树,那该节点值就不可能位于两节点值之间
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root == nullptr) return root;
    if (root->val > p->val && root->val > q->val)
    {
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        if (left != nullptr)
        {
            return left;
        }
    }
    if (root->val < p->val && root->val < q->val)
    {
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (right != nullptr)
        {
            return right;
        }
    }
    return root;
}
int main()
{
    return 0;
}