#include <bits/stdc++.h>
using namespace std;

// 使用单调队列解题,出口元素最大front,入口元素最小back
// 而使用双端队列最为合适,因为可能需要从入口弹出元素,这是queue实现不了的
// 并且常用的queue在没有指定容器的情况下,deque就是默认底层容器
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    deque<int> dq;
    vector<int> res;
    int count = nums.size() - k + 1;
    for (int i = 0; i < k; i++)
    {
        if (dq.empty())
            dq.push_back(nums[i]);
        else if (dq.back() >= nums[i])
            dq.push_back(nums[i]);
        else
        {
            while (!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
        }
    }
    res.push_back(dq.front());
    for (int i = k; i < nums.size(); i++)
    {
        if (dq.front() == nums[i - k]) dq.pop_front();
        if (dq.empty())
            dq.push_back(nums[i]);
        else if (dq.back() >= nums[i])
            dq.push_back(nums[i]);
        else
        {
            while (!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
        }
        res.push_back(dq.front());
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> res = maxSlidingWindow(nums, 3);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}