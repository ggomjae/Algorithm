#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 51
#define MAXNUMBER 987654321

using namespace std;

int n,m;
int ans = MAXNUMBER;
int arr[MAX][MAX];
int cpyArr[MAX][MAX];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

vector<pair<int,int> > v;
vector<int> cv;
queue<pair<pair<int,int>, int > > q;

void init(){
	
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < n ; ++j)
			cpyArr[i][j] = arr[i][j];
		
	while(!q.empty())	
		q.pop();
	
	return ;
}

int solution(){
	
	while(!q.empty()){
		
		int _x = q.front().first.first;
		int _y = q.front().first.second;
		int t = q.front().second;
		q.pop();
		
		for(int i = 0 ; i < 4; ++i){
			
			int nx = _x + dx[i];
			int ny = _y + dy[i];
			
			if(0 <= nx && nx < n && 0 <= ny && ny < n){
				if(cpyArr[nx][ny] == 0 ){
					q.push(make_pair(make_pair(nx,ny),t+1));
					cpyArr[nx][ny] = t+1;
				}else if(cpyArr[nx][ny] == -1){
					//
				}else if(cpyArr[nx][ny] == -2){
					q.push(make_pair(make_pair(nx,ny),t+1));
					cpyArr[nx][ny] = -1;
				}else if(cpyArr[nx][ny] == -3){
					//
				}else{
					//
				}
			}
		}		
	}	
	
	int maxAns = -MAXNUMBER;
	bool zeroStatus = false;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			if(cpyArr[i][j] == 0)
				return MAXNUMBER;
			if(maxAns < cpyArr[i][j])
				maxAns = cpyArr[i][j];
			if(cpyArr[i][j] > 0)
				zeroStatus = true;
		}
	}
	
	if(!zeroStatus)
		return 0;
		
	return maxAns;
}

int main(){
	// -1 현재 바이러스 , -2 비활성바이러스  -3 벽 
	cin >> n >> m ;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ;j < n ; ++j){
			cin >> arr[i][j];
			if(arr[i][j] == 2){
				v.push_back(make_pair(i,j));
				arr[i][j] = -2;	
			}
			
			if(arr[i][j] == 1)
				arr[i][j] = -3;
		}
	}
	
	for(int i = 0 ; i < v.size()-m; ++i)
		cv.push_back(0);
	for(int i = 0 ; i < m ; ++i)
		cv.push_back(1);	
		
	do{
		init();
	
		for(int i = 0 ; i < cv.size() ; ++i){
			if(cv[i] == 1){
				q.push(make_pair(make_pair(v[i].first,v[i].second),0));
				cpyArr[v[i].first][v[i].second] = -1;
			}
		}	
		
		ans = min(ans,solution());
	}while(next_permutation(cv.begin(),cv.end()));
	

	if(ans == MAXNUMBER){
		cout << "-1" << '\n';
		return 0;
	}
	
	cout << ans << '\n';

	return 0;
}
