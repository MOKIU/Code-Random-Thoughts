#include <bits/stdc++.h>
using namespace std;

string replaceNumber(string s)
{
    int sOldIndex = s.size() - 1;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            count++;
        }
    }
    int sNewIndex = sOldIndex + 5 * count;
    s.resize(sNewIndex + 1);
    while (sOldIndex >= 0)
    {
        if (s[sOldIndex] >= '0' && s[sOldIndex] <= '9')
        {
            s[sNewIndex--] = 'r';
            s[sNewIndex--] = 'e';
            s[sNewIndex--] = 'b';
            s[sNewIndex--] = 'm';
            s[sNewIndex--] = 'u';
            s[sNewIndex--] = 'n';
        }
        else
        {
            s[sNewIndex--] = s[sOldIndex];
        }
        sOldIndex--;
    }
    return s;
}
int main()
{
        // 使用双指针法:首先遍历一边知道有多少个数字,得到扩展后的字符串长度
        // 然后从后向前遍历,替换字符,这样保证时间复杂度为O(1)
    string s;
    cin >> s;
    cout << replaceNumber(s) << endl;
    return 0;
}