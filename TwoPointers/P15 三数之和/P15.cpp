#include <bits/stdc++.h>
using namespace std;

// 使用双指针解决问题
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {// 去重a
            continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[i] + nums[left] + nums[right] < 0)
                left++;
            else if (nums[i] + nums[left] + nums[right] > 0)
                right--;
            else
            {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            }
        }
    }
    return result;
}
int main()
{
    return 0;
}