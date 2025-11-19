#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    unordered_set<int> uset; // 无序不可重复
    int index = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (nums1[i] == nums2[j])
            {
                uset.insert(nums1[i]); // 复杂度一般按平均O(1)估算
            }
        }
    }
    vector<int> arr(uset.size());
    for (int tmp : uset)
    {
        arr[index++] = tmp;
    }
    return arr;
}
// 时间复杂度改进:由O(n^2)改进到O(n)
vector<int> intersection(vector<int> nums1, vector<int> nums2)
{
    unordered_set<int> result_set;
        // 数组和set可以互相转化
    unordered_set<int> nums_set(nums1.begin(), nums1.end());
    for (int num : nums2)
    {
        if (nums_set.find(num) != nums_set.end())
        {
            result_set.insert(num);
        }
    }
    return vector<int>(result_set.begin(), result_set.end());
}
int main()
{
    return 0;
}