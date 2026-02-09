#include <bits/stdc++.h>
using namespace std;

//dp[j]:容量为j的背包,能放的最大价值
int main(){
	int n, bagweight;
	cin >> n >> bagweight;
	vector<int> weight(n, 0);
	vector<int> value(n, 0);
	
	for(int i = 0;i < n;i++){
		cin >> weight[i];
	}
	
	for(int j = 0;j < n;j++){
		cin >> value[j];
	}
	
	vector<int> dp(bagweight + 1, 0);
	
	for(int i = 0;i < weight.size();i++){
		for(int j = bagweight;j >= weight[i];j--){
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	cout << dp[bagweight] << endl;
	return 0;
}