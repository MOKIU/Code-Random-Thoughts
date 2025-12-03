#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens)
{
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" &&
            tokens[i] != "/")
        {
            st.push(stoi(tokens[i]));
        }
        else
        {
            int tmp1 = st.top();
            st.pop();
            int tmp2 = st.top();
            st.pop();
            int res;
            if (tokens[i] == "+")
                res = tmp1 + tmp2;
            else if (tokens[i] == "-")
                res = tmp2 - tmp1;
            else if (tokens[i] == "*")
                res = tmp1 * tmp2;
            else
                res = tmp2 / tmp1;
            st.push(res);
        }
    }
    return st.top();
}
int main()
{
    vector<string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                             "/",  "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens) << endl;
    return 0;
}