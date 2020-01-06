#include<stdio.h>
#define MAX 20
void push();
void display();
void reverse();
int queue[MAX];
int rear=-1,front=-1;
 
int main(){
	int n;
	while(1){
		printf("\n1.push\n2.Normal queue\n3.Reverse quoue\n4.Exit\n");
		printf("Select one chooice\n");
		scanf("%d",&n);
		
		switch(n){
			case 1:push();break;
			case 2:display();break;
			case 3:reverse();break;
			case 4:exit(1);break;
			default:printf("Wrong choice\n");
		}
	}
}

void push(){
	int x;
	if(rear==MAX-1){
		printf("quoue is overflow\n");
	}
	else{
		if(front==-1)
			front=0;
			printf("Enter the numbers:");
			scanf("%d",&x);
			rear=rear+1;
			queue[rear]=x;
	}
}

void display(){
	int i;
	if(front==-1 || front>rear){
		printf("Quoue is underflow\n");
	}
	else{
		printf("real quoue:");
		for(i=front;i<=rear;i++){
			printf("%d\t",queue[i]);
		}
	}
}

void reverse(){
		int i;
	if(front==-1 || front>rear){
		printf("Quoue is underflow\n");
	}
	else{
		printf("rear quoue:");
		for(i=rear;i>=0;i--){
			printf("%d\t",queue[i]);
		}
	}
}
