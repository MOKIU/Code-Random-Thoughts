#include <bits/stdc++.h>
using namespace std;

// KMP算法经典题目 构建next数组
vector<int> getNext(string s)
{
    int n = s.size();
    vector<int> next(n, 0);
    int j = 0;
    next[0] = -1; // 初始化为-1，表示该位置字符匹配失败跳转到-1位置
    if (n > 1) next[1] = 0;
    for (int i = 1; i < s.size() - 1; i++)
    {
        while (j > 0 && s[j] != s[i])
        { // 字符不匹配 j>0的目的是防止一直回退陷入死循环
            j = next[j]; // 回到下一个待比较位置
        }
        if (s[j] == s[i])
        {
            j++; // 相等则j+1,为目前最长公共子串长度
        }
        next[i + 1] = j; // 表示第i+1个字符比较失败时应该回退的位置
    }
    return next;
}
// 根据得到的next数组进行匹配,haystack为主字符串,needle为模式字符串
int strStr(string haystack, string needle)
{
    vector<int> next = getNext(needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); i++)
    {
        while (j != -1 && haystack[i] != needle[j])
        {
            j = next[j];
        }
        j++; // 这里j++负责处理两种情况：
        // 1.字符一直不相等j回溯到-1,+1变成0随i for循环+1重新比较
        // 2.字符一开始相等或者回溯到相等的位置,+1继续比较
        if (j == needle.size()) return i - needle.size() + 1;
    }
    return -1;
}
int main()
{
    string str1 = "aabaacaab";
    string str2 = "aac";
    int n = str2.size();
    cout << strStr(str1, str2) << endl;
    return 0;
}
