#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[16][2];  
int n;
int ans = -1; 

int solution(int p){
	
	queue<pair<pair<int,int>,int> > q;
	if( p + arr[p][0] -1 <= n){
		q.push(make_pair(make_pair(p,arr[p][0]),arr[p][1]));	
	}
	
	int result = 0 ;
	
	while(!q.empty()){
	
		int _x = q.front().first.first;  
		int _y = q.front().first.second; 
		int mid_result = q.front().second;
		q.pop();
		bool status = false;
		
		for(int i = _x + _y ; i<= n ; ++i){
			
			int nx = i + arr[i][0] - 1;
			
			if( nx <= n ){
				q.push(make_pair(make_pair(i,arr[i][0]),mid_result+arr[i][1]));
				status = true;
			}
		}
		
		if(!status){
			result = max(result,mid_result);
		}
	}
	
	return result;
}

int main(){
	
	cin >> n;
	
	for(int i = 1 ; i <= n ; ++i){
		cin >> arr[i][0] >> arr[i][1];
	}	
	
	for(int i = 1 ; i <= n ; ++i){
		 
		ans = max(ans , solution(i));		
	}

	cout << ans << '\n';
	
	return 0;
}
