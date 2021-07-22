#include<bits/stdc++.h>
using namespace std;

int max_profit_dp(int* prices, int n){

	int dp[n+1];
	dp[0]=0;

	
	for(int len=1;len<=n;len++){

		int ans = INT_MIN;
		for(int i=0;i<len;i++){
			int cut = i+1;
			int curr_ans = prices[i] + dp[len - cut];
			ans = max(ans,curr_ans);
		}
		dp[len] = ans;

	}
	return dp[n];
}

int main(){

	int prices[] = {3,4,17,17,4,20};
	cout<<max_profit_dp(prices,6);

}