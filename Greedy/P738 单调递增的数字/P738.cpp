#include <bits/stdc+.h>
using namespace std;

// 贪心:从后往前比较,两个数字间只要前比后大,则前-1,后面全变成9
// 存到数组就是前到后遍历,这样后续一些操作也更方便易懂
int monotoneIncreasingDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    vector<int> digit;
    int res = 0;
    while (n)
    {
        digit.push_back(n % 10);
        n /= 10;
    }
    for (int i = 0; i < digit.size() - 1; i++)
    {
        if (digit[i] < digit[i + 1])
        {
            digit[i + 1] -= 1;
            int count = i;
            while (count >= 0)
            {
                digit[count] = 9;
                count--;
            }
        }
    }
        // 第一位是'0',则消除该位
    if (digit[digit.size() - 1] == 0)
    {
        digit.resize(digit.size() - 1);
    }
        // 还原结果
    for (int i = digit.size() - 1; i >= 0; i--)
    {
        res += digit[i] * pow(10, i);
    }
    return res;
}
int main()
{
    return 0;
}