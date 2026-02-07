#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    vector<int> dp(n + 1); // 下标含义：上第i层有dp[i]种方法
    if (n == 1) return 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    return 0;
}