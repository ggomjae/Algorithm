#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100];
vector<int> v;

int main(){
	
	int n,m;
	cin >> n >> m;
	
	
	for(int i = 0 ; i < n-3 ; ++i){
		v.push_back(0);
	}
	for(int i = 0 ; i < 3 ; ++i){
		v.push_back(1);
	}
	
	
	for(int i = 0 ; i < n ; ++i){
		cin >> arr[i];
	}
	
	int ans = 0;
	int sum = 0;
	
	do{
		sum = 0 ;
		for(int i = 0 ; i < v.size() ; ++i){
			if(v[i] == 1)
				sum += arr[i];
		}
		
		if(sum <= m)
			ans = max(ans,sum);
		
		
	}while(next_permutation(v.begin(),v.end()));
	
	cout << ans << '\n';
	
	return 0;
}
