#include<bits/stdc++.h>
using namespace std;

long long int powerModulo(int a, int b){
    //Write your code here. Do not modify the function or parameters. Use helper functions if needed.
    if(b==0) return 1;
    if(b&1) return (a*powerModulo(a,b-1)%1000000007 )%1000000007 ;
    long long num = powerModulo(a,b/2)%(1000000007);
    
    return (num*num)%(1000000007);
    
}

int main(){
    cout<<powerModulo(5,6);
}