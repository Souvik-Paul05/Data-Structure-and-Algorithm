#include<stdio.h>
 int main()
 {
 	int arr[100],i,n,val,pos;
 	printf("Enter the Size of the array:");
 	scanf("%d",&n);
 	printf("Enter the elements of the Array:");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&arr[i]);
	 }
	printf("Enter the new elements want to insert:");
	scanf("%d",&val);
	printf("Enter the Position to insert:");
	scanf("%d",&pos);
	for(i=n-1;i>=pos-1;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[pos-1]=val;
	printf("The Resultant Array is:\n");
	for(i=0;i<=n;i++)
	{
		printf("%d ",arr[i]);
	}
 	return 0;
 }
