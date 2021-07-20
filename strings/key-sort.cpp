#include<bits/stdc++.h>
using namespace std;

string extractStringAtKey(string str, int key){
	char *s = strtok( (char*) str.c_str(), " ");
	while(key>1){
		s = strtok(NULL, " ");
		key--;
	}
	return string;
}

int main(){
	string  s=""
	int n;
	cin>>n;
	cin.get();  //will consume \n
	string temp;
	vector<string> v;
	for(int i=0;i<n;i++){
		getline(cin, temp);
		v.push_back(temp);
	}
	int key;
	string reverse,ordering;
	cin>>key>>reverse>>ordering;
}