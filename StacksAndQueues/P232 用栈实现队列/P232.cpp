#include <bits/stdc++.h>
using namespace std;
// 思路用进栈和出栈模拟队列
class MyQueue
{
    stack<int> in;
    stack<int> out;
    MyQueue() {}
    void push(int x)
    {
        in.push(x);
    }
    int pop()
    {
        int result;
        // 模拟队列的弹出操作,如果出栈为空需要将入栈全部弹出并入出栈,如果出栈不为空则正常弹出
        if (out.empty())
        {
            while (!in.empty())
            {
                int tmp = in.top();
                in.pop();
                out.push(tmp);
            }
        }
        result = out.top();
        out.pop();
        return result;
    }
    int peek()
    {
        int result;
        if (!out.empty())
        {
            result = out.top();
        }
        else
        {
            while (!in.empty())
            {
                int tmp = in.top();
                in.pop();
                out.push(tmp);
            }
            result = out.top();
        }
        return result;
    }
    bool empty()
    {
        if (in.empty() && out.empty())
            return true;
        else
            return false;
    }
} int main()
{
    return 0;
}