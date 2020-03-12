#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

int n,m,k,ans;
pair<pair<int,int>,int > arr[MAX][MAX];
pair<pair<int,int>,int > cpyArr[MAX][MAX];

int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,1,-1};

void init(){
	
	for(int i = 1; i <= n ; ++i)
		for(int j = 1 ; j <= m ; ++j)
			cpyArr[i][j].first.first = cpyArr[i][j].first.second = cpyArr[i][j].second = 0;
 	
	return ;
}

void calculation(){
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			
			if(arr[i][j].second != 0 ){
			
				int dir= arr[i][j].first.second;
				int s = arr[i][j].first.first;
				int x = i;
				int y = j;
				
				if(dir == 1 || dir == 2){
					int temp = s % ((n-1) * 2);
					for(int l = 0 ; l < temp ; l++){
						
						x += dx[dir];
						y += dy[dir];
						
						if( x == 0 ){
							x = 2;
							dir = 2;
						}
						
						if( x == n + 1){
							x = n - 1;
							dir = 1;
						}
					}
				}else{
					int temp = s % ((m-1) * 2);
					for(int l = 0 ; l < temp ; l++){
						x += dx[dir];
						y += dy[dir];
						
						if( y == 0 ){
							y = 2;
							dir = 3;
						}
						
						if( y == m + 1){
							y = m - 1;
							dir = 4;
						}
					}	
				}
				
				if( cpyArr[x][y].second < arr[i][j].second){
				
					cpyArr[x][y].first.first = s;
					cpyArr[x][y].first.second = dir;
					cpyArr[x][y].second = arr[i][j].second;	
				}
			}
		}
	}
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			arr[i][j].first.first = cpyArr[i][j].first.first;
			arr[i][j].first.second = cpyArr[i][j].first.second;
			arr[i][j].second = cpyArr[i][j].second;
		}
	}
	
	return ;
}

int solution(int pt){
	
	int result = 0;
	
	for(int i = 1 ; i <= n ; ++i){
		if( arr[i][pt].second != 0 ){
			result = arr[i][pt].second;
			arr[i][pt].first.first = arr[i][pt].first.second = arr[i][pt].second = 0;
			
			return result;
		}
	}
	
	return result;
}

int main(){
	
	cin >> n >> m >> k;
	int r,c,s,d,z;
	
	for(int i = 1; i <= k ; ++i){
		
		cin >> r >> c >> s >> d >> z;
		arr[r][c] = make_pair(make_pair(s,d),z);
	}
	
	for(int i = 1 ; i <= m ; ++i){ 
		init();
		ans += solution(i);
		calculation(); 
	}
	
	cout << ans << '\n';
		
	return 0;
}
