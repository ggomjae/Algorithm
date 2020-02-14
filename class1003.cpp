#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int> > v(50);

int main(){
	
	int t,x;
	cin >> t;
	
	v[0].first = 1;v[0].second= 0;
	v[1].first = 0;v[1].second= 1;
	
	while(t--){
		int x;
		cin >> x;
		
		for(int i = 2 ; i <= x ; ++i){
			v[i].first = v[i-1].first + v[i-2].first;
			v[i].second = v[i-1].second + v[i-2].second;
		}
		
		cout << v[x].first << " " << v[x].second << '\n';
	}
	
	return 0;
}
