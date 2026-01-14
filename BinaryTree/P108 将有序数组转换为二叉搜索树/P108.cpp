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
TreeNode* traversal(vector<int> nums, int left, int right)
{
    if (left > right) return nullptr;
    int mid = (left + right) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = traversal(nums, left, mid - 1);
    node->right = traversal(nums, mid + 1, right);
    return node;
}
TreeNode* sortArrayToBST(vector<int>& nums)
{
    return traversal(nums, 0, nums.size() - 1);
}
int main()
{
    return 0;
}