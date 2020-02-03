#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[101][101];
int cpyArr[101][101];
int check[101][101];
int cnt;
int ans = 1;
int n;
bool stop;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void bfs(int x, int y ){
	
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	check[x][y] = 1;
	
	while(!q.empty()){
		int _x = q.front().first;
		int _y = q.front().second;
		
		q.pop();
		
		for(int i = 0 ; i < 4 ; ++i){
			int nx = _x + dx[i];
			int ny = _y + dy[i];
			
			if( 0<= nx && nx < n && 0 <= ny && ny < n ){
			
				if( !check[nx][ny] && cpyArr[nx][ny]){
					q.push(make_pair(nx,ny));
					check[nx][ny] =1;
					
				}	
			}
		}	
	}
	
	return ;
}

int main(){
	
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			cin >> arr[i][j] ;
		}
	}	
	
	for(int index = 1 ; index <= 100 ; ++index){
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				if(arr[i][j] > index){
					cpyArr[i][j] = 1;
					stop = true;
				}
				else
					cpyArr[i][j] = 0;
			
				check[i][j] = 0 ;	
			}
		}
		
		if(!stop)
			break;
		
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				if(cpyArr[i][j] && !check[i][j]){
					cnt++;
					bfs(i,j);
				}
			}
		}
		
		if(ans < cnt)
			ans = cnt;
				
		cnt = 0;
	}
	
	cout << ans << '\n';
	
	return 0;
}
