#include<stdio.h>
 int main() 
 {
 	int i,n,arr[100];
 	printf("Enter the Elements want to insert:");
 	scanf("%d",&n);
 	printf("Inserting the Element:");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&arr[i]);
	 }
	printf("Array Elements are:\n");
	for(i=0;i<n;i++)
 	{
 		printf("%d ",arr[i]);
	 }
	return 0;
 }   
 
 
 
 
