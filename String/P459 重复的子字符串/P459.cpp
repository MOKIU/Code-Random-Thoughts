#include <bits/stdc++.h>
using namespace std;

// 我的想法：计算整个字符串的next数组,看最后一位字符的next值
// 是不是整个字符串长度的一半
vector<int> getNext(string s)
{
    int n = s.size();
    vector<int> next(n + 1, 0);
    next[0] = -1;
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        while (j > 0 && s[j] != s[i])
        {
            j = next[j];
        }
        if (s[j] == s[i])
        {
            j++;
        }
        next[i + 1] = j;
    }
    return next;
}
// 得到下面的关键理念需要考虑三种情况
// 1.当lsp少于整个字符串的一半的时候,试想一个极端情况字符串是由两个重复字符串组成的,此时的lsp=字符串长度的一半,如果lsp<这个标准,说明不是该字符串不是前后平移对称的,有不一样的元素存在,则代表不是由重复字符串构成的
// 2.当lsp大于整个字符串的一半的时候,并且去除最长公共前后缀剩下的字符串长度能整除整个字符串的大小时,举例子可以验证出来结论是对的,通过循环交叉往复相等验证
// 3.当lsp大于整个字符串的一半但不能整除的时候,同样举例可以论证剩下的子串无法构成最小长度重复字符串,尺寸不够
// 关键理念:如果一个字符串是由重复子串组成的，字符串去除最长公共前后缀就是最小重复子串
// 当一个除去最长公共前后缀的子串的长度能被整个字符串整除时(前提是有最长公共前后缀)，该字符串就是最小重复子串
bool repeatedSubstringPattern(string s)
{
    // 首先求除去最长公共前后缀子串的长度
    // 首先获取整个字符串的lsp,按理说应该是next[s.size()],
    // 因为我写的版本是next[i]代表0~i-1下标字符串的lsp,所以要对之前的getnext函数结果数组向后扩容一位
    // 考虑一些其他情况,如果字符串大小为0,则返回的next数组为-1,minLen=0-(-1)=1,0%1肯定会返回true,所以要判断尺寸为0,但不用考虑了,题目限定尺寸>1
    // 再考虑尺寸为1情况,返回next数组为-1,0,minlen=1-0=1,1%1=0,所以字符串长度为1时也不符合情况需要判断
    // 但由此又引申出了一个情况,如果该字符串没有公共前后缀,那么就是len%len=0,这样肯定不对,所以我们需要排除next[size]=0的字符串
    // 那为什么next[size]=0不满足情况呢,试想一个由重复字符串构成的字符串是一定有公共前后缀的,则没有一定代表不是重复字符串
    int len = s.size();
    vector<int> next = getNext(s);
    int minLen = len - next[s.size()]; // next[s.size()]为字符串lsp
    if (next[len] != 0 && len % minLen == 0) return true;
    return false;
}
int main()
{
    string s = "abcabcabc";
    cout << repeatedSubstringPattern(s) << endl;
    return 0;
}