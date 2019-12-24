#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	vector<int> v;
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	do{
		
		for(int i = 0 ; i < v.size() ; ++i){
			cout << v[i]<< " ";
		}
		
		cout << '\n';
		
	}while(next_permutation(v.begin(),v.end()));
	
	for(int i = 0 ; i < v.size() ; ++i)  //1 2 3 4 가나옴. 원본자체가 바뀌진않음. 
	{
		cout << v[i]<< " ";
	}
	
	cout << next_permutation(v.begin(),v.end()) << '\n'; // 1 2 3 4 라 바꿀수있으므로 true , 1 이나옴 
	
	
	return 0;
}
