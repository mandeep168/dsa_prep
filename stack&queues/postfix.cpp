#include<bits/stdc++.h>
using namespace std;
 
string InfixToPostfix(string exp){
	string B = "";
	stack<char> operators;
	for(int i=0;i<exp.length();i++){
		if(!(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')) B+=exp[i];
		else{
				while(!operators.empty() && ((operators.top() == '*' || operators.top() == '/') || ((operators.top() == '+' || operators.top() == '-') && (exp[i]=='+' || exp[i]=='-')))){
					B+=operators.top();
					operators.pop();
				}
				operators.push(exp[i]);
			
		}

	}
	while(!operators.empty()){
		B += operators.top();
		operators.pop();
	}
	return B;
}

string InfixToPrefix(string exp){
	
}

int postfix_evaluate(string exp){
	stack<int> s;
	for(int i=0;i<exp.length();i++){
		if(!(exp[i]=='+'||exp[i]=='*'||exp[i]=='-'||exp[i]=='/')){
			s.push(exp[i]-'0');
		}else{
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();
			int res;
			if(exp[i]=='+') res = op1 + op2;
			else if(exp[i]=='-') res = op1 - op2;
			else if(exp[i]=='*') res = op1 * op2;
			else if(exp[i]=='/') res = op1 / op2;
			s.push(res);
		}
	}
	return s.top();
}

int prefix_evaluate(string exp){
	stack<int> s;
	for(int i=exp.length()-1;i>=0;i--){
		if(!(exp[i]=='+'||exp[i]=='*'||exp[i]=='-'||exp[i]=='/')){
			s.push(exp[i]-'0');
		}else{
			int op1 = s.top();
			s.pop();
			int op2 = s.top();
			s.pop();
			int res;
			if(exp[i]=='+') res = op1 + op2;
			else if(exp[i]=='-') res = op1 - op2;
			else if(exp[i]=='*') res = op1 * op2;
			else if(exp[i]=='/') res = op1 / op2;
			s.push(res);
		}
	}
	return s.top();
}

int main(){
	cout<<"Postfix evaluation is: "<<postfix_evaluate("23*54*+9-");
	cout<<"\n";
	cout<<"Prefix evaluation is: "<<prefix_evaluate("-+*23+549");
	cout<<"\n";
	cout<<"infix to postfix: "<<InfixToPostfix("A+B*C-D*E");
}