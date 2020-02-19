#include <iostream>

using namespace std;

int arr[10][10];

int main(){
	
	int mv = -1;
	int ansi,ansj;
	
	for(int i = 1 ; i <= 9 ; i++){
		for(int j = 1 ; j <= 9 ; ++j){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 1 ; i <= 9 ; ++i){
		for(int j = 1 ; j <= 9 ; ++j){
			if(arr[i][j] > mv){
				ansi = i;
				ansj = j;
				mv = arr[i][j];
			}
		}
	}
	
	cout << mv << '\n';
	cout << ansi << " " << ansj << '\n';
	
	return 0;
}
