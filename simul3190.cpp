#include <iostream>
#include <deque>
#include <queue>
#include <vector>

#define MAX 100

using namespace std;

int arr[MAX][MAX];
queue<pair<int,char> > q;
deque<pair<int,int> > dq;

int dx[4] = {-1,0,1,0 };
int dy[4] = { 0,1,0,-1};
int direction = 1;
int time;

int main(){
	
	int n,k;
	cin >> n >> k;
	
	for(int i = 0 ; i < k ; ++i){
		int a,b;
		cin >> a >> b;
		arr[a-1][b-1] = 1;
	}
	
	int l;
	cin >> l;
	
	for(int i = 0 ; i < l ; ++i){
		int a;
		char c;
		cin >> a >> c;
		q.push(make_pair(a,c));
	}
	
	dq.push_back(make_pair(0,0));
	arr[0][0] = 2;
	
	while(++time){
		
		int _x = dq.front().first;
		int _y = dq.front().second;
			
		int nx = _x + dx[direction];
		int ny = _y + dy[direction];
		
		if(nx < 0 || nx >= n || ny < 0 || ny >=n || arr[nx][ny] == 2){
		
			break;
		}else{
			dq.push_front(make_pair(nx,ny));
		
			if(arr[nx][ny] == 1){
				arr[dq.back().first][dq.back().second] = 2 ;
				arr[nx][ny] = 2;		
			}else{
				arr[dq.back().first][dq.back().second] = 0 ;
				arr[nx][ny] = 2;
				dq.pop_back();
			}
		}
		
		if(q.front().first == time){
			if(q.front().second == 'D'){
				direction += 1;
				if(direction > 3){
					direction = 0;
				}
			}else{
				
				direction -= 1;
				if(direction <0){
					direction = 3;
				}
			}	
			q.pop();
		}
	}	
		
	cout << time << '\n';
	
	return 0;
}
