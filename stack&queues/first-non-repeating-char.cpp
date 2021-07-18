#include<bits/stdc++.h>
using namespace std;


vector<char> FindFirstNonRepeatingCharacter(string s){
    vector<char> v;
    unordered_map<char,int> m;
    queue<char> q;
    for(char i:s){
    	m[i]++;
    	if(m[i]==1) q.push(i);
    	while(!q.empty() && m[q.front()]>1) q.pop();
    	if(q.empty()) v.push_back('0');
    	else v.push_back(q.front());
    }
    return v;
}
 int main(){
 	vector<char> v=FindFirstNonRepeatingCharacter("aabcbcd");
 	for(char x:v) cout<<x<<" ";
 }