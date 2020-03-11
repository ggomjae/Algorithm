#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

struct Node{
	int tx,ty;
	int ux,uy;
};

int n,m,t,ans;
int arr[MAX][MAX];
int cpyArr[MAX][MAX];
int dx[4] = { -1, 0, 1 , 0 };
int dy[4] = { 0, 1 , 0 ,-1 };

Node node;
vector<pair<int,int> > v;

bool node_state;

void spreadFunction(){

	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m ; ++j)
			cpyArr[i][j] = 0;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			
			if(arr[i][j] > 0){
				
				int cnt = 0;
				int amount = arr[i][j]/5;
				
				for(int l = 0 ; l < 4 ; ++l){
					
					int nx = i + dx[l];
					int ny = j + dy[l];
					
					if( 0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] != -1){
						
						cpyArr[nx][ny] += amount;
						cnt++;		
					}
				}
				cpyArr[i][j] += arr[i][j] - (cnt * amount) ;
			}
		}
	}
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			arr[i][j] = cpyArr[i][j];
		}
	}
	
	arr[node.tx][node.ty] = -1;
	arr[node.ux][node.uy] = -1;
	
	return ;
}

void solution(){
	
	int x = node.tx;
	int y = node.ty;

	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m ; ++j)
			cpyArr[i][j] = arr[i][j];
		
	for(int i = 1 ; i < m-1 ; ++i)
		cpyArr[x][i+1] = arr[x][i];
	
	for(int i = x ; i > 0; i--)
		cpyArr[i-1][m-1] = arr[i][m-1];
	
	for(int i = m-1 ; i > 0 ; i--)
		cpyArr[0][i-1] = arr[0][i];
	
	for(int i = 0 ; i < x-1 ; ++i)
		cpyArr[i+1][0] = arr[i][0];
	
	
	x = node.ux;
	y = node.uy;
	
	for(int i = 1 ; i < m-1 ; ++i)
		cpyArr[x][i+1] = arr[x][i];
	
	for(int i = x ; i < n-1; i++)
		cpyArr[i+1][m-1] = arr[i][m-1];
	
	for(int i = m-1 ; i > 0 ; i--)
		cpyArr[n-1][i-1] = arr[n-1][i];
	
	for(int i = n-1 ; i > x+1 ; --i)
		cpyArr[i-1][0] = arr[i][0];	
		
	for(int i = 0 ; i < n ; ++i)
		for(int j = 0 ; j < m ; ++j)
			arr[i][j] = cpyArr[i][j];		
	
	arr[node.tx][node.ty+1] = 0 ;
	arr[node.ux][node.uy+1] = 0 ;
		
	return ;
}

int ansFunction(){
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			if(arr[i][j] > 0)
				ans += arr[i][j];
		}
	}
	
	return ans;
}

int main(){
	
	cin >> n >> m >> t;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			cin >> arr[i][j];
			if(arr[i][j] == -1 && !node_state){
				node.tx = i,node.ty = j;
				node_state = true;
			}else if(arr[i][j] == -1 && node_state){
				node.ux = i,node.uy = j;
			}	
		}	
	}
	
	while(t--){
		spreadFunction();
		solution();	
	}
	
	cout << ansFunction() << '\n';
	
	return 0;
}
