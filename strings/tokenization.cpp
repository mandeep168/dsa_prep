#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main(){

	string input = "ojkm noml nmol";
	// getline(cin, input);
	// input = "I am the BEST.";

	//creating a string stream object
	stringstream ss(input);

	//we can read/write data from string stream object
	string token;
	vector<string> tokens;
	while(getline(ss,token,' ')){
		tokens.push_back(token);
	}
	for(string token:tokens) cout<<token<<", ";
}