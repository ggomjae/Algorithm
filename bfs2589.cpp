#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 50

using namespace std;

string str[MAX];
queue<pair<int,int> > q;
int dist[MAX][MAX];
int ans;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int n,m;

void init(){
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			dist[i][j] = 0;
		}
	}
	
	return ;
}

int bfs(int x, int y){
	
	init();
	dist[x][y] = 0;
	q.push(make_pair(x,y));
	int result = 0 ;
	
	while(!q.empty()){
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();	
		result = max(result,dist[_x][_y]);
		
		for(int i = 0 ; i < 4; ++i){
			int nx = _x + dx[i];
			int ny = _y + dy[i];
			
			if( 0<= nx && nx < n && 0 <= ny && ny < m ){
				if(!dist[nx][ny] && str[nx][ny] == 'L'){
					q.push(make_pair(nx,ny));
					dist[nx][ny] = dist[_x][_y] + 1;
				}
			}
		}
	}
	
	return result;
}

int main(){
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> str[i] ;
	}
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < str[i].length() ; ++j){
			if(str[i][j] == 'L'){
				ans = max(ans, bfs(i,j));
			}			
		}	
	}
	
	cout << ans << '\n';
	
	return 0;
}
