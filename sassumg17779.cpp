#include <iostream>
#include <algorithm>
#define ANSNUMBER 987654321
#define MAX 21

using namespace std;

int n,cnt;
int arr[MAX][MAX];
int cpyArr[MAX][MAX];
bool checkState[6];

void init(){
	
	for(int i = 1; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			cpyArr[i][j] = 0;
	
	for(int i = 1; i <= 5 ; ++i)
		checkState[i] = false;
		
	return ;
}

int ansFunction(){
	int ansArray[6] = { 0, 0, 0, 0 ,0, 0};
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1; j <= n ; ++j)
			ansArray[cpyArr[i][j]] += arr[i][j];
		
	}
	
	sort(ansArray,ansArray+6);
	
	return ansArray[5] - ansArray[1];
}

bool calculation(int px, int py , int pd1, int pd2){
	
	if( pd1 < 1 || pd2 < 1 || px < 0 || px + pd1 + pd2 > n || 1 > py - pd1 || py + pd2 > n )
		return false;	
	
	int k = pd1 + pd2 + 1;
	int _x = px;
	int _y = py;
	int amount,right,left;
	amount = left = right = 0;
	
	int left_turn =  1;
	int right_turn = 1;
	
	while(k--){
		for(int i = 0 ; i <= amount ; ++i)
			cpyArr[_x][_y+i] = 5;
		
		if(left  == pd1)
			left_turn *= -1;		
		
		if(right == pd2)
			right_turn *= -1;
			
		left += left_turn;
		right += right_turn;
		_x++;
		_y -= left_turn;
		amount = left + right;
	}
	
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1; j <= n ; ++j){
			
			if(cpyArr[i][j] == 5){
				checkState[cpyArr[i][j]] = true;
				continue;
			}
			
			if( 1 <= i && i < px + pd1 && 1 <= j && j <=py )
				cpyArr[i][j] = 1;
			else if( 1 <= i && i <= px + pd2 && py < j && j<= n)
				cpyArr[i][j] = 2;
			else if( px + pd1 <= i && i <= n && 1 <= j && j < py-pd1+pd2)
				cpyArr[i][j] = 3;
			else if( px+pd2 < i && i <= n && py -pd1 + pd2 <= j && j <= n)
				cpyArr[i][j] = 4;
			
			checkState[cpyArr[i][j]] = true;
		}
	}
	
	for(int i = 1 ; i <= 5 ; ++i){
		if(checkState[i] == false)
			return false;
		
	}
	
	return true;
}

int solution(int px,int py){
	
	int ans = ANSNUMBER;
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j =1 ; j <= n ; ++j){
			
			init();
	
			if(calculation(px,py,i,j))
				ans = min(ans ,ansFunction());
		}
	}
	
	return ans;
}


int main(){
	
	int ans = ANSNUMBER;
	cin >> n;
	
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			cin >> arr[i][j];	
	
	
	for(int i = 1; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			ans = min (ans,solution(i,j));	
		
	cout << ans << '\n';

	return 0;
}
