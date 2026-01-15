#include <bits/stdc++.h>
using namespace std;

vector<string> result;
string path = "";
bool isIpNum(string s){
	if(s.size() > 1 && s[0] == '0'){
		return false;
	}
	long num = stol(s);
	if(num < 0 || num > 255){
		return false;
	}
	return true;
}
void backtracking(string s, int startIndex, int nthNumber){
	if(nthNumber == 5){
		if(startIndex >= s.size()){
			path.resize(path.size() - 1); // 将最后一个多加的'.'删去
			result.push_back(path);
			path += '.';
			return;
		}else{
			return;
		}
	}
	for(int i = startIndex;i < s.size();i++){
		string str = s.substr(startIndex, i-startIndex+1);
		if(isIpNum(str)){
			path += str + '.';
			backtracking(s, i+1, nthNumber+1);
			path.resize(path.size() - str.size() - 1);
		}else{
			break;
		}
	}
}
vector<string> restoreIpAddresses(string s){
	if(s.size() > 12){
		return {};
	}
	backtracking(s, 0, 1);
	return result;
}
int main(){
	return 0;
}