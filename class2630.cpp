#include <iostream>

using namespace std;

int arr[128][128];
int ans[2];

void function(int x , int y , int k){
	
	bool status = true;
	
	if(k==1){
		ans[arr[x][y]]++;
		return;
	}
	
	for(int i = x ; i < k + x ; ++i){
		for(int j = y ; j < k + y ; ++j){
			if(arr[i][j] != arr[x][y]){
				status = false;
				break;
			}
		}
	}
	if(!status){
		function(x,y,k/2);
		function(x ,y + k/2 , k/2);
		function(x + k/2,y,k/2); 
		function(x+k/2 ,y+k/2 , k/2);
		
		return ;
	}else{
		if(arr[x][y] == 1){
			ans[1]++;			
		}else{
			ans[0]++;
		}
	}
	return ;		
}

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			cin >> arr[i][j] ;
		}
	}
	
	function(0,0,n);
	
	cout << ans[0] << '\n';
	cout << ans[1] <<'\n';
	
	return 0;
}
