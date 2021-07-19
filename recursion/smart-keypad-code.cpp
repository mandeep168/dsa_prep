#include<bits/stdc++.h>
using namespace std;

string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printKeypadOutput(string input, string output, int i=0){
	//base case
	if(i==input.size()){
		cout<<output<<"\n";
	}

	//recursive case
	if(input[i]==0 || input[i]==1) {
		printKeypadOutput(input,output,i+1);
	}
	else{
		int num = input[i] - '0';
		for(int j=0;j<keypad[num].size();j++){
			printKeypadOutput(input, output + keypad[num][j],i+1);
		}
	}
	return;

}

 int main(){
 	printKeypadOutput("23","",0);
 }