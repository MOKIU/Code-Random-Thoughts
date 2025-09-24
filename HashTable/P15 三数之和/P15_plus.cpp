#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        { // a,b,c可定都大于0,没有符合条件的
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1])
        { // 确保a的唯一性
            continue;
        }
                // 这个set的作用是存储b
        unordered_set<int> set;

        for (int k = i + 1; k < nums.size(); k++)
        {
            if (k > i + 2 && nums[k] == nums[k - 1] &&
                nums[k - 1] == nums[k - 2])
            {
                continue;
            }
            int target = 0 - (nums[i] + nums[k]); // target可能是b，也可能是c
            if (set.find(target) != set.end())
            { // 找到能用的b
                result.push_back({nums[i], target, nums[k]}); // nums[k]成为c
                set.erase(
                    target); // 唯一的a，唯一的b，对应唯一的c，这个b已经用过了，就无利用价值了
            }
            else
            {
                set.insert(nums[k]); // nums[k]成为b
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    threeSum(nums);
    return 0;
}