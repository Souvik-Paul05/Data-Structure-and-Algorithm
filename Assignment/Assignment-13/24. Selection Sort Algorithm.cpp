#include<stdio.h>
 int main()
 {
 	int arr[100],n,i,j,temp;
 	printf("Enter the no. of Elements want to Insert:");
 	scanf("%d",&n);
 	printf("Enter the Array Elements:\n");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&arr[i]);
	 }
	 
	for(i=0;i<n;i++)                    // Selection Sort Logic..
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	printf("After Selection Sort, the Sorting Elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
	return 0;
 }
