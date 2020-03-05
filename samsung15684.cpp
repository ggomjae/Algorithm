#include <iostream>
#define MAX 31
using namespace std;

int n ,m ,k;
int arr[MAX][MAX];

bool checkFunction(){
	
	for(int i = 1 ; i <= m ; i++){
		
		int y = i;
		int x = 0;
		
		for(int j = 1 ; j <= n ; ++j){
			x++;
			if(arr[x][y]){
				y++;
			}else if(arr[x][y-1]){
				y--;
			}		
		}
		if(i != y){
			
			return false;
		}
	}
	
	return true;
}

bool solution(int x, int y ,int cnt,int de){
	
	if(cnt == de){
	
		if(checkFunction())
			return true;
		
		return false;
	}
	
	int cpyArr[MAX][MAX];
	
	for(int i = 0 ; i <= n ; ++i){
		for(int j = 0 ; j <= m ; ++j)
			cpyArr[i][j] = arr[i][j];
	}
	
	
	for(int i = x; i <= n ; ++i){
		for(int j = 1 ; j < m ; ++j){
			if(arr[i][j] == 0 && arr[i][j-1] == 0 && arr[i][j+1] == 0){
				arr[i][j] = 1;
			
				if(solution(i,j,cnt + 1 , de)){
					return true;
				}
				
				for(int index = 0 ; index <= n ; ++index){
					for(int outIndex = 0 ; outIndex <= m ; ++outIndex)
						arr[index][outIndex] = cpyArr[index][outIndex];
				}
			}else{
				continue;
			}
		}
	}
	
	return false;
}

int main(){
	
	cin >> m >> k >> n;
	
	for(int i = 0 ; i < k ; ++i){
		int x,y;
		cin >> x >> y;
		arr[x][y] = 1;
	}
	
	if(checkFunction()){
		cout << "0" << '\n';
		return 0;
	}
	
	for(int i = 1 ; i <= 3; ++i){
		if(solution(1,1,0,i)){
			cout << i << '\n';
			return 0;	
		}		
	}
	
	cout << "-1" << '\n';
	return 0;
}
