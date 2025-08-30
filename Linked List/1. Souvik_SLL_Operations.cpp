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
  
  // Insertion at the Beginning:
  
  void insert_at_beg()
  {
  	node *newnode;
  	newnode=getnode();
  	if (start==NULL)
  	{
  		start=newnode;
  		printf("Node Inserted...\n");
	  }
	else
	{
		newnode->next=start;
		start=newnode;
		printf("Node Inserted...\n");
	}
  }
  
  // Insertion at the End:
  
   void insert_at_end()
   {
   	 node *newnode, *temp;
   	 newnode=getnode();
   	 if(start==NULL)
   	 {
   	 	start=newnode;
   	 	printf("Node Inserted...\n");
	}
	else
	{
		temp=start;
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
	   temp->next=newnode;
	   printf("Node Inserted...\n");
	}
}

   // Insertion at the Intermediate Position:
   
   void insert_at_pos()
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
		printf("Node Inserted...\n");
	}
	else
	 {
	 	printf("%d is not a intermediate position.",pos);
	 }
   }
   
   // Delete Node from the Beginning:
   
   void delete_at_beg()
   {
   	node *temp;
   	if(start==NULL)
   	{
   		printf("\n No Nodes are exists.");
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
   
   // Delete Node from the End:
   
   void delete_at_last()
   {
   	 node *temp,*prev;
   	 if(start==NULL)
   	 {
   	 	printf("Empty List.");
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
   
   // Delete Node from the Intermediate Position:
   
   void delete_at_pos()
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
			printf("this node does not exists..\n");
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
   	printf("\n1. Create the list.\n");
   	printf("2. Insert at Beginning.\n");
   	printf("3. Insert at End.\n");
   	printf("4. Insert at Intermediate Position.\n");
   	printf("5. Delete form Beginning.\n");
   	printf("6. Delete from End.\n");
   	printf("7. Delete from Intermediate Position.\n");
   	printf("8. Display.\n");
   	printf("9. Exit.\n");
   printf("\nEnter your choice:");
   scanf("%d",&ch);
   switch(ch)
   {
   	  	case 1:
   	  	 printf("Enter of no. of Elements wants to Insert: ");
         scanf("%d",&num);
         create_list(num);
         break;
        case 2:
        	insert_at_beg();
        	break;
        case 3:
        	insert_at_end();
        	break;
        case 4:
        	insert_at_pos();
        	break;
        case 5:
        	delete_at_beg();
        	break;
        case 6:
        	delete_at_last();
        	break;
        case 7:
        	delete_at_pos();
        	break;
        case 8:
        	traverse();
        	break;
        case 9:
        	exit(0);
        	break;
        default:
        	printf("\n Wrong Choice......");	
    }
  }
    return 0; 	
  }                       // Souvik Paul.......
 
