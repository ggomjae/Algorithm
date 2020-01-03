#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void result(int _i){
	if( v.size() == 3){
		for(int i = 0 ; i < v.size(); ++i){
			cout << v[i] << ' ';
		}
		cout << '\n';
		return ;
	}else{
		for(int i = _i+1 ; i<=5 ; ++i){
			v.push_back(i);
			result(i);
			v.pop_back();	
		}	
	}	
}

int main(){
	
	for(int i = 1 ; i <= 5 ; ++i){
		v.push_back(i);
		result(i);
		v.pop_back();
	}
	
	return 0;
}
