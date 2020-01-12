#include <stdio.h>
#include <string.h>

struct node{
        int data;
        struct node* link;
};

struct node* root = NULL;

void addLast (int data){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    //printf("Enter a Number : ");
    //scanf("%d", &temp->data);
    temp->data = data;
    temp->link = NULL;
    if(root == NULL){
        root=temp;
    }
    else {
        struct node* ptr;
        ptr = root;
        while (ptr->link !=NULL){
            ptr=ptr->link;
        }
        ptr->link = temp;
    }
}

void display(struct node* n){
    while (n != NULL){
        printf(" %d ",n->data);
        n = n->link;
    }
}
void addFront(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    //printf("Enter a Number : ");
    //scanf("%d", &newNode->data);
    newNode->data = data;
    newNode->link = root;
    root = newNode;
}

void addAfter(struct node* n, int data, int preData){
	//int preData;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	/*
	printf("Enter the Number : ");
	scanf("%d",&newNode->data);
	printf("Enter the Number to add after : ");
	scanf("%d",&preData);
	*/
	newNode->data = data;
	while(n->data != preData){
		n = n->link;
	}
	newNode->link = n->link;
	n->link = newNode;
		
}
//still coding
/*void addBefore(struct node* n, int data, int postData){
	struct node* preptr= n;
	n = n->link;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	
}*/

int main (){
    addLast(3);
    addFront(1);
    addAfter(root,2,1);
    display(root);    
}
