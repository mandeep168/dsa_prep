#include<bits/stdc++.h>
using namespace std;

vector<int> hashFunction(string s,int i,int j){
	vector<int> freq(26,0);

	for(int k=i;k<=j;k++){
		freq[s[k] - 'a']+=1;
	}

	return freq;
}

int anagram_substrings(string s){

	map<vector<int>, int> mapOfAnagrams;

	for(int i=0;i<s.length();i++){
		for(int j=i;j<s.length();j++){
			vector<int> hashCode = hashFunction(s,i,j);
			mapOfAnagrams[hashCode]++;
		}
	}

	int ans=0;
	for(auto p:mapOfAnagrams){
		int val = p.second;
		if(val>1){
			ans+=(val)*(val-1)/2;
		}
	}return ans;
}

int main(){
	cout<<anagram_substrings("abcde");
}