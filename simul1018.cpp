#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string w[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string b[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

string str[50];
int ans = 987654321;

int function(int x , int y){
	
	int bCnt = 0 ;
	int wCnt = 0 ;
	
	for(int i = x ; i < x + 8 ; ++i){
		for(int j = y ; j < y + 8 ; ++j){
			if(str[i][j] != w[i-x][j-y])
				wCnt++;
		}
	}	
	
	for(int i = x ; i < x + 8 ; ++i){
		for(int j = y ; j < y + 8 ; ++j){
			if(str[i][j] != b[i-x][j-y])
				bCnt++;
		}
	}	
	
	return min(bCnt,wCnt);
}

int main(){
	
	int n,m;
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> str[i];
	}	
	
	for(int i = 0 ; i + 7 < n; ++i){
		for(int j = 0 ; j + 7 < m ; ++j){
			ans = min(ans,function(i,j));
		}
	}
	
	cout << ans << '\n';
	return 0;
}
