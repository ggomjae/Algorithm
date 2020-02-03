#include <iostream>
#include <queue>

using namespace std;

int dist[100001];

int main(){
	
	int n,m,ans;
	
	cin >> n >> m;
	
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		if(x == m){
			ans = dist[x];
					
			break;
		}
		
		if(2*x <= 100000 && x != 0){
			
			if(!dist[2*x] || dist[2*x] > dist[x] + 1){
				q.push(2*x);
				dist[2*x] = dist[x] + 1;
			}
				
		}
			
		if(x-1 >=0 ){
		
			if(!dist[x-1] || dist[x-1] > dist[x] + 1){
				q.push(x-1);
				dist[x-1] = dist[x] + 1;
			}
		}
			
		if(x+1 <= 100000){
			
			if(!dist[x+1] || dist[x+1] > dist[x] + 1){
				q.push(x+1);
				dist[x+1] = dist[x] + 1;
			}
		}
			
	}
	
	cout << ans << '\n';
	
	return 0;
}
