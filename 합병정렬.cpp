#include <stdio.h>
#include <stdlib.h>

	
int a_size,b_size;
int a_cur,b_cur,c_cur;

int main() {

 	scanf("%d",&a_size);
	int* arr = (int*)malloc(sizeof(int)*a_size);
	 	
 	for(int i = 0; i < a_size; i++) 
	 	scanf("%d",&(*(arr+i)));
 		
	scanf("%d",&b_size);

 	int* brr = (int*)malloc(sizeof(int)*b_size);
 	int* crr = (int*)malloc(sizeof(int)*(a_size+b_size));
 	
 	
	for(int i = 0; i < b_size; i++) 
	 	scanf("%d",&(*(brr+i)));
 	
 	while(a_cur< a_size && b_cur< b_size) {
 		
 		if( *(arr + a_cur) <  *(brr + b_cur)) 
 			*(crr + c_cur++) = *(arr + a_cur++);
 		else
			*(crr + c_cur++) = *(brr + b_cur++);
	}
	
	while(a_cur < a_size) 
		*(crr + c_cur++) = *(arr + a_cur++);
	
	while(b_cur < b_size) 
		*(crr + c_cur++) = *(brr + b_cur++);
		
 	for(int i = 0; i < c_cur; i++) 	
	 	printf("%d ",crr[i]);
	
	free(arr);
	free(brr);
	free(crr);
	
	return 0;
}
