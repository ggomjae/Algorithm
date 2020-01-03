#include <iostream>

using namespace std;

bool check[101][101] = {false, };

void solve(int n , int a[][101], int result[][101]){
	
	
}

int main(){
	
	int n ;
	cin >> n;
	int a[101][101] = {0,};
	int result[101][101] = {0,};
	
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j){
			cin >> a[i][j];
		}	
	}
	
	solve(n,a,result);
		
	return 0;
}
