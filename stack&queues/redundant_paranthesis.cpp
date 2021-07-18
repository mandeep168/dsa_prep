#include <bits/stdc++.h>
using namespace std;

bool redundant_paranthesis(string s){
    stack<char> stack;
    bool is_operator = false;
    for(char x:s){
        if(x!=')'){
            stack.push(x);
        }else{
            is_operator=false;
            while(!stack.empty() && stack.top()!='('){
                char top = stack.top();
                if(top=='+' || top=='-' || top=='*' ||top=='/'){
                    is_operator=true;
                }
                stack.pop();
            }if(is_operator == false) return true;
            if(stack.top()=='(') stack.pop();
            else return true;
        }
    }
    return false;
}

int main() {
   if(redundant_paranthesis("((a+56) + 5) + f")) cout<<"Redundant paranthesis";
   else cout<<"Perfect!!!";
}