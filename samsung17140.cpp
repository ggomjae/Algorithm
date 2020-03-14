#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;

vector<pair<int,int> > v;
int cpyArr[MAX];
int arr[MAX][MAX];
int r,c,k,ans;
int n = 3;
int m = 3;

bool cmp(pair<int,int>& a, pair<int,int>& b){
	
	if(a.second < b.second)
		return true;
	else if(a.second > b.second)
		return false;			
	else{
		if(a.first <= b.first)
			return true;
		else
			return false;
	}
			
}

void init(){
	
	v.clear();
	for(int i = 1 ; i <= MAX ; ++i)
		cpyArr[i] = 0;
	
	return ;
}

void rFunction(){
	
	int _m = 0;
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			
			if(arr[i][j] == 0)	
				continue;
			if(!cpyArr[arr[i][j]]){
				v.push_back(make_pair(arr[i][j],1));
				cpyArr[arr[i][j]]++;	
			}else{
				for(int l = 0 ; l < v.size() ; ++l){
					if(v[l].first == arr[i][j])
						v[l].second++;
				}
			}
		}
		for(int j = 1 ; j <= m ; ++j)
			arr[i][j] = 0;
		sort(v.begin(),v.end(),cmp);
		int cnt = 0;
		int size = v.size();
		if(v.size() > 50)
			size = 50;
		for(int j = 1; j <= size*2 ; j += 2,cnt++){
			
			arr[i][j] = v[cnt].first;
			arr[i][j+1] = v[cnt].second;
		}
		if( _m < size*2)
			_m = size*2;
		init();
	}
	
	m = _m;
	
	return ;
}

void cFunction(){
	
	int _n = 0;
	
	for(int i = 1 ; i <= m ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			
			if(arr[j][i] == 0)
				continue;
			if(!cpyArr[arr[j][i]]){
				v.push_back(make_pair(arr[j][i],1));
				cpyArr[arr[j][i]]++;	
			}else{
				for(int l = 0 ; l < v.size() ; ++l){
					if(v[l].first == arr[j][i])
						v[l].second++;
				}
			}
		}
		for(int j = 1 ; j <= n ; ++j)
			arr[j][i] = 0;
		sort(v.begin(),v.end(),cmp);
		int cnt = 0;
		int size = v.size();
		if(v.size() > 50)
			size = 50;
		for(int j = 1; j <= size*2 ; j += 2,cnt++){
			arr[j][i] = v[cnt].first;
			arr[j+1][i] = v[cnt].second;
		}
		if( _n < size*2)
			_n = size*2;
		init();
	}
	
	n = _n;
	
	return ;
}

void solution(){
	
	if(n >= m)
		rFunction();
	else
		cFunction();
	
	return ;
}

int main(){
	
	cin >> r >> c >> k;
	for(int i = 1 ; i <= 3 ; ++i)
		for(int j = 1 ; j <= 3 ;++j)
			cin >> arr[i][j];	
	
	while(1){
		
		if(arr[r][c] == k)
			break;
		
		if(ans > 100){
			cout<< "-1" << '\n';
			return 0;
		}
		
		solution();
		ans++;
	}	
	
	cout << ans << '\n';
	
	return 0;
}
