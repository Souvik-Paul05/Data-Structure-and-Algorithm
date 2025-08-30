#include<stdio.h>
#include<stdlib.h>
# define MAX 5

   int front=-1;
   int rear=-1;
   int queue[MAX];
   
  // Insert an Element into the Queue using Array:
  
  void enqueue()
  {
  	int data;
  	if(rear==(MAX-1))
  	{
  		printf("Queue is Overflow..\n");
  		return;
	  }
	else
	{
		printf("Enter Data:");
		scanf("%d",&data);
		if(front==-1)
		{
			front=0;
			rear=0;
		}
		else
		{
			rear=rear+1;
		}
		queue[rear]=data;
		printf("Data is Inserted into the stack...\n");
	}
  }
  
  // Delete an Element from the Queue using Linked List:
  
  void dequeue()
  {
  	int data;
  	if(front==-1)
  	{
  		printf("Queue is Underflow...\n");
  		return;
	  }
	else
	{
		data=queue[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=front+1;
		}
		printf("The item is Deleted from the Queue.\n");
		printf("The Deleted item is %d\n",data);
	}
  }
  
  // Display Operation of Queue usng Array:
  
  void display()
  {
  	int i;
  	if(front==-1)
  	{
  		printf("Queue is Empty..\n");
	  }
	else
	{
		printf("Elements in Queue:\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
  }
  
   // Main Function:
 
   int main()
   {
 	 int ch,i;
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
				enqueue();
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
 }                                     // Souvik Paul.....
