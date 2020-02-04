#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[301][301];
int check[301][301];

int dx[8] = {-2,-2,-1,1,2,2,1,-1};
int dy[8] = {-1,1,2,2,1,-1,-2,-2};

int t,k;
int a,b,c,d;
int ans;
bool stop;
	
queue<pair<int,pair<int,int> > > q;

void init(int k){
	
	for(int i = 0 ; i < k ; ++i){
		for(int j = 0 ; j < k ; ++j){
			arr[i][j] = 0;
			check[i][j] = 0;
		}
	}
	
	while(!q.empty())
		q.pop();
		
	ans = 0 ;
	stop = false; 
	
	return ;
}

int main(){
	
	cin >> t;
	
	while(t--){
		
		cin >> k;
		cin >> a >> b >> c >> d;
		
		check[a][b] = 1;
		arr[a][b] = 1;
		q.push(make_pair(a ,make_pair(b,ans)));
		
		while(!q.empty()){
			
			int _x = q.front().first;
			int _y = q.front().second.first;
			int _ans = q.front().second.second;
			q.pop();
			for(int i = 0 ; i < 8 ; ++i){
				
				int nx = _x + dx[i];
				int ny = _y + dy[i];
				
				if(0 <= nx && nx < k && 0 <= ny && ny < k){
					if(!check[nx][ny]){
						if(nx == c && ny == d){
							ans = _ans + 1;
							stop = true;
							break;
						}
						q.push(make_pair(nx,make_pair(ny,_ans+1)));
						check[nx][ny] = 1;
					}
				}
			}
			
			if(stop)
				break;
		}	
		cout << ans << '\n';
		
		init(k);
	}
	
	return 0;
}
