#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size()) return false;
    multiset<char> mset;
    bool isAns = true;
    for (int i = 0; i < t.size(); i++)
    {
        mset.insert(t[i]);
    }
    for (int i = 0; i < s.size(); i++)
    {
        auto it = mset.find(s[i]);
        if (it != mset.end())
        {
            mset.erase(it);
        }
        else
        {
            isAns = false;
            break;
        }
    }
    return isAns && mset.empty();
}
int main()
{
    return 0;
}