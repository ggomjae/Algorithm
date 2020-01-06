#include <iostream>
#include <vector>
#define N 6

using namespace std;

vector<int> v;
vector<int> v_a;
int t;
int val;

void init(){
	
	v.clear();
	v_a.clear();
	
	return;
}

void print(){
	
	for(int i = 0 ; i < v_a.size(); ++i){
		cout << v[v_a[i]] << " ";
	}
	cout << '\n';
	return ;
}

void solve(int cnt){
	
	if(v_a.size() == N){
		print();
		
		return ;
	}
	
	for(int i = cnt+1 ; i < t ; ++i){
		v_a.push_back(i);
		solve(i);
		v_a.pop_back();
	}
	
	return ;
}

int main(){
	
	cin >> t;
	
	while( t != 0){
		
		for(int i = 0 ; i < t ; ++i){
			cin >> val;
			v.push_back(val);
		}
		
		solve(-1);
		init();
		cout << '\n';
		cin >> t;
	}	
	
	return 0;
}
