#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<string,int> > v;
vector<pair<string,int> > sv;

int function1(string str){
	
	int low = 0 ;
	int high = sv.size();
	
	while(low <= high){
		
		int mid = (low + high)/2;
		
		if(sv[mid].first == str){
			return sv[mid].second;
		}else if(sv[mid].first < str){
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
}

string function2(int number){
	
	return v[number-1].first;
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	
	for(int i = 1 ; i <=n ; ++i){
		string str;
		cin >> str;		
		v.push_back(make_pair(str,i));	
		sv.push_back(make_pair(str,i));
	}
	
	sort(sv.begin(),sv.end());
	
	for(int i = 0 ; i < m ; ++i){
      
      string str;
      cin >> str;
      if( 0 < str[0] - '0' && str[0] - '0' <= 9 ){
         int number = 0 ;
         
         for(int j = 0 ; j < str.length() ; ++j){
               number = 10*number+ (str[j] - '0');
         }
         cout << function2(number) << '\n';
      }else{
         cout << function1(str) << '\n';
      }
   }
	
	return 0;
}
