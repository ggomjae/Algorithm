#include <iostream>
#include <deque>
#include <algorithm>
#define MAX 20

using namespace std;

int n;
int arr[MAX][MAX];
int d[4] = {1,-1 ,1, -1};
int s[4] = {0,1, 0 , 1 };

void function(int p){
	
	deque<int> dq;

	for(int i = 0 ; i < n ; ++i){
		while(!dq.empty())
			dq.pop_front();
			
		int r = (n-1)*s[p];
		bool check = false;
		
		while(0 <= r && r < n){
			int &temp = p & 2 ? arr[r][i] : arr[i][r];
			
			if(temp){
			
				if(check && dq.back() == temp){
					dq[dq.size()-1] *= 2;
					check = false;
					temp = 0;
				}else{
					dq.push_back(temp);
					check = true;	
					temp = 0;
				}		
			}
			
			r += d[p];
		} 
		
		r = (n-1)*s[p];
		
		while(!dq.empty()){
			int &temp = p & 2 ? arr[r][i] : arr[i][r];
		
			temp = dq.front();
			dq.pop_front();
			r += d[p];
		}
	}	
	
	return ;
}

int solution(int dep){
	
	if(dep == 5){
		int ans = 0;
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				ans = max(ans,arr[i][j]);
			}
		}		
		return ans;
	}
	
	int cpyArr[MAX][MAX];
	int num = 0 ;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			cpyArr[i][j] = arr[i][j];
		}
	}
	
	for(int i = 0 ; i < 4 ; ++i){
		function(i);
		num = max(num , solution(dep + 1));
	
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				arr[i][j] = cpyArr[i][j];
			}
		}
	}
	
	return num;
}

int main(){
	
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			cin >> arr[i][j];
		}
	}
	
	cout << solution(0) << '\n';
	
	return 0;
}
