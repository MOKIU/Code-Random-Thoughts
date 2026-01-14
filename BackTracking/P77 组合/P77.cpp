#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<int> path;
void backtracking(int n, int k, int startIndex)
{
    if (path.size() == k)
    {
        result.push_back(path);
        return;
    }
    for (int i = startIndex; i <= n; i++)
    {
        path.push_back(i);
        backtracking(n, k, i + 1); // 向下一层递归
        path.pop_back(); // 回溯撤销处理的节点
    }
}
vector<vector<int>> combine(int n, int k)
{
    backtracking(n, k, 1);
    return result;
}
int main()
{
    return 0;
}