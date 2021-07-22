#include<bits/stdc++.h>
using namespace std;

int quickBrownFox(map<string,int> &m,string s, int i, string curr){
	if(i == s.length()) {
		if(m[curr]) return 0;
		return -1;
	}
	curr+=s[i];
	if(!m[curr]){
		return quickBrownFox(m,s,i+1,curr);
	}
	int A = 1 + quickBrownFox(m,s,i+1,"");
	int B = quickBrownFox(m,s,i+1,curr);

	if(B==-1) return A;
	return 1+min (A,B);

}


	string s = "thequickbrownfox";
	string words[]= {"the", "quickbrown", "fox", "quick", "brown"};

int minbars_Helper(string s,string words[],int idx,unordered_set<string>&m){

	//base
	if(s[idx]=='\0') {
		return 0;
	}

	//rec
	int ans = INT_MAX;
	string curr = "";
	for(int j=idx;s[j]!='\0';j++){
		curr+=s[j];

		if(m.find(curr)!=m.end()){
			int remaining_ans = minbars_Helper(s,words,j+1,m);
			if(remaining_ans!=-1){
				ans = min(ans,1+remaining_ans);
			}
		}
	}
	if(ans==INT_MAX){
		return -1;
	}
	return ans;
}

int min_bars(){
	unordered_set<string> m;

	for(string w:words){
		m.insert(w);
	}

	//rec

	int output = minbars_Helper(s,words,0,m);

	return output-1;
}

int main(){
	// map<string,int> m;
	// for(string x:v) m[x]++;
	// cout<<quickBrownFox(m, s, 0, "")-1;
	cout<<min_bars()<<" ";
}