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
    temp->link=NULL;
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
    while(n->data != preData && n->link != NULL){
        n = n->link;
    }
    newNode->link = n->link;
    n->link = newNode;        
}

void addBefore(struct node* n, int data, int postData){
    struct node* ptr= root;
    n = ptr->link;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    while(n->data != postData){
        n = n->link;
        ptr = ptr->link;
    }
    ptr->link = newNode;
    newNode->link = n;    
}

void delFront(){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = root;
	root = root->link;
	free(temp);
}

void delLast(){
	struct node* preptr = root;
	struct node* ptr = root->link;
	while (ptr->link != NULL){
		preptr=ptr;
		ptr = ptr->link;
	}
	preptr->link=NULL;
	free(ptr);
}

int main () {
    addLast(4);
    addFront(1);
    addAfter(root,2,1);
    addBefore(root,3,4);
    display(root);
    printf("\n");
    delFront();
    display(root);
    printf("\n");
    delLast();
    display(root);
}
