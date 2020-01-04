#include <stdio.h>
#include <string.h>
#define max 2

int queue[max]; 
int front = -1, rear = -1;

int isFull(){
    if (rear == max-1) //check whether the last value of the queue is equal to the maximum number -1 where it indicates a full queue
	{
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(){
	if (front == -1) //check whether the firt value of the queue is equal to -1 where it indicates an empty queue
	{
        return 1;
    }
    else{
        return 0;
    }
}

int enqueue() {
	int num;
	if ((front == 0 && isFull()) || front == rear + 1) {
		printf("Queue is Full \n");
		return;
	}
	if (isEmpty()){
		front = rear = 0;
	}
	else {
		if (isFull()){
			rear = 0;
		}
		else {
			rear++;
		}
	}
	printf("Inset the element in queue : ");
    scanf("%d", &num);
	queue[rear]=num;
}

int dequeue() {
	if(isEmpty()){
		printf("Queue is Empty \n");
		return;
	}
	if (front == rear){
		front = rear = -1;
	}
	else {
		if(front==max-1){
			front=0;
		}
		else {
			front++;
		}
	}
}

int display(){
	int frontPos = front, rearPos = rear;
	if (isEmpty()){
		printf("Queue is Empty \n");
		return;
	}
	if(frontPos <= rearPos){
		while (frontPos <= rearPos){
			printf("%d ",queue[frontPos]);
			frontPos++;
		}
	}
	else{
		while(frontPos <= max -1){
			printf("%d ",queue[frontPos]);
			frontPos++;
		}
		frontPos=0;
		while(frontPos <= rearPos){
			printf("%d ",queue[frontPos]);
			frontPos++;
		}
	}
	printf("\n");
}

int main (){
	int n;  
    while (1){//creating a loop until user wants to end the program
    	printf("1. Enqueue \n");
    	printf("2. Dequeue \n");
    	printf("3. Display \n");
    	printf("4. Peek \n");
    	printf("0. Exit \n");
    	
    	printf("Enter your choice : ");
    	scanf("%d",&n);
    	
    	switch (n){//calling fumctions using switch case
    		case 1:enqueue();
    				break;
    		case 2:dequeue();
    				break;
    		case 3:display();
    				break;
    		//case 4:peek();
    		//		break;
    		case 0:exit(0);
		}
	}
	return 0;  
}


