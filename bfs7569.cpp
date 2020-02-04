#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[101][101][101];
int check[101][101][101];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int dh[2] = {-1,1};

int cnt;
int ans;

int main(){
	
	int n,m,h;
	bool zeroStatus = true;
	
	queue<pair<pair<int,int>,pair<int,int> > > q;
	cin >> n >> m >> h;
	
	
	for(int i = 0 ; i < h ; ++i){
		for(int j = 0 ; j < m ; ++j){
			for(int k = 0 ; k < n ; ++k){
				cin >> arr[k][j][i];
				if(arr[k][j][i]==1){
					q.push(make_pair(make_pair(k,j),make_pair(i,cnt)));
					check[k][j][i] = 1;
				}	
				
				if(arr[k][j][i] == 0){
					zeroStatus = false;
				}
			}
		}
	}
	
	if(zeroStatus){
		cout << "0" << '\n';
		return 0;
	}
	
	while(!q.empty()){
		
		int _x = q.front().first.first;
		int _y = q.front().first.second;
		int _h = q.front().second.first;
		int _cnt = q.front().second.second;
		
		q.pop();
		
		for(int i = 0 ; i < 4 ; ++i){
			int nx = _x + dx[i];
			int ny = _y + dy[i];
			int nh = _h;
			
			if( 0 <= nx && nx < n && 0 <= ny && ny < m ){
				if( !check[nx][ny][nh] && arr[nx][ny][nh] == 0){
					q.push(make_pair(make_pair(nx,ny),make_pair(nh,_cnt + 1)));
					check[nx][ny][nh] = 1;
					arr[nx][ny][nh] = _cnt + 1;
				}
			}
		}
		
		for(int i = 0 ; i < 2 ; ++i){
			int nx = _x ;
			int ny = _y ;
			int nh = _h + dh[i];
			
			if( 0<= nh && nh < h){
				if(!check[nx][ny][nh] && arr[nh][nh][nh] == 0){
					q.push(make_pair(make_pair(nx,ny),make_pair(nh,_cnt + 1)));
					check[nx][ny][nh] = 1;
					arr[nx][ny][nh] = _cnt + 1;
				}
			}
		}
	}
	
	for(int i = 0 ; i < h ; ++i){
		for(int j = 0 ; j < m ; ++j){
			for(int k = 0 ; k < n ; ++k){
			
				if(arr[k][j][i]==0){
					cout << "-1" << '\n';
					return 0;
				}
				if(ans < arr[k][j][i])
					ans = arr[k][j][i];
			}	
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
