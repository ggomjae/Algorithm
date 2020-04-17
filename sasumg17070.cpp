#include <iostream>
#define N 17

using namespace std;

int n;
int ans;
int arr[N][N];

int dx[4] = { 0, 0, 1, 1 };
int dy[4] = { 0, 1, 1, 0 };

void solution(int px, int py , int pt){
	
	if(px == n && py == n){
		ans++;
		return ;
	}
	
	for(int i = 1 ; i <= 3 ; ++i){
		
		int nx = px + dx[i];
		int ny = py + dy[i];
		
		if( pt == 1 && i == 3 )
			continue;
		
		if( pt == 3 && i == 1)
			continue;
		
		
		if( nx > n || ny > n || arr[nx][ny] == 1)
			continue;
		
		if( i == 2 && (arr[nx-1][ny] == 1 || arr[nx][ny-1] == 1) )
			continue;
			
		solution(nx,ny,i);
	}
	
	return ;
}

int main(){
	
	cin >> n;
	
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			cin >> arr[i][j];
	
	solution(1,2,1);
	cout << ans << '\n';
	
	return 0;
}
