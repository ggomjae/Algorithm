#include <iostream>
#define NUM 64
using namespace std;

int x,ans;
int temp = NUM;

int main(){
	
	cin >> x;
	
	while(x){
		if(temp <= x){
			ans++;
			x -= temp;
		}
		
		temp /= 2;
	}
	cout << ans << '\n';
	
	return 0;
}
