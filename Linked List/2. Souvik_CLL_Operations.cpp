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
 
  // creation of circular linked list:
 
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
 
  // display function:
  
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
  
  // count_node:
  
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

 // Insertion at the Beginning:
  
  void cll_insert_beg()
  {
  	node *newnode, *temp;
  	newnode=getnode();
  	if(start==NULL)
  	{
  		start=newnode;
  		newnode->next=start;
  		printf("Node Inserted..\n");
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
		printf("Node Inserted..\n");
	}
  }
  
  // insertion at the end:
  
  void cll_insert_end()
  {
  	node *newnode,*temp;
  	newnode=getnode();
  	if(start==NULL)
  	{
  		start=newnode;
  		newnode->next=start;
  		printf("Node Inserted..\n");
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
		printf("Node Inserted..\n");
	}
  }
  
  // Insertion at Intermediate Position:
  
  void cll_insert_at_pos()
   {
   	node *newnode,*temp;
   	int pos,nodectr,i;
   	newnode=getnode();
   	printf("Enter the position:");
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
		printf("Node Inserted..\n");
	}
	else
	 {
	 	printf("%d is not a intermediate position.",pos);
	 }
   }
   
   // Delete from the Beginning:

	void cll_delete_beg()
	{
		node *temp,*last;
		if(start==NULL)
		{
			printf("No Nodes exists..");
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
	
	void cll_delete_at_pos()
   {
   	int i,pos,nodectr;
   	node *temp,*prev;
   	if(start==NULL)
   	{
   		printf("Empty list.");
   		return;
	   }
	else
	{
		printf("Enter position of node wany to delete:");
		scanf("%d",&pos);
		nodectr=count_node();
		if(pos>nodectr)
		{
			printf("this node does not exists..");
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
	   	 printf("%d is not aintermediate position.",pos);
	   }
	}
   }
   
   int main()
  {
   int num,ch,n;
   while(1)
   {
   	printf("\n1. Create the list.\n");
   	printf("2. Insert at Beginning.\n");
   	printf("3. Insert at End.\n");
   	printf("4. Insert at Intermediate Position.\n");
   	printf("5. Delete from Beginning.\n");
   	printf("6. Delete from End.\n");
   	printf("7. Delete from Intermediate Position.\n");
   	printf("8. Display.\n");
   	printf("9. Exit.\n");
   printf("\nEnter your choice:");
   scanf("%d",&ch);
   switch(ch)
   {
   	  	case 1:
   	  	 printf("Enter of no. of elements wants to insert:");
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
        	cll_insert_at_pos();
        	break;
        case 5:
        	cll_delete_beg();
        	break;
        case 6:
        	cll_delete_last();
        	break;
        case 7:
        	cll_delete_at_pos();
        	break;
        case 8:
        	display();
        	break;
        case 9:
        	exit(0);
        	break;
        default:
        	printf("\n Wrong Choice......");	
       }
    }
       return 0; 	
     }                  // Souvik Paul.......
