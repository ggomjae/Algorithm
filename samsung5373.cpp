#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 3

using namespace std;

int n,t;
string color = "wyrogb";
string str;

char arr[6][3][3]; 
char cpyArr[3][3];

void U(int px){

	char temp[3];
	
	for (int i = 0; i < 3; i++)
		temp[i] = arr[4][px][i];
	for (int i = 0; i < 3; i++)
		arr[4][px][i] = arr[2][px][i];
	for (int i = 0; i < 3; i++)
		arr[2][px][i] = arr[5][px][i];
	for (int i = 0; i < 3; i++)
		arr[5][px][i] = arr[3][px][i];
	for (int i = 0; i < 3; i++)
		arr[3][px][i] = temp[i];
		
	return ;
}

void D(int px){

	char temp[3];

	for (int i = 0; i < 3; i++)
		temp[i] = arr[4][px][i];
	for (int i = 0; i < 3; i++)
		arr[4][px][i] = arr[3][px][i];
	for (int i = 0; i < 3; i++)
		arr[3][px][i] = arr[5][px][i];
	for (int i = 0; i < 3; i++)
		arr[5][px][i] = arr[2][px][i];
	for (int i = 0; i < 3; i++)
		arr[2][px][i] = temp[i];
		
	return ;
}


void F(int px){
	
	char temp[3];
	int idx = (px == 0 ? 2 : 0);
	
	for (int i = 0; i < 3; i++)
		temp[i] = arr[0][px][i];
	for (int i = 0; i < 3; i++)
		arr[0][px][i] = arr[4][2 - i][px];
	for (int i = 0; i < 3; i++)
		arr[4][i][px] = arr[1][idx][i];
	for (int i = 0;i < 3; i++)
		arr[1][idx][i] = arr[5][2 - i][idx];
	for (int i = 0; i < 3; i++)
		arr[5][i][idx] = temp[i];
		
	return ;
}

void B(int px){

	char temp[3];
	int idx = (px == 0) ? 2 : 0;
	
	for (int i = 0; i < 3; i++)
		temp[i] = arr[0][px][i];
	for (int i = 0; i < 3; i++)
		arr[0][px][i] = arr[5][i][idx];
	for (int i = 0; i < 3; i++)
		arr[5][i][idx] = arr[1][idx][2 - i];
	for (int i = 0; i < 3; i++)
		arr[1][idx][i] = arr[4][i][px];
	for (int i = 0; i < 3; i++)
		arr[4][i][px] = temp[2 - i];
		
	return ;
}

void L(int px){

	char temp[3];
	int idx = (px == 0 ? 2 : 0);

	for (int i = 0; i < 3; i++)
		temp[i] = arr[0][i][px];
	for (int i = 0; i < 3; i++)
		arr[0][i][px] = arr[3][2 - i][idx];
	for (int i = 0; i < 3; i++)
		arr[3][i][idx] = arr[1][2 - i][px];
	for (int i = 0; i < 3; i++)
		arr[1][i][px] = arr[2][i][px];
	for (int i = 0; i < 3; i++)
		arr[2][i][px] = temp[i];
		
	return ;
}

void R(int px){
	
	char temp[3];
	int idx = (px == 0 ? 2 : 0);

	for (int i = 0; i < 3; i++)
		temp[i] = arr[0][i][px];
	for (int i = 0; i < 3; i++)
		arr[0][i][px] = arr[2][i][px];
	for (int i = 0; i < 3; i++)
		arr[2][i][px] = arr[1][i][px];
	for (int i = 0; i < 3; i++)
		arr[1][i][px] = arr[3][2 - i][idx];
	for (int i = 0; i < 3; i++)
		arr[3][i][idx] = temp[2 - i];
		
	return ;
}

void rightTurn(int px){
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cpyArr[i][j] = arr[px][i][j];

	
	for (int i = 0; i < 3; i++)
		arr[px][0][i] = cpyArr[2 - i][0];
	
	arr[px][1][0] = cpyArr[2][1];
	arr[px][1][2] = cpyArr[0][1];

	for (int i = 0; i < 3; i++)
		arr[px][2][i] = cpyArr[2 - i][2];
		
	return ;
}

void leftTurn(int px){
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cpyArr[i][j] = arr[px][i][j];

	for (int i = 0; i < 3; i++)
		arr[px][0][i] = cpyArr[i][2];

	arr[px][1][0] = cpyArr[0][1];
	arr[px][1][2] = cpyArr[2][1];

	for (int i = 0; i < 3; i++)
		arr[px][2][i] = cpyArr[i][0];
		
	return ;
}

int main(void){

	cin >> t;

	while(t--){
		
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					arr[i][j][k] = color[i];
		
		cin >> n;
		
		for (int i = 0; i < n; i++){
			
			cin >> str;
			
			if(str[0] == 'U'){
				if(str[1] == '+'){
					rightTurn(0);
					U(0);
				}else{
					leftTurn(0);
					D(0);
				}
			}else if(str[0] == 'D'){
				if(str[1] == '+'){
					rightTurn(1);
					D(2);
				}else{
					leftTurn(1);
					U(2);
				}
			}else if(str[0] == 'F'){
				if(str[1] == '+'){
					rightTurn(2);
					F(2);
				}else{
					leftTurn(2);
					B(2);
				}
			}else if(str[0] == 'B'){
				if(str[1] == '+'){
					rightTurn(3);
					B(0);
				}else{
					leftTurn(3);
					F(0);
				}
			}else if(str[0] == 'L'){
				if(str[1] == '+'){
					rightTurn(4);
					L(0);
				}else{
					leftTurn(4);
					R(0);
				}
			}else{
				if(str[1] == '+'){
					rightTurn(5);
					R(2);
				}else{
					leftTurn(5);
					L(2);
				}
			}
		}

		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++)
				cout << arr[0][i][j];
			cout << '\n';
		}
	}
	
	return 0;
}
