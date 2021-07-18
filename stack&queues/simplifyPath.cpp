#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<deque>
using namespace std;


string simplifyPath(string path){
   //complete this code return the simplified path
  istringstream iss(path);
  vector<string> tokens;

  string token;
  while(getline(iss, token, '/')){
   if(token=="." or token==""){
      continue;
   }tokens.push_back(token);
  }
  for(string t:tokens){
   cout<<t<<" ";
  }return "";
}

int main(){
   string s=simplifyPath("/a//b//");
   cout<<s;
}