#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int function(int start, int end , int target){
	if(start > end)
		return 0;
		
	int mid = (start + end)/ 2;
	
	if(v[mid] == target)
		return 1;
	else if(v[mid] < target){
		return function(mid+1,end,target);
	}else{
		return function(start,mid-1,target);
	}
}

int main(){

	ios_base::sync_with_stdio(0); 
	cin.tie(NULL); 

	int n;
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}	
	
	sort(v.begin(),v.end());

	int k;
	cin >> k;
	
	for(int i = 0 ; i < k ; ++i){
		int temp;
		cin >> temp;
		cout << function(0,n-1,temp) << '\n';;
	}	
	
	return 0;
}
