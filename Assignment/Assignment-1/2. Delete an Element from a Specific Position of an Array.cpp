#include<stdio.h>
 int main()
 {
 	int arr[100],i,n,val,pos;
 	printf("Enter the size of the Array:");
 	scanf("%d",&n);
 	printf("Enter the Array Elements:");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&arr[i]);
	 }
 	printf("Enter the position to delete:");
 	scanf("%d",&pos);
 	for(i=pos-1;i<n;i++)
 	{
 		arr[i]=arr[i+1];
	 }
	printf("The Resltant Array is:\n");
	for(i=0;i<n-1;i++)
	{
		printf("%d ",arr[i]);
	}
 	return 0;
 	
 }
