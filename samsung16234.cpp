#include <iostream>
#define MAX 51

using namespace std;

int n,l,r;
int arr[MAX][MAX];
int cpyArr[MAX][MAX];
int dx[4] = { -1, 0 ,1 ,0 };
int dy[4] = { 0 , 1, 0, -1};
bool state,final;
int ans;


void solution(int px,int py){
	
	for(int i = 0 ; i < 4; ++i){
		
		int nx = px + dx[i];
		int ny = py + dy[i];
		
		if(0 <= nx && nx < n && 0 <= ny && ny < n && !cpyArr[nx][ny]){
			
			int cp = arr[px][py] - arr[nx][ny];
			
			if(cp < 0)
				cp *= -1;
			
			if( l <= cp && cp <= r){
				cpyArr[nx][ny] = 1;
				state = true;
				solution(nx,ny);	
			}
		}
	}
	
	return ;
}

void function(){
	
	int num = 0 ;
	int cnt = 0 ;
	final = true;
	
	for(int i = 0 ; i < n ;++i){
		for(int j = 0 ; j < n ; ++j){
			if(cpyArr[i][j] == 1){
				num += arr[i][j];
				cnt++;
			}
		}
	}
	
	num = num/cnt;
	
	for(int i = 0 ; i < n ;++i){
		for(int j = 0 ; j < n ; ++j){
			if(cpyArr[i][j] == 1){
				arr[i][j] = num;
				cpyArr[i][j] = -1;
			}
		}
	}
	state = false;
	return ;
}

int main(){
	
	cin >> n >> l >> r;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			cin >> arr[i][j];
		}
	}
	while(1){
		final = false;
		
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				cpyArr[i][j] = 0;
			}
		}
		
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				if(cpyArr[i][j] == -1)
					continue;
				
				cpyArr[i][j] = 1;
				solution(i,j);
			
				if(state){
					function();
				}else{
					cpyArr[i][j] = 0;
				}
			}
		}
		
		if(!final)
			break;
		
		ans++;
	}
	cout << ans << '\n';
	return 0;
}
