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
	 
	for(i=1;i<n;i++)                  // logic for Insertion Sort:
	{
		j=i-1;
		temp=arr[i];
		while(temp<arr[j] && j>=0)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}

	
	printf("After Insertion Sort, the Sorting Elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
	return 0;
 }
