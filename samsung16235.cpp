#include <iostream>
#include <vector>
#include <algorithm> 
#define MAX 11

using namespace std;

int n,m,k;
int cpyArr[MAX][MAX]; // 겨울지나면 주는 양분 
int arr[MAX][MAX];  // 현재 양분 
vector<int> realTree[MAX][MAX]; // 각 땅마다 나무 
vector<pair<pair<int,int>, int> > dieTree;
 
int dx[8] = {-1 , -1 , 0 ,1 ,1 ,1 ,0 ,-1};
int dy[8] = {0 ,1,1 ,1 ,0 , -1 , -1 , -1};

int ansFunction(){
	
	int ans = 0;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			ans += realTree[i][j].size();
		}
	}
	
	return ans;
}

void treeInit(){
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n; ++j){
			if(realTree[i][j].size())
				sort(realTree[i][j].begin(),realTree[i][j].end());
		}
	}
	return ;
}

int main(){
	
	cin >> n >> m >> k;
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < n ; ++j){
			cin >> cpyArr[i][j];
			arr[i][j] = 5;			
		}
	}
	
	int x, y, t;
	
	for(int i = 0 ; i < m ; ++i){
		cin >> x >> y >> t;
		realTree[x-1][y-1].push_back(t);
	}
	
	while(k--){
		treeInit();
		dieTree.clear();
			
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				if(realTree[i][j].size()){
					int number = 0 ;
					for(int l = 0 ; l < realTree[i][j].size() ;++l){
						if(arr[i][j] >= realTree[i][j][l]){
							arr[i][j] -= realTree[i][j][l];
							realTree[i][j][l]++;
						}else{
							
							number++;
							dieTree.push_back(make_pair(make_pair(i,j),realTree[i][j][l]/2));
						}	
					}
					for(int l = 0 ; l < number ; ++l){
					
						realTree[i][j].pop_back();
					}
				}
			}
		}

		for(int i = 0 ; i < dieTree.size() ; ++i){
			
			int nx = dieTree[i].first.first;
			int ny = dieTree[i].first.second;
			int m = dieTree[i].second;
			
			arr[nx][ny] += m;
		}
		
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				if(realTree[i][j].size()){
					for(int l = 0 ; l < realTree[i][j].size() ; ++l){
						if(realTree[i][j][l] % 5 == 0){
							for(int q = 0 ; q < 8 ; ++q){
								
								int nx = i + dx[q];
								int ny = j + dy[q];
								
								if(0 <= nx && nx < n && 0 <= ny && ny < n){
									realTree[nx][ny].push_back(1);	
								}
							}
						}
					}
				}
			}
		}
		
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				arr[i][j] += cpyArr[i][j];
			}
		}
	}
	cout << ansFunction() << '\n';
	
	return 0;
}
