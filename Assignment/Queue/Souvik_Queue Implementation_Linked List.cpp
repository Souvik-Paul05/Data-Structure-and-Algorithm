#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

  struct linkedlist_Queue
  {
 	 int data;
 	 struct linkedlist_Queue *next;
  };
  typedef struct linkedlist_Queue queuenode;
  queuenode *front = NULL;
  queuenode *rear = NULL;
  
  // Insert an Element into the Queue using Linked List:
  
  void enqueue(int item)
  {
  	queuenode *node;
  	node=(queuenode*)malloc(sizeof(queuenode));
  	node->data=item;
  	node->next=NULL;
  	if(rear==NULL)
  	{
  		front=node;
  		rear=node;
	  }
	else
	{
		rear->next=node;
		rear=rear->next;
	}
	printf("Data is pushed into the Queue...\n");
  }
  
  // Delete an Element from the Queue using Linked List:
  
  void dequeue()
  {
  	int item;
  	queuenode *temp;
  	temp=front;
  	if(front==NULL)
  	{
  		rear=NULL;
  		printf("Queue is Underflow..\n");
	  }
	else
	{
		item=temp->data;	
		printf("The item is Deleted from the Queue.\n");
		printf("The Deleted item is %d\n",item);
		front=temp->next;
		if(front==NULL)
		{
			rear=NULL;
		}
		free(temp);
	}
  }
  
  // Display the Elements of the Queue using Linked list:
  
  void display()
  {
  	queuenode *temp;
  	if(front==NULL)
  	{
  		printf("Queue is Empty..\n");
  		return;
	  }
	else
	{
		printf("Elements in Queue:\n");
		temp=front;
		while(temp != NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
  }
  
   // main function:
  
   int main()
  {
 	int ch,data;
 	while(1)
 	{
 		printf("\n1. INSERT\n");
 		printf("2. DELETE\n");
 		printf("3. DISPLAY\t");
 		printf("4. EXIT\n");
 	   printf("\nEnter Your Choice:");
 	   scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data:");
				scanf("%d",&data);
				enqueue(data);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nWrong Choice....");
		}
	}
	return 0;
 }                          // Souvik Paul.....
