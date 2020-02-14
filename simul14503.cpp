#include <iostream>
#include <queue>

using namespace std;

int arr[51][51];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1}; 

int ans;

queue<pair<pair<int,int>, int> > q;

int main(){
	
	int n,m;
	cin >> n >> m;
	int x,y,direction;
	cin >> x >> y >> direction;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			cin >> arr[i][j];			
		}
	}
	
	q.push(make_pair(make_pair(x,y),direction));
	
	while(!q.empty()){
		
		int _x = q.front().first.first;
		int _y = q.front().first.second;
		int _direction = q.front().second;
		bool status = false;
		
		q.pop();
		
		if(arr[_x][_y] == 0){
			arr[_x][_y] = 2;
			ans++;
		}
		
		for(int i = 0 ; i < 4 ; ++i){
			
			int ndirection = (_direction + (3-i))%4;
			int nx = _x + dx[ndirection];
			int ny = _y + dy[ndirection];
			
			if(0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] == 0){
				q.push(make_pair(make_pair(nx,ny),ndirection));
				status = true;
				
				break;
			}
		}
		
		if(!status){
			int nx = _x - dx[_direction];
			int ny = _y - dy[_direction];
			
			if(0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] != 1){
				q.push(make_pair(make_pair(nx,ny),_direction));

			}else{
				break;
			}			
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
