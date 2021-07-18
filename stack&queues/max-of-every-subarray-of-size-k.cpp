#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> max_of_subarray(vector<int> &a, int k){
	vector<int> v;
	deque<int> deq;

	//pushing usefull at the back
	//poping useless at the back
	for(int i=0;i<k;i++){
		while(!deq.empty() && deq.back()<a[i]) deq.pop_back();
		deq.push_back(a[i]);
	}
	if(a.size()>k) v.push_back(deq.front());
	for(int i=k;i<a.size();i++){
		while(deq.size()>=k) deq.pop_front();
		while(!deq.empty() && deq.back()<a[i]) deq.pop_back();
		
		deq.push_back(a[i]);
		
		
		v.push_back(deq.front());
	}
	return v;
}

int main(){ 
	vector<int> a={1,2,3,1,4,5,2,3,5};
	vector<int > v=max_of_subarray(a,3);

}