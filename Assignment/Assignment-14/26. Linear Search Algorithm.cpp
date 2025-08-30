#include<stdio.h>
 int main()
 {
 	int i,arr[100],n,flag=0,val,pos;
 	printf("Enter the no. of Elements Want to Insert:");
 	scanf("%d",&n);
 	printf("Enter the Array Elements:\n");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&arr[i]);
	 }
	printf("Enter the Element to Search:");
	scanf("%d",&val);
	
	for(i=0;i<n;i++)                      // Linear Search Logic..
	{
		if(val==arr[i])
		{
			pos=i+1;
			flag=1;
			break;
		}
	}
	
	if(flag==1)
	{
		printf("In Position %d The Element %d is Present",pos,val);
	}
	else
	{
		printf("The Element is not Present in the Array.");
	}
	return 0;
 }
