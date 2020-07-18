#include <iostream>

using namespace std;

int main(){
	
	int a,b,c;
	cin >> a >> b >> c;
	
	int m;
	cin >> m;
	
	a += m/3600;
	m -= (m/3600)*3600;
	b += m/60;
	m -= (m/60)*60;
	c += m%60;
	
	if(c>= 60){
		b += c/60;
		c = c%60;
	}
	
	if(b>=60){
		a += b/60;
		b = b%60;
	}
	
	if(a>= 24){
		a = a%24;
	}
	
	cout << a << " " << b << " " << c;
	
	return 0;
}
