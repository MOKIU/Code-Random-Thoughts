#include <bits/stdc++.h>
using namespace std;
void reverseString(vector<char>& s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i < j)
    {
        int tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}
int main()
{
    return 0;
}
