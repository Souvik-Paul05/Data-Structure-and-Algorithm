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
 
 // Display of Single Linked List:
 
 void traverse()
  {
  	node *temp;
  	temp=start;
  	printf("The contents of the list from left to right:\n");
  	if(start==NULL)
  	{
  		printf("Empty List.");
	  }
	else
	{
		while(temp != NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
      }
      printf("X\n");
  }
  
  // Node Count:
   
   int count_node()
   {
   	int count=1;
   	node *temp;
   	temp=start;
   	while (temp->next != NULL)
   	{
   		count++;
   		temp=temp->next;
	}
	   return count;
   }
   
   // Delete Node from the Beginning:
   
   void delete_at_beg()
   {
   	node *temp;
   	if(start==NULL)
   	{
   		printf("\nNo Nodes are exists.");
   		return;
	   }
	else
	{
		temp=start;
		start=start->next;
		free(temp);
		printf("Node Deleted.\n");
	}
   }
   
   // Deleting Node from the End:
   
   void delete_at_last()
   {
   	 node *temp,*prev;
   	 if(start==NULL)
   	 {
   	 	printf("\nEmpty List.");
   	 	return;
		}
	else
	{
		temp=start;
		prev=start;
		while(temp->next != NULL)
		{
			prev=temp;
			temp=temp->next;
		}
	  prev->next=NULL;
	  free(temp);
	  printf("Node Deleted.\n");
	}
   }
   
   // Deleting Node from the Intermediate:
   
   void delete_at_pos()
   {
   	int i,pos,nodectr;
   	node *temp,*prev;
   	if(start==NULL)
   	{
   		printf("\nEmpty list.");
   		return;
	   }
	else
	{
		printf("Enter position of node want to delete:");
		scanf("%d",&pos);
		nodectr=count_node();
		if(pos>nodectr)
		{
			printf("\nThis Node does not Exists..");
		}
		else if(pos>1 && pos<=nodectr)
		{
			prev=NULL;
			temp=start;
			for(i=1;i<pos;i++)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=temp->next;
			free(temp);
			printf("Node Deleted.\n");
		}
	   else
	   {
	   	 printf("\n%d is not aintermediate position.",pos);
	   }
	}
   }  
   
   int main()
  {
   int num,ch,n;
   while(1)
   {
   	printf("\n1. Create the list.\t");
   	printf("2. Delete from Beginning.\n");
   	printf("3. Delete from End.\t");
   	printf("4. Delete from Intermediate Position.\n");
   	printf("5. Display.\t");
   	printf("6. Exit.\n");
   printf("\nEnter your choice:");
   scanf("%d",&ch);
   switch(ch)
   {
   	  	case 1:
   	  	 printf("Enter of no. of elements wants to insert: ");
         scanf("%d",&num);
         create_list(num);
         break;
        case 2:
        	delete_at_beg();
        	break;
        case 3:
        	delete_at_last();
        	break;
        case 4:
        	delete_at_pos();
        	break;
        case 5:
        	traverse();
        	break;
        case 6:
        	exit(0);
        	break;
        default:
        	printf("\n Wrong Choice......");	
    }
   }
      return 0; 	
  }                          // Souvik Paul.......
 
  
   
