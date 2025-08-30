#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 struct dlinklist
 {
 	struct dlinklist *left;
 	int data;
 	struct dlinklist *right;
 };
 typedef struct dlinklist node;
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
 
  // Creation of Double Linked List:
  
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
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			temp->right=newnode;
			newnode->left=temp;
		}
	 }
 }
 
 // Display of Double Linked list:
 
 void display_right_to_left()
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
		while(temp->right != NULL)
		{
			temp=temp->right;
		}
	}
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp=temp->left;
	}
	printf("X\n");
  }
  
  void display_left_to_right()
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
		while(temp != NULL)
		{
			printf("%d->",temp->data);
			temp=temp->right;
		}
	}
	printf("X\n");
}
  
   // Main Function.
  
  int main()
  {
  	int num;
  	printf("Enter the no. of Elements want to Insert:");
  	scanf("%d",&num);
  	create_list(num);
  	display_left_to_right();
  	display_right_to_left();
  	return 0;
  }
