#include<bits/stdc++.h>
using namespace std;

void paranthesis(int n,int open, int close, string ans){
	if(open==close && open==n) {
		cout<<ans<<"\n";
		return;
	}
	if(open<n) paranthesis(n,open+1,close,ans+'(');
	if(close<open) paranthesis(n,open, close+1, ans+')');
	return;
}

int main(){
	paranthesis(5,0,0,"");
}