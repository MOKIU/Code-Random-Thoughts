#include <bit/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures){
	stack<int> st;
	vector<int> res(temperatures.size(), 0);
	for(int i = 0;i < temperatures.size();i++){
		// if(st.size() == 0){
			// st.push(i);
			// continue;
		// }
		// do{
			// if(temperatures[i] > temperatures[st.top()]){
				// res[st.top()] = i - st.top();
				// st.pop();
				// if(st.size() == 0){
					// st.push(i);
					// break;
				// }  
			// }else{
				// st.push(i);
				// break;
			// }
		// }while(st.size() != 0);
		while(!st.empty() && temperatures[i] > temperatures[st.top()]){
			res[st.top()] = i - st.top();
			st.pop();
		}
		st.push(i);
	}
	return res;
}
int main(){
	
}