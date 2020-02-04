#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

string str[101];
char arr[101][101]; 
char cpyArr[101][101]; 
int check[101][101];
int dx[4] = { 0, 0, -1,1};
int dy[4] = {-1, 1, 0, 0};

queue<pair<int,int> > q;
int n;
int cnt ;

void bfs(int x , int y ){
	
	check[x][y] = 1;
	q.push(make_pair(x,y));	
	
	while(!q.empty()){
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();
		
		for(int i = 0 ; i < 4 ; ++i ){
			int nx = _x + dx[i];
			int ny = _y + dy[i];
			
			if(0 <= nx && nx < n && 0 <= ny && ny < n){
				if(!check[nx][ny] && arr[nx][ny] == arr[_x][_y]){
					q.push(make_pair(nx,ny));
					check[nx][ny] = 1;
				}
			}
		}
	}
	
	return ;
}

int main(){
	
	
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> str[i];
	}	
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < str[i].length() ; ++j){
			arr[i][j] = str[i][j];
			if(str[i][j] == 'R')
				cpyArr[i][j] = 'G';
			else
				cpyArr[i][j] = str[i][j];
		}
	}
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			if(!check[i][j]){
				cnt++;
				bfs(i,j);
			}
		}
	}
	
	cout << cnt << " ";
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			arr[i][j] = cpyArr[i][j];
			check[i][j] = 0 ;
		}
	}
	
	while(!q.empty())
		q.pop();
	cnt = 0 ;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			if(!check[i][j]){
				cnt++;
				bfs(i,j);
			}
		}
	}
	
	cout << cnt << '\n';
	
	return 0;
}
