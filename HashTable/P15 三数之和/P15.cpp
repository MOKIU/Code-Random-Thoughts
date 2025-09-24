#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    set<vector<int>> uset;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[j];
                    tmp[2] = nums[k];
                    std::sort(tmp.begin(), tmp.end());
                    if (uset.find(tmp) == uset.end())
                    {
                        uset.insert(tmp);
                    }
                }
            }
        }
    }
    vector<vector<int>> result(uset.size());
    int index = 0;
    for (auto vnums : uset)
    {
        vector<int> tmp(3);
        std::copy(vnums.begin(), vnums.end(), std::begin(tmp));
        result[index++] = tmp;
    }
    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    threeSum(nums);
    return 0;
}