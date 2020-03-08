#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 987654321

using namespace std;

int n,m;

vector<pair<int,int> > h;
vector<pair<int,int> > v;
vector<pair<int,int> > cpyV;

int calculate(){
	
	int result;
	int sum = 0;
	
	for(int i = 0 ; i < h.size() ; ++i){
		result = MAX;
		
		for(int j = 0 ; j < cpyV.size() ; ++j){
			
			int nx = h[i].first - cpyV[j].first;
			int ny = h[i].second -cpyV[j].second;
			
			if(nx < 0)
				nx *= -1;
			if(ny < 0)
				ny *= -1;
				
			result = min(result, nx + ny );  
		}
		sum += result;
	}
	
	return sum;
}

int solution(int cnt,int p){
	
	if( m == cnt)
		return calculate();
	
	
	int result = MAX;
	
	for(int i = p ; i < v.size() ; ++i){
		
		int nx = v[i].first;
		int ny = v[i].second;
		
		cpyV.push_back(make_pair(nx,ny));
		result = min(result,solution(cnt+1,i+1));
		cpyV.pop_back();
	}	
	
	return result;
}

int main(){
	
	cin >> n >> m;
	int x;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			cin >> x;
			if(x == 1)
				h.push_back(make_pair(i,j));
			if(x == 2)
				v.push_back(make_pair(i,j));
		}
	}
	
	cout << solution(0,0) <<'\n';
	
	return 0;
}
