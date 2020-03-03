#include <iostream>
#include <algorithm>
#define MAX 12

using namespace std;

int arr[MAX];
int brr[4];
int n;

int max_value = -987654321;
int min_value = 987654321;

void solution(int pa, int pb, int pc , int pd, int sum, int cnt){
	
	if(cnt == n){
		max_value = max(max_value, sum);
		min_value = min(min_value, sum);
	}
		
	if(pa > 0){
		solution(pa - 1 , pb , pc , pd ,sum + arr[cnt],cnt + 1);	
	}
	if(pb > 0){
		solution(pa , pb - 1 , pc , pd ,sum - arr[cnt],cnt + 1);	
	}
	if(pc > 0 ){
		solution(pa  , pb , pc -1, pd ,sum * arr[cnt],cnt + 1);
	}
	if(pd > 0 ){
		solution(pa  , pb , pc , pd -1, sum / arr[cnt],cnt + 1);
	}
	
	return ;
}

int main(){
	
	cin >> n;
		
	for(int i = 0 ; i < n ; ++i){
		cin >> arr[i];
	}	
	
	for(int i = 0 ; i < 4; ++i){
		cin >> brr[i];
	}

	solution(brr[0],brr[1],brr[2],brr[3],arr[0],1);	
	
	cout << max_value << '\n';
	cout << min_value << '\n';
	
	return 0;
}
