#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check[50][50];
int a[50][50];
int dx[4] = {0 , 1 , 0 , -1};
int dy[4] = {-1, 0 , 1 , 0 };
int result ;
vector<pair<int,int> > v;
queue<pair<int,int> > q;

void init(){
	
	v.clear();
	result = 0 ;
	
	while(!q.empty()){
		q.pop();
	}
	
	
	for(int i = 0 ; i < 50; ++i){
		
		for(int j = 0 ; j < 50 ; ++j){
			a[i][j] = 0 ;
			check[i][j] = false;
		}
	}
		
	return ;
}

void bfs(int w, int h){
	
	for(int i = 0 ; i < v.size() ; ++i){
		if(!check[v[i].first][v[i].second]){
			q.push(make_pair(v[i].first, v[i].second));
			result++;
		}
	
		while(!q.empty()){
		
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
		
			for(int i = 0 ; i < 4 ; ++i ){
			
				int nx = x + dx[i];
				int ny = y + dy[i];
			
				if( nx < 0 || nx >= w || ny < 0 || ny >= h || a[nx][ny] == 0 || check[nx][ny] == true){
					continue;
				}
				
				check[nx][ny] = true;
				q.push(make_pair(nx,ny));	
			}		
		}
	}
	
	cout << result << '\n';
}


int main(){
	
	int n,w,h,cnt,r,c;
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> w >> h >> cnt;
		init();
		
		for(int j = 0 ; j < cnt ; ++j){
			
			cin >> r >> c;
			a[r][c] = 1;
			v.push_back(make_pair(r,c));
		}		
		
		bfs(w,h);
	}
	
	return 0;
}
