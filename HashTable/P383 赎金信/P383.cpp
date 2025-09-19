#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    if (ransomNote.size() > magazine.size())
    {
        return false;
    }
    multiset<char> mset;

    for (int i = 0; i < magazine.size(); i++)
    {
        mset.insert(magazine[i]);
    }
    for (int i = 0; i < ransomNote.size(); i++)
    {
        auto it = mset.find(ransomNote[i]);
        if (it != mset.end())
        {
            mset.erase(it);
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cout << canConstruct("aa", "ab");
    return 0;
}