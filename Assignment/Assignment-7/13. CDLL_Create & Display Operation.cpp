#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 struct cdlinklist
 {
 	struct cdlinklist *left;
 	int data;
 	struct cdlinklist *right;
 };
 typedef struct cdlinklist node;
 node *start=NULL;
 
 node *getnode()
 {
 	node *newnode;
 	newnode=(node*) malloc(sizeof(node));
 	printf("Enter Data:");
 	scanf("%d",&newnode->data);
 	newnode->left=NULL;
 	newnode->right=NULL;
 	return newnode;
 }
 
  // Creation of Circular Double Linked List:
  
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
 			newnode->left=start;
 			newnode->right=start;
		 }
		else
		{
			newnode->left=start->left;
			newnode->right=start;
			start->left->right=newnode;
			start->left=newnode;
		}
	 }
 }
 
 // Display of Circular Double Linked List:
 
  void cdll_display_left_to_right()
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
			temp=temp->right;
		} while(temp != start);	
	}
	printf("X\n");
  }
 
 void cdll_display_right_to_left()
  {
  	node *temp;
  	temp=start;
  	printf("\nThe contents of list(right to left):\n");
  	if(start==NULL)
  	{
  		printf("Empty List..");
	  }
	else
	{
		do
		{
			temp=temp->left;
		    printf("%d->",temp->data);
		} while(temp != start);	
	}
	printf("X\n");
  }
  
  // Main Function:
  
  int main()
  {
  	int num;
  	printf("Enter the no. of Elements want to Insert:");
  	scanf("%d",&num);
  	create_list(num);
  	cdll_display_left_to_right();
  	cdll_display_right_to_left();
  	return 0;
  }
