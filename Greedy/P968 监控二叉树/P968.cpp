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
// int num = 0;
// int leefDepth = 0;
// void traversal(TreeNode* root, int depth){
        // if(root == nullptr){return;}
        // traversal(root->left, depth+1);
        // traversal(root->right, depth+1);
        // if(!root->left && !root->right){
                // leefDepth = depth;
        // }
        // if(leefDepth != 0 && depth % 2 != leefDepth % 2){
                // num++;
        // }
// }
int result;
// 巧妙的利用返回值模拟节点是否被覆盖的状态,0,1,2代表三种状态
// 局部最优：从下到上遍历,叶子节点不设摄像头,每隔一个设一个摄像头
int traversal(TreeNode* cur)
{
    if (cur == nullptr) return 2; // 空节点有覆盖
    int left = traversal(cur->left);
    int right = traversal(cur->right);
    if (left == 2 && right == 2) return 0; // 左右节点都被覆盖
    if (left == 0 || right == 0)
    { // 左右节点至少有一个没被覆盖,则设摄像头
        result++;
        return 1;
    }
    if (left == 1 || right == 1) return 2;
    return -1; // 逻辑不会走到这里,随便返回
}
int minCameraCover(TreeNode* root)
{
    result = 0;
    if (traversal(root) == 0)
    { // 根节点左右节点都覆盖,上述回溯不会设摄像头,在此补充,这是关键
        result++;
    }
    return result;
}
int main()
{
    return 0;
}