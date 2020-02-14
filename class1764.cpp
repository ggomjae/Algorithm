#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> left_v;
vector<string> right_v;
vector<string> ans;

void solved(int low , int high, string str){
	
	
	
	while(low <= high){
		
		int mid = (low+high)/2;
		
		if(left_v[mid] == str){
			ans.push_back(str);
			return ;
		}	
		else if(left_v[mid] < str){
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	
	return ;
}

int main(){
	
	int n,m;
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; ++i){
		string str;
		cin >> str;
		left_v.push_back(str);
	}
	
	for(int i = 0 ; i < m ; ++i){
		string str;
		cin >> str;
		right_v.push_back(str);
	}
	
	sort(left_v.begin(),left_v.end());
	sort(right_v.begin(),right_v.end());
	
	for(int i = 0 ; i < right_v.size() ; ++i ){
		solved(0,left_v.size(),right_v[i]);		
	}
	
	cout << ans.size() << '\n';
	
	for(int i = 0 ; i < ans.size() ; ++i){
		cout << ans[i] << '\n';
	}

	return 0;
}
