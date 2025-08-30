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
  	printf("The contents of list(left to right):\n");
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
	printf("X\n");
  }
  
   // Node Count:
   
   int count_node()
   {
   	int count=1;
   	node *temp;
   	temp=start;
   	while (temp->next != start)
   	{
   		count++;
   		temp=temp->next;
	}
	   return count;
   }

  // Insertion at the Beginning:
  
  void cll_insert_beg()
  {
  	node *newnode, *temp;
  	newnode=getnode();
  	if(start==NULL)
  	{
  		start=newnode;
  		newnode->next=start;
  		printf("Node Inserted....\n");
	  }
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		newnode->next=start;
		start=newnode;
		temp->next=start;
		printf("Node Inserted....\n");
	}
  }
  
  // Insertion at the End:
  
  void cll_insert_end()
  {
  	node *newnode,*temp;
  	newnode=getnode();
  	if(start==NULL)
  	{
  		start=newnode;
  		newnode->next=start;
  		printf("Node Inserted....\n");
	  }
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=start;
		printf("Node Inserted....\n");
	}
  }
  
  // Insertion at Intermediate Position:
   
   void cll_insert_pos()
   {
   	node *newnode,*temp;
   	int pos,nodectr,i;
   	newnode=getnode();
   	printf("Enter the position: ");
   	scanf("%d",&pos);
   	nodectr=count_node();
   	if (pos>(nodectr+1))
   	{
   		printf("Position is out of range.");
   		return;
	   }
	else if (pos>1 && pos<=nodectr)
	{
		temp=start;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
		printf("Node Inserted...\n");
	}
	else
	 {
	 	printf("%d is not a intermediate position.",pos);
	 }
   }
  
  int main()
  {
   int num,ch,n;
   while(1)
   {
   	printf("\n1. Create the list.\t");
   	printf("2. Insert at Beginning.\n");
   	printf("3. Insert at End.\t");
   	printf("4. Insert at Intermediate Position.\n");
   	printf("5. Display.\t");
   	printf("6. Exit.\n");
   printf("\nEnter your choice:");
   scanf("%d",&ch);
   switch(ch)
   {
   	  	case 1:
   	  	 printf("Enter of no. of Elements want to Insert:");
         scanf("%d",&num);
         create_list(num);
         break;
        case 2:
        	cll_insert_beg();
        	break;
        case 3:
        	cll_insert_end();
        	break;
        case 4:
        	cll_insert_pos();
        	break;
        case 5:
        	display();
        	break;
        case 6:
        	exit(0);
        	break;
        default:
        	printf("\n Wrong Choice......");	
       }
    }
       return 0; 	
     }                  // Souvik Paul.......
  
