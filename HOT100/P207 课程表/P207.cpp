#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    // 入度数组,出度节点数组
    vector<int> inNum(numCourses, 0);
    // 出度节点数组
    vector<vector<int>> outNodes(numCourses);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        inNum[prerequisites[i][0]]++;
        outNodes[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    // 使用队列存储所有入度为0的节点(拓扑排序的关键)
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (inNum[i] == 0)
        {
            q.push(i);
        }
    }
    
    int count = 0; // 记录已完成的课程数
    // BFS遍历
    while(!q.empty()){
    	int current = q.front();
    	q.pop();
    	count++;
    	for(int nextNode : outNodes[current]){
    		inNum[nextNode]--;
    		if(inNum[nextNode] == 0){
    			q.push(nextNode);
    		}
    	}
    }
    
    return count == numCourses;
    // for (int i = 0; i < numCourses; i++)
    // {
        // if (inNum[i] == 0)
        // {
            // for (int j = 0; j < outNode[i].size(); j++)
            // {
                // inNum[outNode[i][j]]--;
            // }
        // }
    // }
    // bool res = true;
    // for (int i = 0; i < numCourses; i++)
    // {
        // if (inNum[i] != 0) res = false;
    // }
    // return res;
}
int main()
{
    vector<vector<int>> arr = {{1, 0}};
    canFinish(2, arr);
    return 0;
}