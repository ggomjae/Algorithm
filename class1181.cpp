#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
	
	int n;
	string str;
	bool status = true;
	vector<pair<int,string> > v;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> str;
		status = true;
		for(int j = 0 ; j < v.size() ; ++j){
			if(str == v[j].second)
				status = false;
		}
		if(status)
			v.push_back(make_pair(str.length(),str));
	}
	
	sort(v.begin(),v.end());
	
	for(int i = 0 ; i < v.size() ; ++i){
		cout << v[i].second << '\n';
	}
	
	
	return 0;
}
