#include <iostream>
#include <algorithm>

using namespace std;

int result;
int ans;

int main(){
	
	
	for(int i = 0 ; i < 4 ; ++i){
		int minus,plus;
		cin >> minus >> plus;
		
		result += plus;
		result -= minus;
		
		ans = max(ans,result);
	}
	
	cout << ans << '\n';
	
	return 0;
}
