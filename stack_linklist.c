#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

//Defining a node structure with two members val and next
struct node{
int val;
struct node *next;
};
struct node *head;


//function to push element in stack
void push(){
	int val;
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("Not able to push in stack\n");
	}
	else{
		printf("Enter the value\n");
		scanf("%d",&val);
		if(head==NULL){
			ptr->val=val;
			ptr->next=NULL;
			head=ptr;
		}
		else{
			ptr->val=val;
			ptr->next=head;
			head=ptr;
		}
	}
}

//function to remove element from stack
void pop(){
	int item;
	struct node *ptr;
	//If empty,display underflow and terminate
	if(head==NULL){
		printf("Underflow\n");
	}
	//else then define ptr and set it to top
	else{
		item=head->val;
		ptr=head;
		head=head->next;
		free(ptr);
		printf("Item popped:%d\n",item);
	}
}

//funtion to display elemnt from stack
void display(){
	struct node *ptr;
	ptr=head;
	//If empty,then display stack is empty.
	if(ptr==NULL){
		printf("Stack empty\n");
	}

	//If not empty,then define a node pointer ptr and initialize it with top
	else{
		printf("Printing stack elements\n");
		while(ptr!=NULL){
			printf("%d\t",ptr->val);
			printf("\n");
			ptr=ptr->next;
		}
	}
}



void main(){
int choice;

	while(1){
	printf("Select the operation\n");
	printf("1.PUSH\n2.POP\n3.Display\n4.Exit\n");    //Option to select the operation
	printf("Enter the choice:\n");                   
	scanf("%d",&choice);                             //to input the choice
	switch(choice){
		case 1:push();break;
		case 2:pop();break;
		case 3:display();break;
		case 4:printf("Exited\n");
		default:printf("Invalid choice!!!!\n");
 		}
	}
}
