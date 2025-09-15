#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
        auto f = umap.find(target - nums[i]);
        if (f != umap.end())
        {
            return {f->second, i};
        }
        umap.insert(pair<int, int>(nums[i], i));
    }
    return {};
}
int main()
{
    return 0;
}