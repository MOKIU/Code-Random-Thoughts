#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s){
	sort(g.begin(), g.end()); // 胃口
	sort(s.begin(), s.end()); // 饼干
	int result = 0;
	int index = s.size() - 1;
	for(int i = g.size() - 1;i >= 0;i--){
		if(index >= 0 && s[index] >= g[i]){
			index--;
			result++;
		}
	}
	return result;
}
int main(){
	return 0;
}