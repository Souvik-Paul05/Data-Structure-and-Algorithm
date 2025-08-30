#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 struct dlinklist
 {
 	struct dlinklist *left;
 	int data;
 	struct dlinklist *right;
 };
 typedef struct dlinklist node;
 node *start=NULL;
 
 node *getnode()
 {
 	node *newnode;
 	newnode=(node*) malloc(sizeof(node));
 	printf("Enter Data:");
 	scanf("%d",&newnode->data);
 	newnode->left=NULL;
 	newnode->right=NULL;
 	return newnode;
 }
 
  // Creation of Double Linked List:
  
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
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			temp->right=newnode;
			newnode->left=temp;
		}
	 }
 }
 
 // Display of Double Linked list:
 
 void display_right_to_left()
  {
  	node *temp;
  	temp=start;
  	printf("The contents of list(right to left):\n");
  	if(start==NULL)
  	{
  		printf("Empty List..");
	  }
	else
	{
		while(temp->right != NULL)
		{
			temp=temp->right;
		}
	}
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp=temp->left;
	}
	printf("X\n");
  }
  
  void display_left_to_right()
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
		while(temp != NULL)
		{
			printf("%d->",temp->data);
			temp=temp->right;
		}
	}
	printf("X\n");
}

  // Count Node:
  
  int count_node()
  {
  	int count=1;
  	node *temp;
  	temp=start;
  	while(temp->right != NULL)
  	{
  		count++;
  		temp=temp->right;
	  }
	  return count;
  }
  
  // Delete from Beginning:
   
   void dll_delete_beg()
	{
		node *temp;
		if(start==NULL)
		{
			printf("No Nodes exists.");
			return;
		}
		else
		{
			temp=start;
			start=start->right;
			if(start != NULL)
			{
				start->left=NULL;
			}
			free(temp);
			printf("Node Deleted..\n");
		}
	}
	
	// Delete at End:
	
	void dll_delete_last()
	{
		node *temp;
		if(start==NULL)
		{
			printf("Empty list..");
			return;
		}
		else
		{
			temp=start;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			temp->left->right=NULL;
			free(temp);
			printf("Node Deleted..\n");
		}
	}
	
	// Delete at Intermediate Position:
	
	void dll_delete_pos()
   {
   	int i,pos,nodectr;
   	node *temp;
   	if(start==NULL)
   	{
   		printf("Empty list.");
   		return;
	   }
	else
	{
		printf("Enter position of the node want to delete:");
		scanf("%d",&pos);
		nodectr=count_node();
		if(pos>nodectr)
		{
			printf("this node does not exists..");
			return;
		}
		else if(pos>1 && pos<nodectr)
		{
			temp=start;
			for(i=1;i<pos;i++)
			{
				temp=temp->right;
			}
			temp->right->left=temp->left;
			temp->left->right=temp->right;
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
   	printf("4. Delete from Intermediate Position.\n");
   	printf("5. Display.\t");
   	printf("6. Exit.\n");
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
        	dll_delete_beg();
        	break;
        case 3:
        	dll_delete_last();
        	break;
        case 4:
        	dll_delete_pos();
        	break;
        case 5:
        	display_left_to_right();
        	display_right_to_left();
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
	

