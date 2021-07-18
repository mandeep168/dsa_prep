#include<bits/stdc++.h>
using namespace std;

// int ans=0;

int sumsToX(vector<int> &v,int i,int x){
	if(i==v.size()) {
		// cout<<ans<<" ";
		if(x==0) return 1;
		else return 0;
	}
	int a = sumsToX(v,i+1,x);
	// ans+=v[i];
	int b=sumsToX(v,i+1,x - v[i]);
	// ans-=v[i];

	return a+b;
}

int main(){
	vector<int> v={1,4,2,3,6};
	cout<<sumsToX(v,0,5)<<" ";
}