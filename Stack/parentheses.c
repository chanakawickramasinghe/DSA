#include <stdio.h>
#include <string.h>

#define max 12

char stack[max];
int top = -1;

/*Function to check whether the Stack is Full or not
This returns the vales 1 & 0 if the stack is full or not respectively*/
int isFull (){
	if (top == max - 1){
        return 1;
    }
    else {
        return 0;
    }
}

/*Function to insert elements into the stack*/
int push (char num){
    if (isFull()){
        printf("Stack Overflow \n");
    }
    else {
        top++;
        stack[top]= num;
    }
}

/*Function to check whether the Stack is Empty or not
This returns the vales 1 & 0 if the stack is empty or not respectively*/
int isEmpty (){
	if (top == -1){
		return 1;
	}
	else {
		return 0;
	}
}

/*Function to delete elements from the stack*/
int pop (){
	if( isEmpty()){
		printf("Stack Underflow \n");
	}
	else{
		return stack[top--];
	}	
}

/*Function to check whether the parantheses are balanced*/
int paraBal(char name[]){
	int i; 
	char loopValue, topValue; 
	
	for (i=0; i < strlen(name); i++){
		loopValue = name[i]; //set the current loopValue as i
		
		/*if the current loopValue is an opening bracket push it to the stack*/
		if (loopValue == '(' || loopValue == '{' || loopValue == '[') {
            push(name[i]);
        }
        
       	/*if the current loopValue is an closing bracket push*/
        if (loopValue == ')' || loopValue == '}' || loopValue == ']') {
        	//first check whether the stack is empty
        	if (isEmpty()){
        		return 0; //if empty return 0, which means the paranthesis are not balanced
			}
			
			//else, take the last value of the stack to topValue
			topValue = pop ();
			
			/*check whether the topValue match with the loopValue, if not return 0 which 
			means the paranthesis are not balanced*/
			if (topValue == '(' && loopValue != ')' || topValue == '{' && loopValue != '}' || topValue == '[' && loopValue != ']'){
				return 0;
			}
		}
	}
	/*finally, check whether the stack is empty, if not it will return 0,
	which means the paranthesis are not balanced*/
	return isEmpty ();
}

int main () {
	char name[10];
	printf("Enter the Expression : ");
	//scanf("%[^\n]s",name); 
	//we can use this method also
	gets(name);
	//printf("%s",name);
	
	if (paraBal(name)){
		printf("Balanced \n");
	}
	else {
		printf("Not Balanced \n");
	}
	
	return 0;
}
