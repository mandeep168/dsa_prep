#include<iostream>
#include<string>

using namespace std;

void generatingPermutaions(string input,int i){
	if(i==input.size()){
		cout<<input<<"\n";return;
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

int main(){
	generatingPermutaions("abc", 0);
}