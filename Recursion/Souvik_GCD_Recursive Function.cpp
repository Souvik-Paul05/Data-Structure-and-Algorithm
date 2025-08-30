#include<stdio.h>

 int gcd(int a,int b)
 {
 	if(a==0) 
		return b;
	if(b==0) 
		return a;
		
	if(a>b)
		return gcd(a-b,b);
	else
		return gcd(a,b-a);
 }
 int main()
 {
 	int num1,num2,result;
	printf("Enter the Two Number:");
	scanf("%d%d",&num1,&num2);
	result= gcd(num1,num2);
	printf("GCD: %d",result);
	return 0; 
 }
