#include <stdio.h>
#include <string.h>
#define max 10 //define maximum size as 10

int queue[max]; //initialize the queue
int front = -1; rear = -1; // use to variables for the front and rear of the queue

/*Function to check whether the Queue is Full or not
This returns the vales 1 & 0 if the queue is full or not respectively*/
int isFull(){
    if (rear == max-1) //check whether the last value of the queue is equal to the maximum number -1 where it indicates a full queue
	{
        return 1;
    }
    else {
        return 0;
    }
}

/*Function to check whether the Queue is Empty or not
This returns the vales 1 & 0 if the queue is empty or not respectively*/
int isEmpty (){
    if (rear == -1) //check whether the firt value of the queue is equal to -1 where it indicates an empty queue
	{
        return 1;
    }
    else{
        return 0;
    }
}

/*Function to insert elements into the queue*/
int enqueue (){
    int num;
    if (isFull()){
        printf("Queue is Full \n");
    }
    else {
        if (front == -1){ //if the queue is empty make the front as the first element
            front = 0;
        }
        printf("Inset the element in queue : ");
        scanf("%d", &num);
        rear = rear + 1;
        queue[rear]=num;
    }
}

/*Function to delete elements from the queue*/
int dequeue () {
    if (isEmpty() || front>rear){
        printf("Queue is Empty \n");
    }
    else{
        return queue[front++]; //increase the front and returns the stack with the next front value
    }
} 

/*Function to print the queue*/
int display (){
	int i;
	if(isEmpty()){
		printf("Queue is empty \n");
	}
	else {
		for (i=front; i<=rear; i++){ //printing the queue from front to rear
        printf("%d ", queue[i]);
    	}
    	 printf("\n");
	}   
}

int peek (){
	if(isEmpty()){
		printf("Queue is empty \n");
	}
	else {
		printf("Front is : %d\n",queue[front]); //display the front value of queueS
	}
}
/*Main Function*/
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
    		case 4:peek();
    				break;
    		case 0:exit(0);
		}
	}
	return 0;  
}
