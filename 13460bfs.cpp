#include <iostream>
#include <string>

using namespace std;

string str[10];
char arr[10][10];
int check[10][10];
int dx[4] = {0 , 0 , -1 , 1};
int dy[4] = {-1, 1 , 0 , 0 };

int n , m;
int a,b,c,d;
int x,y;

int main(){
		
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> str[i];
	}
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < str[i].length(); ++j){
			arr[j][i] = str[i][j];
			
			if(arr[j][i] == 'R'){
				a = j ;
				b = i ;
			}
			
			if(arr[j][i] == 'B'){
				c = j ;
				d = i ;
			}	
			
			if(arr[j][i] == 'O'){
				x = j ;
				y = i ;
			}
			
			if(arr[j][i] == '#'){
				check[j][i] = 1;
			}
		}
	}
	
	
	
		
	return 0;
}
