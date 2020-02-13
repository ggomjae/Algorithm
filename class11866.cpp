#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
	
	deque<int> dq;
	vector<int> v;
	int n;
	cin >>n;
	
	for(int i = 1 ; i <= n ;++i){
		dq.push_back(i);
	}
	
	int k;
	int temp;
	cin >> k;
	
	while(!dq.empty()){
		int cnt = k-1;
		while(cnt--){
			temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
		}
		temp = dq.front();
		v.push_back(temp);
		dq.pop_front();
	}
	
	cout << "<" ;
	for(int i = 0 ; i < v.size() ; ++i){
		cout << v[i] ;
		if(i != v.size()-1)
			cout << ", ";
	}
	cout << ">" ;
	return 0;
}
