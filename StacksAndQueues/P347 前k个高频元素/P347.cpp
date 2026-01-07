#include <bits/sdtc++.h>
using namespace std;
// 使用优先级队列,元素为map,存储的使nums的数值和对应频率
// 使用小顶堆保存前k个频率大的,先维护前k个数组元素,栈顶是目前最小元素
// 每添加新元素与栈顶比较,如果小不入堆,如果大入队替换更新,最后小顶堆保存的是前k大的元素
// 题目说明答案具有唯一性,即每个元素的频率都不同
class mycomparsion
{
    // 左大建立小顶堆,反之建立大顶堆,可能与优先权队列的实现有关,方法必须共有不然访问不到
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        return lhs.second > rhs.second;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
        umap[nums[i]]++;
    }
    // 定义小顶堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparsion>
        pri_que;

    for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end();
         it++)
    {
        pri_que.push(*it);
        if (pri_que.size() > k)
        {
            pri_que.pop();
        }
    }

    // 找出前k个高频元素
    vector<int> res(k);
    for (int i = k - 1; i >= 0; i--)
    {
        res[i] = pri_que.top().first;
        pri_que.pop();
    }
    return res;
}
int main()
{
    return 0;
}