#include<stdio.h>
 int main()
 {
 	int i,arr[100],n,flag=0,val,pos;
 	int beg,end,mid;
 	printf("Enter the no. of Elements Want to Insert:");
 	scanf("%d",&n);
 	printf("Enter the Sorted Array Elements:\n");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&arr[i]);
	 }
	printf("Enter the Element to Search:");
	scanf("%d",&val);
	
	beg=0;                         // Linear Search Logic...
	end=n-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(arr[mid]==val)
		{
			pos=mid+1;
			flag=1;
			break;
		}
		else if(arr[mid]<val)
		{
			beg=mid+1;
		}
		else
		{
			end=mid-1;
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
