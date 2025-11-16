#include <bits/stdc++.h>
using namespace std;
// 首先移除多余的空格,然后整体反转,再反转每个单词
void removeExtraSpace(string& s)
{
    int slowIndex = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            if (slowIndex != 0) s[slowIndex++] = ' ';
            while (i < s.size() && s[i] != ' ')
            {
                s[slowIndex++] = s[i++];
            }
        }
    }
    s.resize(slowIndex);
}
string reverseWords(string s)
{
    removeExtraSpace(s);
    reverse(s.begin(), s.end());
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            reverse(s.begin() + j, s.begin() + i);
            j = i + 1;
        }
    }
    reverse(s.begin() + j, s.end());
    return s;
}
int main()
{
    string s = "abc abc  adcc";
    cout << reverseWords(s) << endl;
    return 0;
}