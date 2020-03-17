#include <iostream>
#include <algorithm>
using namespace std;

int table[33][6] = { 
	{0,1,2,3,4,5},
	{2,2,3,4,5,9},  
	{4,3,4,5,9,10}, 
	{6,4,5,9,10,11},  
	{8,5,9,10,11,12},
	{10,6,7,8,20,29}, 
	{13,7,8,20,29,30},  
	{16,8,20,29,30,31},  
	{19,20,29,30,31,32},  
	{12,10,11,12,13,14},  
	{14,11,12,13,14,15},  
	{16,12,13,14,15,16}, 
	{18,13,14,15,16,17}, 
	{20,18,19,20,29,30},  
	{22,15,16,17,24,25},  
	{24,16,17,24,25,26},  
	{26,17,24,25,26,27},  
	{28,24,25,26,27,28},  
	{22,19,20,29,30,31},  
	{24,20,29,30,31,32},  
	{25,29,30,31,32,32}, 
	{26,20,29,30,31,32},  
	{27,21,20,29,30,31},  
	{28,22,21,20,29,30},  
	{30,23,22,21,20,29},  
	{32,26,27,28,31,32},  
	{34,27,28,31,32,32},  
	{36,28,31,32,32,32},  
	{38,31,32,32,32,32},  
	{30,30,31,32,32,32},  
	{35,31,32,32,32,32},  
	{40,32,32,32,32,32}, 
	{0,32,32,32,32,32} 
};

int turnNumber[11];
int ans ,result;
int position[4];
int panNumber[35];

void init(){
	
	result = 0 ;
	
	for(int i = 0 ; i < 4 ; ++i)	
		position[i] = 0;
	for(int i = 0 ; i < 35 ; ++i)
		panNumber[i] = 0;
	
	return ;
}

void solution(int px){
	
	init();
	
	for(int i = 0 ; i < 10 ; ++i){
		
		int nx = px >> (i*2) & 3;
		int m = turnNumber[i];
		int &currentPosition = position[nx];
		int nextPosition = table[currentPosition][m];
		int score = table[nextPosition][0];
		
		if(panNumber[nextPosition] > 0 && nextPosition != 32)
			return ;	
		
		
		result += score;
		panNumber[nextPosition]++;
		panNumber[currentPosition]--;
		currentPosition = nextPosition;	
	}
	
	ans = max(ans,result);
}

int main(){
	
	for(int i = 0 ; i < 10 ; ++i)
		cin >> turnNumber[i];
	
	for(int i = 0 ; i < 1 << 20 ; ++i)
		solution(i);
	
	cout << ans << '\n';
	
	return 0;
}
