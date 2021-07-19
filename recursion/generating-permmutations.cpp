#include<bits/stdc++.h>

using namespace std;

set<string> se;

void generatingPermutaions(string input,int i){
	if(i==input.size()){
		se.insert(input);return;
	}
	for(int j=i;j<input.size();j++){
		char temp = input[i];
		input[i] = input[j];
		input[j] = temp;

		generatingPermutaions(input,i+1);

		temp = input[i];
		input[i] = input[j];
		input[j] = temp;

	}
	return;
}


vector<string> findSortedPermutations(string s){
    vector<string> v;
    generatingPermutaions(s,0);
    
    auto it = se.begin();
    for(;it!=se.end();it++){
    	v.push_back(*it);
    }
    return v;
}

int main(){

	vector<string> v = findSortedPermutations("abbc");
	for(string i:v) cout<<i<<",";
}