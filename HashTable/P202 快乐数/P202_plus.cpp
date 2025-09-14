#include <bits/stdc++.h>
using namespace std;

int getSum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}
bool isHappy(int n)
{
    unorder_set<int> set;
    while (1)
    {
        int sum = getSum(n);
        if (sum == 1)
        {
            return true;
        }
        // 因为平方和数是有限的,所以出现死循环(不快乐数)的必要条件是在计算平方和数出现了重复的情况
        if (set.find(sum) != set.end())
        {
            return false;
        }
        else
        {
            set.insert(sum);
        }
        n = sum;
    }
}
int main()
{
    return 0;
}