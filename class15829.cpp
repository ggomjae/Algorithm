#include <iostream>
#include <string>
using namespace std;

unsigned long long function(int t,int k){
	
	unsigned long long a = 1;
	
	for(int i = 0 ; i < t ; ++i){
		a *= 31;
	}
	
	return a*k;
}

int main(){
	
	int n;
	string str;
	unsigned long long result = 0;
	cin >> n >> str;
	
	for(int i = 0 ; i < str.length() ; ++i){
		result += function(i,str[i]-'a'+1);
	}
	
	cout << result << '\n';
	
	return 0;
}
