#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int ans;

int main(){
	
	deque<int> dq;
	queue<int> q;
	int n , m , k, cur;
	int left,right;
	
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; ++i)
		dq.push_back(i);
	
	for(int i = 0 ; i < m ; ++i){
		cin >> k;
		q.push(k);
	}
	
	for(int i = 0 ; i < m ; ++i){
		for(int j = 0 ; j < dq.size() ; ++j){
			if(dq[j] == q.front()){
				cur = j+1;
				q.pop();
				break;
			}
		}
		
		left = cur - 1;
		right = dq.size() - cur + 1;
		
		if( left < right){
			while(left--){
				int temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
				ans++;
			}
			dq.pop_front();
		}else{
			while(right--){
				int temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
				ans++;
			}
			dq.pop_front();
		}
		
	}
	
	cout << ans << '\n';
	
	return 0;
}
