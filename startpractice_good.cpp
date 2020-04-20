#include <stdio.h>

int main(){
	
	int n;
	scanf("%d",&n);
	int area = n*n;
	
	for(int i = 1 ; i <= area ; ++i){
		
		int t = i / n;
		
		if( 1 <= t && t < n-1 ){
			if( t + 1 == i % n){
				printf("*");
				continue;
			}
			if(i % n != 1 && i % n != 0){
				printf("+");
				continue;
			}
		}
		
		printf("*");
		 
		if( i % n == 0)
			printf("\n");
			
	}
	
	return 0;
}
