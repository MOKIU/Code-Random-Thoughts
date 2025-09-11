#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    unordered_set<int> uset;
    int index = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (nums1[i] == nums2[j])
            {
                uset.insert(nums1[i]);
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
int main()
{
    return 0;
}