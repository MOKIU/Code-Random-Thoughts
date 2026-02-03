#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
	for(int i = 0;i < people.size();i++){
		bool swapped = false;
		for(int j = 0;j < people.size() - 1;j++){
			if(people[j][0] < people[j+1][0]){
				swap(people[j], people[j+1]);
				swapped = true;
			}
			if(people[j][0] == people[j+1][0] && people[j][1] > people[j+1][1]){
				swap(people[j], people[j+1]);
				swapped = true;
			}
		}
		if(!swapped){
			break;
		}
	}
	for(int i = 0;i < people.size();i++){
		int index = people[i][1];
		vector<int> tmp = people[i];
		for(int j = i-1;j >= index;j--){
			 people[j+1] = people[j];
		}
		people[index] = tmp;
	}
	return people;
}
int main(){
	return 0;
}