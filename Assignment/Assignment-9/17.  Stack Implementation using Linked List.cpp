#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

  struct linkedlist_stack
  {
  	int data;
  	struct linkedlist_stack *next;
  };
  typedef struct linkedlist_stack stacknode;
  stacknode *top = NULL;
  
  // Push Operation of Stack using Linked List:
  
  void push(int item)
  {
  	stacknode *node;
  	node=(stacknode*)malloc(sizeof(stacknode));
  	node->data=item;
  	node->next=top;
  	top=node;
  	printf("Data is pushed into the stack...\n");
  }
  
  // Pop Operation of Stack using Linked List:
  
  void pop()
  {
  	int item;
  	stacknode *temp;
  	temp=top;
  	if(top==NULL)
  	{
  		printf("Stack is Empty...\n");
	  }
	else
	{
		item=temp->data;
		printf("Data is popped from the stack.\n");
		printf("The Popped item is %d\n",item);
		top=temp->next;
		free(temp);
	}
  }
  
  // Display Operation of Stack using Linked List:
  
  void display()
  {
  	stacknode *temp;
  	temp=top;
  	if(temp==NULL)
  	{
  		printf("Stack is Empty...\n");
	  }
	else
	{
		printf("Elements in Stack:\n");
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
  }
  
  // Main Function:
  
  int main()
 {
 	int ch,data;
 	while(1)
 	{
 		printf("\n1. PUSH\n");
 		printf("2. POP\n");
 		printf("3. DISPLAY\t");
 		printf("4. EXIT\n");
 	   printf("\nEnter Your Choice:");
 	   scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter Data:");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				pop();
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
