#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,temp;
	cin >> n;
	priority_queue<int,vector<int> ,greater<int> > pq;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> temp;
		if(temp >0){
			pq.push(temp);	
		}else if(temp ==0){
			if(pq.empty()){
				cout << "0" << '\n';
			}else{
				cout << pq.top()<<'\n';
				pq.pop();	
			}
		}		
	}
	
	return 0;
}
