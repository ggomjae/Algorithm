#include <iostream>
#include <vector>
#include <cmath>
#define MAX 987654321

using namespace std;

int dp[50001];
vector<int> v;

int main(){
	
	int n;
	cin >> n;
		
	for(int i = 1 ; i <= 223 ; ++i){
		v.push_back(i*i);		
	}
	
	dp[0] = 0 ;
	dp[1] = 1 ;
	
	for(int i = 2 ; i <=n ; ++i){
		
		int minNumber = MAX;
		
		for(int j = 0 ; i-v[j] >=0 ; j++){
			
			int temp = i-v[j];
			minNumber = min(minNumber,dp[temp]);
		}
		
		dp[i] = minNumber + 1;
	}
	
	cout << dp[n] << '\n';
	
	return 0;
}
