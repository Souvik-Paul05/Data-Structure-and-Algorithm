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
  do
  {
  	count++;
  	temp=temp->next;
  } while(temp->next!=start);
    return count;
  }
 
  // Delete from the Beginning:

	void cll_delete_beg()
	{
		node *temp,*last;
		if(start==NULL)
		{
			printf("No Nodes exists:");
			return;
		}
		else
		{
			last=temp=start;
			while(last->next!=start)
			{
				last=last->next;
			}
			start=start->next;
			last->next=start;
			free(temp);
			printf("Node Deleted.\n");
		}
	}
	
	// Delete from the End:

	void cll_delete_last()
	{
		node *temp,*prev;
		if(start==NULL)
		{
			printf("No nodes exists..");
			return;
		}
		else
		{
			temp=prev=start;
			while(temp->next!=start)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=start;
			free(temp);
			printf("Node Deleted.\n");
		}
	}
		
	// Delete from Intermediate Position:
	
	void cll_delete_pos()
   {
   	int i,pos,nodectr;
   	node *temp,*prev;
   	if(start==NULL)
   	{
   		printf("\n Empty list.");
   		return;
	   }
	else
	{
		printf("Enter position of the node want to delete:");
		scanf("%d",&pos);
		nodectr=count_node();
		if(pos>nodectr)
		{
			printf("\n this node does not exists..");
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
	   	 printf("\n %d is not aintermediate position.",pos);
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
   	printf("4. Detele from Intermediate Position.\n");
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
        	cll_delete_beg();
        	break;
        case 3:
        	cll_delete_last();
        	break;
        case 4:
        	cll_delete_pos();
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
     }                     // Souvik Paul.......
	
