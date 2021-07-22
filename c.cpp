#include<bits/stdc++.h>
using namespace std;

// vector<int> denoms = {1,5,10,20,100};

void solve(){   
    int n;
    cin>>n;

    int ans = n/10;
    if(n%10 == 9) ans++;

    cout<<ans<<"\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--){
        solve();
    }
}