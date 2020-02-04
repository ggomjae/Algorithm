#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[1001][1001];
int check[1001][1001];
int cnt;
int ans;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
	int n, m;
	bool status = false;
	bool zeroStatus = true;
	
	cin >> n >> m;
	
	queue<pair<int,pair<int,int> > > q;
	
	for(int i = 0 ; i < m ; ++i){
		for(int j = 0 ; j < n ; ++j){
			scanf("%d",&arr[j][i]); 		
			
			if(arr[j][i] == 1){
				q.push(make_pair(j,make_pair(i,cnt)));
				check[j][i] = 1;
			}
			
			if(arr[j][i] == 0)
				zeroStatus = false;		
		}
	}
	
	if(zeroStatus){
		cout << "0" << '\n';
		return 0;
	}
	 
	while(!q.empty()){
		
		int _x =q.front().first; 
		int _y =q.front().second.first;
		int _cnt = q.front().second.second;
		
		q.pop();
		
		for(int i = 0 ; i < 4 ; ++i){
			
			int nx = _x + dx[i];
			int ny = _y + dy[i];
			
			if( 0 <= nx && nx < n && 0 <= ny && ny < m ){
				if(!check[nx][ny] && arr[nx][ny] == 0 ){
					arr[nx][ny] = _cnt+1;
					check[nx][ny] = 1;
					q.push(make_pair(nx,make_pair(ny,_cnt+1)));
				}
			}
		}
		
	}

	for(int i = 0 ; i < m ; ++i){
		for(int j = 0 ; j < n ; ++j){
			if(!arr[j][i]){
				status = true;
				cout << "-1" << '\n';
				return 0;
			}
			
			if(arr[j][i] > ans)
				ans = arr[j][i];
		}
	}

	cout << ans << '\n';
	
	return 0;
}
