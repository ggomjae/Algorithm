#include <iostream>
#include <algorithm>
#define MAX 501

using namespace std;

int n,m;
int arr[MAX][MAX];
int visit[MAX][MAX];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int ans ;

int solution(int x, int y, int cnt){
	
	if(cnt == 4){
		return arr[x][y];
	}
	
	int result = 0 ;
	
	for(int i = 0 ; i < 4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if( 0 <= nx && nx < n && 0 <= ny && ny < m && visit[nx][ny] == 0){
			visit[nx][ny] = 1;
			result = max(result ,arr[x][y] + solution(nx,ny,cnt + 1));
			visit[nx][ny] = 0;	
		}
	}
	
	return result ; 
}

int solution_t(int x, int y){
	
	int result = 0 ;
	int t_v = 0 ;
	
	if( x >= 1 && y >= 1 && y + 1 < m){
		t_v = arr[x][y] + arr[x][y-1] + arr[x][y+1] + arr[x-1][y];	
		result = max(result,t_v);
	}
	
	if( y + 1 < m && x >= 1 && x + 1 < n){
		t_v = arr[x][y] + arr[x+1][y] + arr[x-1][y] + arr[x][y+1];
		result = max(result,t_v);
	}
	
	if(x + 1 < n && y + 1 < m && y >= 1){
		t_v = arr[x][y] + arr[x+1][y] + arr[x][y+1] + arr[x][y-1];
		result = max(result,t_v);
	}
	
	if(x + 1 < n && y >= 1 && x >= 1){
		t_v = arr[x][y] + arr[x+1][y] + arr[x-1][y] + arr[x][y-1];
		result = max(result,t_v);
	}
	
	return result;
}

int main(){
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			cin >> arr[i][j];
		}
	}	

	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			visit[i][j] = 1;
			ans = max(ans,solution(i,j,1));
			ans = max(ans,solution_t(i,j));	
			visit[i][j] = 0;	
		}
	}
		
	cout << ans << '\n';
		
	return 0;
}
