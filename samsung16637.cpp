#include <iostream>
#include <algorithm>
#include <string>
#define MIN_NUMBER -987654321
 
using namespace std;

int n;
int ans = MIN_NUMBER;
string str;

int cal(int pa, int pb , char pc){

	int result = pa;

	if( pc == '*')
		result *= pb;
	else if(pc == '-')
		result -= pb;
	else 
		result += pb;

	return result; 	
}

void solution(int pi,int pm){
	
	char calStatus;
	
	if( pi >= n){
		ans = max(ans,pm);
		return ; 
	}
	
	if( !pi )
		calStatus = '+';
	else
		calStatus = str[pi-1];
	
	if( pi + 2 < n){
		int mid = cal(str[pi]-'0' , str[pi+2]-'0',str[pi+1]);
		solution( pi + 4 , cal(pm,mid,calStatus));	
	}
		
	solution( pi + 2 , cal(pm , str[pi]-'0',calStatus));
	
	return ;
}

int main(){
	
	cin >> n >> str;
	
	solution(0,0);
	
	cout << ans ; 
	
	return 0;
}
