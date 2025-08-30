#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 struct cdlinklist
 {
 	struct cdlinklist *left;
 	int data;
 	struct cdlinklist *right;
 };
 typedef struct cdlinklist node;
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
 
  // Creation of Circular Double Linked List:
  
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
 			newnode->left=start;
 			newnode->right=start;
		 }
		else
		{
			newnode->left=start->left;
			newnode->right=start;
			start->left->right=newnode;
			start->left=newnode;
		}
	 }
 }
 
 // Display of Circular Double Linked List:
 
  void cdll_display_left_to_right()
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
			temp=temp->right;
		} while(temp != start);	
	}
	printf("X\n");
  }
 
 void cdll_display_right_to_left()
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
		do
		{
			temp=temp->left;
		    printf("%d->",temp->data);
		} while(temp != start);	
	}
	printf("X\n");
  }
   
  // Insert at Beginning:
  
  void cdll_insert_beg()
  {
  	node *newnode;
  	newnode=getnode();
  	if(start==NULL)
  	{
  		start=newnode;
  		newnode->left=start;
  		newnode->right=start;
  		printf("Node Inserted.\n");
	  }
	else
	{
		newnode->left=start->left;
		newnode->right=start;
		start->left->right=newnode;
		start->left=newnode;
		start=newnode;
		printf("Node Inserted.\n");
	}
  }
  
  // Insert at End:
  
  void cdll_insert_end()
  {
  	node *newnode,*temp;
  	newnode=getnode();
  	if(start==NULL)
  	{
  		start=newnode;
  		newnode->left=start;
  		newnode->right=start;
  		printf("Node Inserted.\n");
	  }
	else
	{
		newnode->left=start->left;
		newnode->right=start;
		start->left->right=newnode;
		start->left=newnode;
		printf("Node Inserted.\n");
	}
  }
  
  // Node Count:
  
  int count_node()
  {
  	int count=1;
  	node *temp;
  	temp=start;
  	while(temp->right != start)
  	{
  		count++;
  		temp=temp->right;
	  }
	  return count;
  }
  
  
  // Insert at Intermediate Position:
  
  void cdll_insert_pos()
   {
   	node *newnode,*temp;
   	int pos,nodectr,i;
   	newnode=getnode();
   	printf("Enter the position:");
   	scanf("%d",&pos);
   	nodectr=count_node();
   	if (pos>(nodectr+1))
   	{
   		printf("Position is out of range...");
   		return;
	   }
	else if (pos>1 && pos<=nodectr)
	{
		temp=start;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->right;
		}
		newnode->left=temp;
		newnode->right=temp->right;
		temp->right->left=newnode;
		temp->right=newnode;
		printf("Node Inserted.\n");
	}
	else
	 {
	 	printf("%d is not a intermediate position.",pos);
	 	return;
	 }
   }
   
   // Delete at Beginning:
   
   void cdll_delete_beg()
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
			temp->left->right=start;
			start->left=temp->left;
			free(temp);
			printf("Node Deleted.\n");
		}
	}
	
	// Delete at Last:
	
		void cdll_delete_last()
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
			while(temp->right!=start)
			{
				temp=temp->right;
			}
			temp->left->right=temp->right;
			temp->right->left=temp->left;
			free(temp);
			printf("Node Deleted.\n");
		}
	}
   
   // Delete at the Intermediate Position:
   
   void cdll_delete_pos()
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
		printf("Enter position of node wany to delete:");
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
   	printf("\n1. Create the list.\n");
   	printf("2. insert at Beginning\n");
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
   	  	 printf("Enter of no. of Elements want to Insert:");
         scanf("%d",&num);
         create_list(num);
         break;
        case 2:
        	cdll_insert_beg();
        	break;
        case 3:
        	cdll_insert_end();
        	break;
        case 4:
        	cdll_insert_pos();
        	break;
        case 5:
        	cdll_delete_beg();
        	break;
        case 6:
        	cdll_delete_last();
        	break;
        case 7:
        	cdll_delete_pos();
        	break;
        case 8:
        	cdll_display_left_to_right();
        	cdll_display_right_to_left();
        	break;
        case 9:
        	exit(0);
        	break;
        default:
        	printf("\n Wrong Choice......");	
       }
    }
       return 0; 	
     }                  
