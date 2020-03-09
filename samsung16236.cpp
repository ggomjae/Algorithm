#include <iostream>
#include <queue>
#include <vector>
#define MAX 21

using namespace std;

struct Shark{
	int x,y;
	int size = 2;
	int cnt_size =0;
};

Shark s;

int arr[MAX][MAX];
int cpyArr[MAX][MAX];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n,ans;

vector<pair<int,int> > v;

void init(){
	
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < n ; ++j)
			cpyArr[i][j] = 0;
	
	v.clear();
	
	return ;
}

int solution(){
	int time = 1;
	bool state = false;
	
	queue<pair<int,int> > q;
	q.push(make_pair(s.x,s.y));
	cpyArr[s.x][s.y] = 1;
	
	while(!q.empty()){
		
		int t = q.size();
		
		for(int i = 0 ; i < t ; ++i){
		
			int _x = q.front().first;
			int _y = q.front().second;
			q.pop();
			
			for(int j = 0 ; j < 4; ++j){
				int nx = _x + dx[j];
				int ny = _y + dy[j];
				
				if(0 <= nx && nx < n && 0 <= ny && ny < n && !cpyArr[nx][ny] && arr[nx][ny] <= s.size){
					q.push(make_pair(nx,ny));
					cpyArr[nx][ny] = 1;
					
					if(arr[nx][ny] != 0 && s.size > arr[nx][ny]){
						v.push_back(make_pair(nx,ny));	
						
					}				
				}
			}
		}
		if(v.size() != 0){
			int nx = v[0].first;
			int ny = v[0].second;
				
			for(int j = 1 ; j < v.size() ; ++j){
				if(v[j].first < nx){
					nx = v[j].first; 
					ny = v[j].second;
				}else if(v[j].first == nx){
						
					if(v[j].second < ny){
						nx = v[j].first; 
						ny = v[j].second;
					}
				}else{
					continue;
				}
			}
				
			state = true;
			arr[nx][ny] = 9;
			arr[s.x][s.y] = 0;
			s.x = nx;
			s.y = ny;
			s.cnt_size++;
				
			if(s.size == s.cnt_size){
				s.size++;
				s.cnt_size = 0;
			}
		}
		
		if(state)
			break;
		
		time++;	
	}
	
	if(!state)
		time = -1;
		
	return time;
}

int main(){
		
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
	
		for(int j = 0 ; j < n ; ++j){
			cin >> arr[i][j];
			if(arr[i][j] == 9){
				s.x = i;
				s.y = j;		
			}
		}
	}
	
	while(1){
		init();
		int tempV = solution();
		
		if(tempV < 0)
			break;
		else
			ans += tempV;
	}
	
	cout << ans << '\n';
	
	return 0;
}
