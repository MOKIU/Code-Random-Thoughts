#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices){
	int result = 0;
	for(int i = 1;i < prices.size();i++){
		result += max(prices[i] - prices[i-1], 0);
	}
	return result;
}

int main(){
	return 0;
}