#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings){
	int sum = 0;
	vector<int> candyVec(ratings.size(), 1);
	for(int i = 1;i < candyVec.size();i++){
		if(ratings[i] > ratings[i-1])candyVec[i] = candyVec[i-1] + 1;
	}
	for(int i = candyVec.size()-2;i >= 0;i--){
		if(ratings[i] > ratings[i+1])candyVec[i] = max(candyVec[i], candyVec[i+1]+1);
	}
	for(int i = 0;i < candyVec.size();i++){
		sum += candyVec[i];
	}
	return sum;
}