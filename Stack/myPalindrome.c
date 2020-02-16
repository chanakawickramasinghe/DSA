#include <stdio.h>
#include <string.h>
#define max 20

char stack[max];
int top = -1;

int isFull (){
	if (top == max - 1){
        return 1;
    }
    else {
        return 0;
    }
}

int push (char num){
    if (isFull()){
        printf("Stack Overflow \n");
    }
    else {
        top++;
        stack[top]= num;
    }
}

int isEmpty (){
	if (top == -1){
		return 1;
	}
	else {
		return 0;
	}
}

int pop (){
	
	if( isEmpty()){
		printf("Stack Underflow \n");
	}
	else{
		return stack[top--];
	}	
}

int palin (char name[]){
	int i;
	char loopValue, topValue;
	
	for (i=0; i<strlen(name); i++ ){
		push(name[i]);
	}
	
	for (i=0; i<strlen(name); i++){
		topValue = pop();
		loopValue = name[i];
		
		if (loopValue != topValue){
			return 0;
		}
	}
	return 1;
}

int main (){
	char name[12];
	printf("Enter char : ");
	scanf("%[^\n]s",name);
	
	if (palin(name)){
		printf("Palindrome \n");
	}
	else {
		printf("Not \n");
	}
	return 0;
}
