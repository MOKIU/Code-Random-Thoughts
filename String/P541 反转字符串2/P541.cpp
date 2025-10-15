#include <bits/stdc++.h>
using namespace std;

string reverseStr(string s, int k)
{
    if (s.size() <= k)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            int tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
    else
    {
        // 核心思路就是构建双指针,两个指针位于k个连续元素的首尾,然后通过不断判断右指针是否超过边界
        // 如果超过就进入下一个重复流程,如果没超过就特殊处理,分为 1~k 和
        // k+1~2k两种形式
        int size = s.size();
        int left;
        int right = -1 * k - 1;
        do
        {
            left = right + k + 1;
            right += 2 * k;
            cout << "left:" << left << " right:" << right << endl;
            int tmp_left = left;
            int tmp_right = right;
            while (tmp_left < tmp_right)
            {
                int tmp = s[tmp_left];
                s[tmp_left] = s[tmp_right];
                s[tmp_right] = tmp;
                tmp_left++;
                tmp_right--;
            }
            size -= 2 * k;
        } while (size >= k);
        left = right + k + 1;
        right = s.size() - 1;
        // 剩下size个还没处理
        while (left < right)
        {
            int tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
    return s;
}
int main()
{
    string s = "abcdefg";
    int k = 4;
    cout << reverseStr(s, k) << endl;
    return 0;
}
