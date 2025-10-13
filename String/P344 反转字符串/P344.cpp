#include <bits/stdc++.h>
using namespace std;

// 从前向后遍历,从后向前遍历 两两交换
void reverseString(vector<char>& s)
{
    int left = 0;
    int right = s.size() - 1;
    while (left < right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}
int main()
{
    return 0;
}