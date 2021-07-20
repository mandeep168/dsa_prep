//complete seach
#include<bits/stdc++.h>
using namespace std;

string res="";

bool compare(string a,string b){
	if(a.size() == b.size()) return a<b;
	return a.size()<b.size();
}

void subsets(string A,int i,vector<string> &v){
	if(i==4) {
		v.push_back(res);
		return;
	}
	subsets(A,i+1,v);
	res+=A[i];
	subsets(A,i+1,v);
	// res = res.substr(0,res.size()-1);
	res.pop_back();
}

string convert_to_digital_time(int minutes){
    //complete this function
    int hours = minutes/60;
    int mins = minutes - 60*hours;
    
    string res = to_string(hours);
    res+=':';
    if(floor(log10(mins)) == 0) res+='0';
    res+=to_string(mins);return res;
    
    
}

int main(){
	// string A="abcd";
	// vector<string> v;
	// subsets(A,0,v);
	// sort(v.begin(), v.end(), compare);
	// for(string s:v) cout<<s<<" ";

	cout<<	convert_to_digital_time(127);
}