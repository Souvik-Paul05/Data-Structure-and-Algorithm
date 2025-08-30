#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 struct slinklist
 {
 	int data;
 	struct slinklist *next;
 };
 typedef struct slinklist node;
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
 
 // Creation of Single Linked List:
 
  void create_list(int n)
 {
 	int i;
 	node *newnode, *temp;
 	for(i=0;i<n;i++)
 	{
 		newnode=getnode();
 		if (start==NULL)
 		{
 			start=newnode;
		 }
		else
		{
			temp=start;
			while(temp->next != NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
		}
	 }
 }
 
 // display of single linked list:
 
 void traverse()
  {
  	node *temp;
  	temp=start;
  	printf("\nThe contents of the list from left to right: \n");
  	if(start==NULL)
  	{
  		printf("\n Empty List.");
	  }
	else
	{
		while(temp != NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
      }
      printf("X");
  }
  
  // Main Function:
  
  int main()
  {
  	int num;
  	printf("Enter the no. of elements wants to insert: ");
  	scanf("%d",&num);
  	create_list(num);
  	traverse();
  	return 0;
  }
