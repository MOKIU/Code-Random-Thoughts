#include <bits/stdc++.h>
using namespace std;

// 左括号进栈,遇到右括号看栈顶左括号是不是同类型
// 如果同类型则弹出左括号,不是则直接返回错
// 栈如果是空的就返回true
bool isValid(string s)
{
    stack<char> cstack;
    cout << cstack.size() << endl;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            cstack.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!cstack.empty() && cstack.top() == '(')
            {
                cstack.pop();
                continue;
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == '}')
        {
            if (!cstack.empty() && cstack.top() == '{')
            {
                cstack.pop();
                continue;
            }
            else
            {
                return false;
            }
        }
        else if (s[i] == ']')
        {
            if (!cstack.empty() && cstack.top() == '[')
            {
                cstack.pop();
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    if (!cstack.empty())
    {
        return false;
    }
    return true;
}
int main()
{
    string s = "()";
    cout << isValid(s) << endl;
    return 0;
}