#include <bits/stdc++.h>
using namespace std;

void rotateRight(string& str, int k)
{
        // 整体反转一下
    reverse(str.begin(), str.end());
    reverse(str.begin(), str.begin() + k);
    reverse(str.begin() + k, str.end());
}
// 本题限制空间复杂度为O(1)
// 思路：先将字符串整体倒序,再将前n个倒序,后str.size()-n个倒序
int main()
{
    int k; // 右旋转的位数
    string str; // 需要旋转的字符串
    cin >> k;
    cin >> str;
    rotateRight(str, k);
    cout << str << endl;
    return 0;
}