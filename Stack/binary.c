#include <stdio.h>
#define max 10

int isFull ();
int main (){
	int stack[max];
	int top = -1;
	int num, r, i, n;
	
	printf("Enter num : ");
	scanf("%d", &num);
	
	n=num; 
	
	while (n!=0){
		r=n%2;
		n=n/2;
		top++;
		stack[top]=r;				
	}
	
	for(i=top; i>=0; i--){
		printf("%d",stack[i]);
	}
}


