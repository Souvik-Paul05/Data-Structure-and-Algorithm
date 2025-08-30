#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 struct clinklist
 {
 	int data;
 	struct clinklist *next;
 };
 typedef struct clinklist node;
 node *start=NULL;
 
 node *getnode()
 {
 	node *newnode;
 	newnode=(node*) malloc(sizeof(node));
 	printf("Enter Data:");
 	scanf("%d",&newnode->data);
 	newnode->next=NULL;
 	return newnode;
 }
 
  // Creation of Circular Linked List:
 
 void create_list(int n)
 {
 	int i;
 	node *newnode,*temp;
 	for(i=0;i<n;i++)
 	{
 		newnode=getnode();
 		if(start==NULL)
 		{
 			start=newnode;
		 }
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
		}
	 }
	 newnode->next=start;
 }
 
  // Display of Circular Linked List:
  
  void display()
  {
  	node *temp;
  	temp=start;
  	printf("\nThe contents of list(left to right):\n");
  	if(start==NULL)
  	{
  		printf("Empty List..");
	  }
	else
	{
		do
		{
			printf("%d->",temp->data);
			temp=temp->next;
		} while(temp!= start);
	}
	printf("X");
  }
  
  // Main Function:
  
  int main()
  {
  	int num;
  	printf("Enter the no. of Elements want to Insert:");
  	scanf("%d",&num);
  	create_list(num);
  	display();
  	return 0;
  }
