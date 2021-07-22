#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int count_triplets(vector<int> arr, int r){
	int n = arr.size();
	unordered_map<long, long> right,left;

	//filling right map
	for(auto x:arr) {
		right[x]++;
		left[x]=0;
	}

	//iterate from left to right
	int ans=0;
	for(int i=0;i<n;i++){

		right[arr[i]]--;
		if(arr[i]%r == 0){
			 long b = arr[i];
			 long a = arr[i]/r;
			 long c = arr[i]*r;

			 ans += left[a]*right[c];
		}

		left[arr[i]]++;
	}

	return ans;
}

counting_rectangles

int main(){
	// cout<<sizeof(int)<<" "<<sizeof(long)<<" "<<sizeof(long long); 
	vector<int> v = {1,6,9,3,6,2,4,9};
	cout<<count_triplets(v,3);
}