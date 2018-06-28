#include<stdio.h>
void main()
{
	int n,i,sum=0;
	printf("enter integer:");
	scanf("%d",&n);
	i=n;
	while(i)
	{
		sum=sum*10+i%10;
		i/=10;
	}
	if(sum==n)
		printf("given num is palendrome\n");
	else
		printf("given num is not palendrome\n");
}
