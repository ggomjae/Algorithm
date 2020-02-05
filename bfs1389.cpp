#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v[101];
int check[101];
queue<pair<int,int> > q;
int ans[101];
int temp,index;

void init(){
	for(int i = 1 ; i <= n ; ++i){
		check[i] = 0;
	}
	
	while(!q.empty())
		q.pop();
		
	return ;
}

void bfs(int st){
	
	int cnt = 0 ;
		
	q.push(make_pair(st,cnt));
	check[st] = 1;
	
	while(!q.empty()){
		int _x = q.front().first;
		int _cnt = q.front().second;
		q.pop();
		
		for(int i = 0 ; i < v[_x].size() ; ++i){
			
			int nx = v[_x][i];
			if(!check[nx]){
				q.push(make_pair(nx,_cnt+1));
				ans[st] += _cnt+1;
				check[nx] = 1;
			}
		}
	}
	
	return ;		
}

int main(){
		
	cin >> n >> m ;
	
	for(int i = 0 ; i < m ; ++i){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	for(int i = 1 ; i <= n ; ++i){
		bfs(i);
		init();
	}
	
	temp = ans[1];
	index=1;
	
	for(int i = 2 ; i <= n ; ++i){
		if(temp > ans[i]){
			temp = ans[i];
			index = i;
		}
	}
	
	cout << index << '\n';
	
	return 0;
}
