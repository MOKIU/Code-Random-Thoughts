#include <bits/stdc++.h>
using namespace std;

// size为已入选的多个字符串的字符个数
// int size = 0;
// bool backtracking(string s, vector<string>& wordDict, int sIndex){
        // if(size == s.size()){
                // return true;
        // }
        // for(int i = 0;i < wordDict.size();i++){
                // int j;
                // for(j = 0;j < wordDict[i].size();j++){
                        // if(s[sIndex] != wordDict[i][j]){
                                // break;
                        // }
                        // sIndex++;
                // }
                // if(j < wordDict[i].size()){
                        // sIndex -= j;
                        // continue;
                // }else{
                        // size += wordDict[i].size();
                        // if(backtracking(s, wordDict, sIndex))return true;
                        // sIndex -= j;
                        // size -= wordDict[i].size();
                // }
        // }
        // return false;
// }

// bool backtracking(const string& s, const vector<string>& wordDict, int start)
// { if (start == s.size()) { return true;
// }
// for (const string& word : wordDict) {
// if (s.substr(start, word.size()) == word) {
// if (backtracking(s, wordDict, start + word.size())) {
// return true;
// }
// }
// }
// return false;
// }

bool backtracking(const string& s, const vector<string>& wordDict, int start,
                  vector<int>& memo)
{
    if (start == s.size()) return true;
    if (memo[start] != -1) return memo[start]; // 已经计算过，直接返回

    for (const string& word : wordDict)
    {
        if (s.substr(start, word.size()) == word)
        {
            if (backtracking(s, wordDict, start + word.size(), memo))
            {
                memo[start] = 1; // 记录可以拆分
                return true;
            }
        }
    }

    memo[start] = 0; // 记录无法拆分
    return false;
}
bool wordBreak(string s, vector<string>& wordDict)
{
    vector<int> memo(s.size(), -1); // -1: 未计算, 0: 不可拆分, 1: 可拆分
    return backtracking(s, wordDict, 0, memo);
}
int main()
{
    return 0;
}