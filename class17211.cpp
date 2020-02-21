#include <iostream>
#define N 100

using namespace std;

double ans[N+1][2];

int main(){
	
	int n,k;
	cin >> n >> k;
	
	double uud,udd,ddd,dud;
	cin >> uud >> udd >> dud >> ddd;
	
	ans[1][0] = (k == 0)? uud : dud;
	ans[1][1] = (k == 0)? udd : ddd;
	//1 싫은날 0 좋은날 
	for(int i = 2 ; i <= n ; ++i){
		ans[i][0] = ans[i-1][0]*uud + ans[i-1][1]*dud;
		ans[i][1] = ans[i-1][0]*udd + ans[i-1][1]*ddd;
	}
	
	int result = ans[n][0] *10000;
	int result2 = ans[n][1] *10000;
	
	if(result % 10 >= 5){
		result /= 10;
		result += 1;
	}else{
		result /= 10;
	}
	
	if(result2 % 10 >= 5){
		result2 /= 10;
		result2 += 1;
	}else{
		result2 /= 10;
	}
		
	cout << result  << '\n';
	cout << result2  << '\n';
	
	return 0;
}
