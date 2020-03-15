#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 13

using namespace std;

struct Horse{
	int x,y;
	int d;
};

int n,k,ans;
int arr[MAX][MAX];
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

vector<int> brr[MAX][MAX];
Horse h[MAX];
bool state = false;

void checkFunction(){
	
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			if(brr[i][j].size() >= 4 )
				state = true;
		
	return ;
}

void solution(){
	
	vector<int> temp;
	vector<int> cv;
	
	for(int i = 1 ; i <= k ; ++i){		
		
		int _x = h[i].x; 
		int _y = h[i].y;
		int _d = h[i].d;
		
		temp.clear();
		cv.clear();
		
		int cnt = 0;
		
		for(int j = 0 ; j < brr[_x][_y].size() ; j++){
			if(brr[_x][_y][j] == i){
				
				for(int l = j ; l < brr[_x][_y].size() ; ++l){
			
					temp.push_back(brr[_x][_y][l]);
					cnt++;
				}
				break;
			} 
		}

		for(int j = 0 ; j < cnt ; ++j)
			brr[_x][_y].pop_back();
		
		
		int nx = _x + dx[_d];
		int ny = _y + dy[_d];
		
		if( 1 <= nx && nx <= n && 1 <= ny && ny <= n ){
		
			if(arr[nx][ny] == 0){		
				for(int j = 0 ; j < temp.size() ; ++j){
					
					int nN = temp[j];
					h[nN].x = nx; 
					h[nN].y = ny;
					
					brr[nx][ny].push_back(nN);
				}
			}
			
			if(arr[nx][ny] == 1){
				
				for(int j = temp.size()-1 ; j >= 0 ; --j){
					
					cv.push_back(temp[j]);
				}
				
				for(int j = 0 ; j < cv.size() ; ++j){
					
					int nN = cv[j];
					h[nN].x = nx; 
					h[nN].y = ny;
					
					brr[nx][ny].push_back(cv[j]);
				}
			}
		}
		
		if(0 >= nx || nx > n || ny <= 0 || ny > n || arr[nx][ny] == 2){
			
			if(_d % 2 )
				_d += 1;
			else
				_d -= 1;
					
			int	nnx = _x + dx[_d];
			int nny = _y + dy[_d];
			
			h[i].d = _d;	
			
			if(arr[nnx][nny] == 2 || 0 >= nnx || nnx > n || nny <= 0 || nny > n ){
				for(int j = 0 ; j < temp.size() ; ++j){
					
					int nN = temp[j];
					h[nN].x = _x; 
					h[nN].y = _y;
					
					brr[_x][_y].push_back(temp[j]);
				}
			}else{
				if(arr[nnx][nny] == 0){
					for(int j = 0 ; j < temp.size() ; ++j){
					
						int nN = temp[j];
						h[nN].x = nnx; 
						h[nN].y = nny;
					
						brr[nnx][nny].push_back(temp[j]);
					}
				}
				else if(arr[nnx][nny] == 1){
					
					for(int j = temp.size()-1 ; j >= 0 ; --j){
						cv.push_back(temp[j]);
					}
				
					for(int j = 0 ; j < cv.size() ; ++j){
					
						int nN = cv[j];
						h[nN].x = nnx; 
						h[nN].y = nny;
					
						brr[nnx][nny].push_back(cv[j]);
					}
				}else{
					//
				}
			}
		}
		
		checkFunction();
		
		if(state == true)
			return ;
	}
	
	return ;
}

int main(){
	
	cin >> n >> k;
	
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			cin >> arr[i][j];
		
			
	for(int i = 1 ; i <= k ; ++i){
		cin >> h[i].x >> h[i].y >> h[i].d;
		brr[h[i].x][h[i].y].push_back(i);
	}
	
	while(++ans){
	
		solution();
		
		if(state)
			break;
			
		if(ans > 1000){
			cout << "-1" << '\n';
			return 0;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
