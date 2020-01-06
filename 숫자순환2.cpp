#include <iostream>
#include <vector>
#define N 6

using namespace std;

vector<int > v;

void print(){
	
	for(int index =0  ; index < v.size() ; ++index){
		cout << v[index] << ' ';
	}
	cout << '\n';
}

void solve(int cnt){
	
	if(v.size() == 3){
		print();
		return;
	}
	
	for(int index = cnt + 1 ; index <= N ; ++index){
		v.push_back(index);
		solve(index);
		v.pop_back();
	}
	
}

int main(){
	
	solve(0);  // 1 2 3 -> 1 2 4 -> 1 2 5 -> 1 2 6 -> 1 3 4 -> 1 3 5  index
	
	return 0;
}
