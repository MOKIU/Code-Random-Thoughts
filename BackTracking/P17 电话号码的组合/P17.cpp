#include <bits/stdc++.h>
using namespace std;

vector<string> result;
string path;
vector<string> letterMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
void backtracking(string digits, int index){
	if(path.size() == digits.length()){
		result.push_back(path);
		return;
	}
	int digit = digits[index] - '0';
	string letters = letterMap[digit];
	for(int i = 0;i < letters.size();i++){
		path.push_back(letters[i]);
		backtracking(digits, index+1);
		path.pop_back();
	}
}
vector<string> letterCombinations(string digits){
	backtracking(digits, 0);
	return result;
}
int main(){
	return 0;
}