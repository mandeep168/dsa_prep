//complete seach
#include<bits/stdc++.h>
using namespace std;

string res="";

void subsets(string A,int i){
	if(i==4) {
		cout<<res<<"\n";
		return;
	}
	subsets(A,i+1);
	res+=A[i];
	subsets(A,i+1);
	// res = res.substr(0,res.size()-1);
	res.pop_back();
}

int main(){
	string A="abcd";
	subsets(A,0);
}