#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
	
	vector<string> v;
	v.push_back("abcd");
	v.push_back("abc");
	v.push_back("ac");
	v.push_back("acd");
	
	for(int i = 0 ; i < v.size() ; ++i){
		cout << v[i] << '\n';
	}
	
	sort(v.begin(),v.end());
	
	cout << '\n';
	
	for(int i = 0 ; i < v.size() ; ++i){
		cout << v[i] << '\n';
	}
	 
	// °á°ú 
	abcd
	abc
	ac
	acd
	 
	abc
	abcd
	ac
	acd
	
	return 0;
}
