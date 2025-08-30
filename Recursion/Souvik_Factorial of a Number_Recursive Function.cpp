#include<stdio.h>

 int fact(int n)
 {
 	if(n==0)
 		return 1;
	else
		return n*fact(n-1);
 }
 int main()
 {
 	int n,x;
 	printf("Enter the Range:");
 	scanf("%d",&n);
 	x=fact(n);
 	printf("Factorial of %d: %d",n,x);
 	return 0;
 }
