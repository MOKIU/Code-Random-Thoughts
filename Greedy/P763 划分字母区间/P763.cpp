#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s){
	vector<int> res;
	int index[27] = {0};
	for(int i = 0;i < s.size();i++){
		index[s[i] - 'a'] = i;
	}
	int startIndex = 0;
	int endIndex = 0;
	for(int i = 0;i < s.size();i++){
		if(endIndex < max(index[s[i] - 'a'], i)){
			endIndex = max(index[s[i] - 'a'], i);
		}
		if(i == endIndex){
			int val = endIndex - startIndex + 1;
			res.push_back(val);
			startIndex = endIndex + 1;
		}
	}
	return res;
}
int main(){
	return 0;
}