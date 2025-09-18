#include <bits/stdc++.h>
using namespace std;

// 第一版本思路：使用两个multiset,分别存储两个数组的两两加和,所以规模大概n*n大小,前面两层for循环的时间复杂度是O(n^2)
// 而后两层循环遍历的都是大小为n*n大小的数组,所以后两层的for循环时间复杂度为O(n^4)
// 为什么选择multiset：因为想要将两数组不同位置的加和都放进set中用于后续比较,只存储一个加和值,并且要求该数可重复
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                 vector<int>& nums4)
{
    int n = nums1.size();
    multiset<int> mset1;
    multiset<int> mset2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mset1.insert(nums1[i] + nums2[j]);
            mset2.insert(nums3[i] + nums4[j]);
        }
    }
    int count = 0;
    // 仅遍历map的键
    for (auto it = mset1.begin(); it != mset1.end(); ++it)
    {
        for (auto st = mset2.begin(); it != mset2.end(); ++it)
        {
            if (mset1.find((*st) * (-1)) != mset1.end())
            {
                count++;
            }
        }
    }
    return count;
}

// 第二版本思路：使用一个unordered_map,键值用于存储数组加和,及该加和出现的次数,方便后续的输出
// 数据结构改用为map后,存储元素大大减小,时间复杂度也减少
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                 vector<int>& nums4)
{
    int all_count = 0;
    int n = nums1.size();
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            auto it = umap.find(nums1[i] + nums2[j]);
            if (it != umap.end())
            {
                it->second += 1;
            }
            else
            {
                umap.insert(pair<int, int>(nums1[i] + nums2[j], 1));
            }
        }
    }
    // 第二次循环找两个map中为相反数
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            auto it = umap.find(0 - (nums3[i] + nums4[j]));
            if (it != umap.end())
            {
                all_count += it->second;
            }
        }
    }
    return all_count;
}
int main(){return 0}