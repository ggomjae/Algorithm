#include <iostream>
#define MAX 350
using namespace std;

int n;
char arr[MAX][7];
int ans[50][50];
int ansi,ansj;
int solution(int p,int cp){
	int cnt = 0;
	
	for(int i = 0 ; i < 5 ; ++i){
		for(int j = 0 ; j < 7 ; ++j){
			if(arr[5*p + i][j] != arr[5*cp + i][j]){
				cnt++;
			}
		}
	}
	
	return cnt;
}

int main(){
	
	cin >> n;
	int t = 987654321;
	
	for(int i = 0 ; i < n*5 ; ++i){
		for(int j = 0 ; j < 7 ; ++j){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = i+1 ; j < n ; ++j){
			ans[i][j] = solution(i,j);
			
			if( t > ans[i][j]){
				ansi = i;
				ansj = j;
				t = ans[i][j];	
			}
		}
	}
	cout << ansi+1 << " " << ansj+1 << '\n';
	return 0;
}
