#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums)
{
    int n = nums.size();
    vector<int> res(n);
    int i = 0;
    int j = n - 1;
    int k = n - 1;
    for (size_t l = 0; l < nums.size(); l++)
    {
        nums[l] *= nums[l];
    }
        // i <= j 要相等,否则会落掉一个元素
    while (i <= j)
    {
        if (nums[i] < nums[j])
        {
            res[k--] = nums[j];
            j--;
        }
        else
        {
            res[k--] = nums[i];
            i++;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-10000, -9999, -7, -5, 0, 0, 10000};
    vector<int> arr = sortedSquares(nums);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
}