#include <bits/stdc++.h>
using namespace std;

// 空间换时间 不原地修改
string replaceNumber(string s)
{
    char c;
    string result;
    string num = "number";
    for (int i = 0; i < s.size(); i++)
    {
        c = s[i];
                // 数字字符ascii码值范围48~57
        if (c >= 0x30 && c <= 0x39)
        {
            result.append(num);
        }
        else
        {
            result += c;
        }
    }
    return result;
}
int main()
{
    string s;
    cin >> s;
    cout << replaceNumber(s) << endl;
    return 0;
}