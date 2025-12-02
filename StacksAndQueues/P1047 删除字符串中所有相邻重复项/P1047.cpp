#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
    stack<char> st;
    string res;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty() || st.top() != s[i])
        {
            st.push(s[i]);
        }
        else
        {
            st.pop();
        }
    }
    int size = st.size();
    while (size--)
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    string s = "abbaca";
    cout << removeDuplicates(s) << endl;
    return 0;
}