#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int imp[10];
int temp;
int cnt;
queue<pair<int,int> > q;


void init(){
	
	while(!q.empty())
		q.pop();
		
	for(int i = 0 ; i < 10 ; ++i)
		imp[i] = 0;
	
	cnt = temp = 0;
		
	return ;
}

int main(){

	int t;
	cin >> t;

	while(t--){
		int n,m;
		cin >> n >> m;
		
		for(int i = 0 ; i < n ; ++i){
			int k;
			cin >> k;
			imp[k]++;			
			q.push(make_pair(i,k));
		}		
		
		while(!q.empty()){
			int x = q.front().first; // 자리 
			int y = q.front().second; // 중요도 
			q.pop();
			
			for(int i = 9 ; i >= 1 ; --i){
				if(imp[i]){
					temp = i;
					imp[i]--;
					break;
				}
			}
			
			if(temp == y && x == m){
				cnt++;
				cout << cnt << '\n';
				break;			
			}else if(temp == y){
				cnt++;		
			}else{
				q.push(make_pair(x,y));
				imp[temp]++;
			}
		}
		init();
	}
	
	return 0;
} 
