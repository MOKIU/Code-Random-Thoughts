#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills){
	int five = 0, ten = 0, twenty = 0;
	for(int i = 0;i < bills.size();i++){
		switch (bills[i]){
		case 5:
			five++;
			break;
		case 10:
			if(five == 0)return false;
			else{
				five--;
				ten++;
			}
			break;
		case 20:
			if(ten > 0 && five > 0){
				ten--;
				five--;
				twenty++;
			}else if(five >= 3){
				five  -= 3;
				twenty++;
			}else{
				return false;
			}
		}
	}
	return true;
}
int main(){
	return 0;
}