#include <iostream>

using namespace std;

int ans1;
int ans2;

int main(){
	// a ->  ³ôÀÌ  // b-> È£ // c ¼Õ´Ô 
	int t;
	cin >> t;
	
	while(t--){
		int a,b,c;
		cin >> a >> b >> c ;
		
		ans1 = c%a ;
		ans2 = c/a + 1;
		
		if( ans1 == 0)
			ans1 = a;
		if(!(c%a))
			ans2 -= 1;
					
		cout << ans1*100 + ans2 <<'\n';
		
	}
	
	return 0;
}
