#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int check[101];

vector<int> v[101];

int main(){
	
	int n,k;
	cin >> n >> k;
	
	for(int i = 0 ; i < k ; ++i){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	int ans = 0;
	
	queue<int> q;
	check[1] = 1;
	q.push(1);
	
	while(!q.empty()){
		int _x = q.front();
		q.pop();
		
		for(int i = 0 ; i < v[_x].size() ; ++i){
			int nx = v[_x][i];
			
			if(check[nx] == 0){
				ans++;
				check[nx] = 1;
				q.push(nx);
			} 
		} 
	}
	
	cout << ans;
	
	return 0;
}
