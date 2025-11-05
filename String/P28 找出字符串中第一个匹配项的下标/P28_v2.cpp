#include <bits/stdc++.h>
using namespace std;

// KMP的另一个构造next数组版本 "aabaaf"的next数组为"010120"
// 此时next[i]的含义不再是i位置匹配失败的应该跳转的位置而是0~i的lcp
vector<int> getNext(string s)
{
    int n = s.size();
    vector<int> next(n, 0);
    int j = 0;
    next[0] = 0; // 表示只有一个字符,lcp=0
    for (int i = 1; i < s.size(); i++)
    {
        while (j > 0 && s[j] != s[i]) // j=0回到起点还不相等就不用回溯了
        {
            j = next[j - 1]; // next[j-1]代表0~j-1的lcp
        }
        if (s[j] == s[i])
        {
            j++;
        }
        next[i] = j;
    }
    return next;
}
int strStr(string haystack, string needle)
{
    vector<int> next = getNext(needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); i++)
    {
        while (j != 0 &&
               haystack[i] != needle[j]) // 这个比上一个版本少了第一个元素的比较
        {
            j = next[j - 1];
        }
        if (haystack[i] == needle[j])
            j++; // 与上个版本不同这个j++是有条件的
                 // 上一个next[0]=-1可以跳到-1再加回来再比较
        // 这个next[0]=0不能跳还是保持0
        if (j == needle.size())
        {
            return i - needle.size() + 1;
        }
    }
    return -1;
}
int main()
{
    // string s = "aabaaf";
    // vector<int> next = getNext(s);
    // for (int i = 0; i < s.size(); i++)
    // {
    // cout << next[i] << " ";
    // }
    string str1 = "aabaacaab";
    string str2 = "aac";
    int n = str2.size();
    cout << strStr(str1, str2) << endl;
    return 0;
}