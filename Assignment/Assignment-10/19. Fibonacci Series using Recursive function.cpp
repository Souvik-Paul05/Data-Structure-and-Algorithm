#include<stdio.h>
 
 int fib(int n)
 {
 	int x;
 	if(n==0 || n==1)
 		return n;
 	else
 	{
 		x=fib(n-1)+fib(n-2);
 		return x;
	 }
 }
 int main()
 {
 	int n,i;
 	printf("Enter the range:");
 	scanf("%d",&n);
 	printf("Fibonacci Series:\n");
 	for(i=0;i<n;i++)
 	{
 		printf("%d\n",fib(i));
	 }
 	return 0;
 }
