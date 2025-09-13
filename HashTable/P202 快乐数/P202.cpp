#include <bits/stdc++.h>
using namespace std;

bool isHappy(int n)
{
    bool hasNew = false;
    unordered_set<int> uset;
    do
    {
        hasNew = false;
        for (int i = 1; i <= 2592; i++)
        {
            int a = i / 1000;
            int b = (i / 100) % 10;
            int c = (i / 10) % 10;
            int d = i % 10;
            int tmp = a * a + b * b + c * c + d * d;
            int size1 = uset.size();
            if (tmp == 1 || tmp == 10 || tmp == 100 ||
                uset.find(tmp) != uset.end())
            {
                uset.insert(i);
            }
            int size2 = uset.size();
            if (size1 != size2)
            {
                hasNew = true;
            }
        }
    } while (hasNew);
    int mul_sum = 0;
    while (n)
    {
        int k = n % 10;
        mul_sum += k * k;
        n = n / 10;
    }
    if (uset.find(mul_sum) != uset.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int num = 7;
    cout << isHappy(7) << endl;
}