#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[101];
int check[101];

int n;
int a, b;
int m ;
int cnt;
bool status;

int main(){
	
	cin >> n >> a >> b >> m;
	
	for(int i = 0 ; i < m ; ++i){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}	
	
	queue<pair<int,int> > q;
	q.push(make_pair(a,cnt));
	check[a] = 1;
	
	while(!q.empty()){
		int _x = q.front().first;
		int _cnt = q.front().second;
		
		q.pop();
		
		for(int i = 0 ; i < v[_x].size() ; ++i){
			
			int nx = v[_x][i];
			
			if(!check[nx]){
				
				if(nx == b){
					cout << _cnt + 1 << '\n';
					return 0;
				}
				
				q.push(make_pair(nx,_cnt + 1));
				check[nx] = 1;
			}
		}
	}
	
	if(!status){
		cout << "-1" << '\n';
	}
	
	return 0;
}
