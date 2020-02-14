#include <iostream>
#define MAX 100

using namespace std;

int a[MAX][MAX];
int check[MAX][MAX];
int n,k,ans;

void init(){
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j <n ; ++j){
			check[i][j] = 0;
		}
	}
	
	return ;
}

void rowFunction(int p){
	bool status = true;
	
	for(int i = 0 ; i < n-1 ; ++i){
		if((a[p][i] - a[p][i+1]) == 1 ){
			for(int j = i+1 ; j < i+1+k ; ++j){
				if(a[p][j] != a[p][i+1] || check[p][j] != 0){
					status = false;
					break;
				}
				check[p][j] = 1;
			}
		}else if((a[p][i] - a[p][i+1]) == -1){
			if( i - k +1 >= 0 ){
				for(int j = i - k +1 ; j <= i ; ++j){
					if(check[p][j] != 0){
						status = false;
						break;
					}
					check[p][j] = 1;
				}
				
			}else{
				status = false;
				break;
			}	
		}else if((a[p][i] - a[p][i+1]) == 0){
			continue;
		}else{
			status = false;
			break;
		}
	}
	
	if(status){
		ans++;
	}
	return ;
}

void colFunction(int p){
	
	bool status = true;
	
	for(int i = 0 ; i < n-1 ; ++i){
		if((a[i][p] - a[i+1][p]) == 1){
			for(int j = i+1 ; j < i+1+k; ++j){
				if(a[i+1][p] != a[j][p] || check[j][p] != 0){
					status = false;
					break;
				}
				check[j][p] = 1;
			}
		}else if((a[i][p] - a[i+1][p]) == -1){
			if( i - k +1 >= 0){
				for(int j = i-k +1; j <= i ; ++j){
					if(check[j][p] != 0){
						status = false;
						break;
					}
					check[j][p] = 1;
				}
			}else{
				status = false;
				break;
			}
		}else if((a[i][p] - a[i+1][p]) == 0 ){
			continue;
		}else{
			status = false;
			break;
		}
	}
	
	if(status){
		ans++;
	}
	return ;
}

int main(){
	
	cin >> n >> k;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			cin >> a[i][j];
		}
		
	}
	
	for(int i = 0 ; i < n ;++i){
		rowFunction(i);
	}
	
	init();
	
	for(int i = 0 ; i < n ; ++i){
		colFunction(i);
	}
	
	cout << ans << '\n';
	
	return 0;
}
