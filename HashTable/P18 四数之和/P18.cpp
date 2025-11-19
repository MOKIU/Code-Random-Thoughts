#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;
std:
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        // 一级剪枝
        if (nums[i] > target && (nums[i] > 0 || target > 0))
        {
            break;
        }
        // 去重
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < nums.size(); j++)
        {
            // 二级剪枝
            if (nums[i] + nums[j] > target && (nums[j] > 0 || target > 0))
            {
                break;
            }
            // 去重
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if ((long)nums[left] + nums[right] + nums[i] + nums[j] < target)
                {
                    left++;
                }
                else if ((long)nums[left] + nums[right] + nums[i] + nums[j] >
                         target)
                {
                    right--;
                }
                else
                {
                    result.push_back(
                        vector<int>{nums[i], nums[j], nums[left], nums[right]});
                    // left去重
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    // right去重
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
    }
    return result;
}
int main()
{
    return 0;
}