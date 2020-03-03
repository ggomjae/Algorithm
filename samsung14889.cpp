#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 21

using namespace std;

vector<int> v;
int arr[MAX][MAX];
int ans = 987654321;

int main(){

	int n;
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		if(i < n/2){
			v.push_back(0);
		}
		else{
			v.push_back(1);
		}	
	}
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			cin >> arr[i][j];			
		}
	}
	
	do{
		int aT = 0;
		int bT = 0;
		
		for(int i = 0 ; i < v.size() ; ++i){
			for(int j = i ; j < v.size() ; ++j){
				if(v[i] == 0 && v[j] == 0){
					aT += arr[i][j] + arr[j][i];
				}
				
				if(v[i] == 1 && v[j] == 1){
					bT += arr[i][j] + arr[j][i];
				}
			}	
		}
		
		int result = aT-bT;
		
		if(result < 0){
			result *= -1;
		}
		
		ans = min(ans,result);
		
	}while(next_permutation(v.begin(),v.end()));
	
	cout << ans <<'\n';
	
	return 0;
}
