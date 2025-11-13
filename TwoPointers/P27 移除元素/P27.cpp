#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
    {
        if (val != nums[fastIndex])
        {
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    return slowIndex;
}
int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    cout << removeElement(nums, val) << endl;
}
