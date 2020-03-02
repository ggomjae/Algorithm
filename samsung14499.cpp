#include <iostream>
#define MAX 20

using namespace std;

struct Node{
	int x, y;
};

struct Node node;

int n,m,x,y,k;
int dx[5] = {0,0,0,-1,1}; 
int dy[5] = {0,1,-1,0,0};

int arr[MAX][MAX];
int brr[7];

void changeArr(int pa, int pb, int pc, int pd,int c){

	int temp[4] = {brr[pa],brr[pb],brr[pc],brr[pd]};
	
	if(c == 1 || c == 2){
		brr[4] = temp[0]; 
		brr[6] = temp[1];
		brr[3] = temp[2];
		brr[1] = temp[3];
	}else{
		brr[5] = temp[0];
		brr[6] = temp[1];
		brr[2] = temp[2];
		brr[1] = temp[3];
	}

	return ;
}

void solution(int p){
	
	int nx = node.x + dx[p];
	int ny = node.y + dy[p];
	
	if( nx < 0 || nx >= n || ny < 0 || ny >= m){
		return ;
	}else{
		node.x = nx;
		node.y = ny;
	}
	
	if( p == 1){
		changeArr(1,4,6,3,1);
	}else if( p == 2){
		changeArr(6,3,1,4,2);
	}else if ( p == 3){
		changeArr(1,5,6,2,3);
	}else{
		changeArr(6,2,1,5,4);
	}
	
	if(arr[node.x][node.y] == 0){
		arr[node.x][node.y] = brr[1]; 
	}else{
		brr[1] = arr[node.x][node.y];
		arr[node.x][node.y] = 0;
	}

	cout << brr[6]<< '\n';
	
	return ;
}

int main(){
	
	cin >> n >> m >> node.x >> node.y >> k;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			cin >> arr[i][j];
		}
	}
	
	while(k--){
		int t_v;
		cin >> t_v;
		solution(t_v);
	}
	
	return 0;
}
