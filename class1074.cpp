#include <iostream>
#define MAX 17000
using namespace std;

int n, x, y;
int cnt ;

int powFunction(int b){
	
	int v = 1;
	
	for(int i = 0 ; i < b ; ++i){
		v *= 2;
	}
	
	return v;
}

void function(int a , int b , int p){

	if( x < a || y < b ){
		cnt += p*p;
		return ;
	}

	if( p == 2 ){
		for(int i = a; i < a + 2 ; ++i){
			for(int j = b ; j < b+2; ++j){
				
				if( i == x && j == y){
					cout << cnt <<'\n';
					return ;
				}
				cnt++;
			}
		}
		return ;
	}
	
	function(a,b,p/2);
	function(a,b+p/2,p/2);
	function(a+p/2,b,p/2);
	function(a+p/2,b+p/2,p/2);
	
	return ;
}

int main(){
	
	
	cin >> n >> x >> y;
	
	int c = powFunction(n);
	
	function(0,0,c);
	
	return 0;
}
