#include<stdio.h>
#include<stdlib.h>
# define MAX 5

 int top= -1;
 int stack[MAX];
 
 // Push Operation of Stack using Array:
 
 void push()
 {
 	int data;
 	if(top==MAX-1)
 	{
 		printf("Stack Overflow...\n");
 		return;
	 }
	else
	{
		printf("Enter Data:");
		scanf("%d",&data);
		top=top+1;
		stack[top]=data;
		printf("Data is pushed into the stack...\n");
	}
 }
 
 // Pop Operation of Stack using Array:
 
 void pop()
 {
 	if(top==-1)
 	{
 		printf("Stack Underflow....\n");
 		return;
	 }
	else
	{
		printf("The item is popped from the stack.\n");
		printf("The Popped item is %d\n",stack[top]);
		top=top-1;
	}
 }
 
 // Display Oparation of Stack using Array:
 
 void display()
 {
 	int i;
 	if(top==-1)
 	{
 		printf("Empty Stack...\n");
 		return;
	 }
	else
	{
		printf("Elements in stack:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
 }
 
 // Main Function:
 
 int main()
 {
 	int ch,i;
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
				push();
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
 }                                    // Souvik Paul....
