#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100][100];
int check[100][100];
int ans[100];
int dx[4] = { 0,0, -1 ,1 };
int dy[4] = { -1,1 ,0 ,0 };
int n,m,k;

void bfs(int x, int y ,int cnt){
	
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	check[x][y] = cnt;
	arr[x][y] = cnt;
	
	while(!q.empty()){
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();
		
		for(int i = 0 ; i < 4 ; ++i){
			int nx = _x + dx[i];
			int ny = _y + dy[i];
			
			if( 0 <= nx && nx < m && 0 <= ny && ny < n){
				if( !check[nx][ny] && !arr[nx][ny]){
					q.push(make_pair(nx,ny));
					check[nx][ny] = cnt;
					arr[nx][ny] = cnt;
				}
			}
		}
	}
	return ;
}

int main(){
	
	int a,b,c,d;
	int cnt = 1;
	
	cin >> n >> m >> k;
	
	while(k--){
		cin >> a >> b >> c >> d;
		
		for(int i = a ; i < c ; ++i){
			for(int j = b ; j < d ; ++j){
				arr[i][j] = 1;
			}
		}
	}
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			if(!arr[j][i] && !check[j][i]){
				bfs(j,i,++cnt);
			}
		}
	}	
	
	cout << cnt-1 << '\n';
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			ans[arr[j][i]]++;
			
		}
		
	}
	
	sort(ans+2, ans+2+cnt-1);
	
	for(int i = 2 ; i <= cnt ; ++i){
		cout << ans[i] << " ";
	}
	
	return 0;
}
