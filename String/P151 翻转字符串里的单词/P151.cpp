#include <bits/stdc++.h>
using namespace std;

// 删除额外空格 分为三种情况 删除首空格 删除单词之间多余空格 删除尾空格
void removeExtraSpace(string& s)
{
        // 使用快慢指针去除空格
    // 主要思路是删除所有空格,遇到非空格就将其赋值前面,遇到单词结束就添加一个字符
    int slow = 0; // 慢指针,被赋值最终结果的每个字符
    for (int i = 0; i < s.size(); i++)
    { // i为快指针
        if (s[i] != ' ')
        {
            // s[slow++] = s[i];
            // 只将每个单词后的空格带上,且最后一个单词后面的空格不同处理了
            // if (slow > 0 && i + 1 < s.size() - 1 && s[i + 1] == ' ')
            // { // slow>0说明前置空格已经处理完了
            // s[slow++] = ' ';
            // }
            if (slow != 0) s[slow++] = ' ';
            while (i < s.size() && s[i] != ' ')
            {
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
}

string reverseWords(string s)
{
    removeExtraSpace(s);
    reverse(s.begin(), s.end());
    // 双指针 将每个单词逆转
    int start = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
        else if (i == s.size() - 1)
        {
            reverse(s.begin() + start, s.end());
        }
    }
    return s;
}

// 不要做成水题,限定空间复杂度要求为O(1),在原字符串修改
int main()
{
    // 思路：1.删除多余的空格2.整个字符串翻转3.将每个单词翻转
    string s = "  hello world  ";
    removeExtraSpace(s);
    cout << s << endl;
    cout << reverseWords(s) << endl;
    return 0;
}