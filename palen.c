#include "palen.h"
void palen()
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
		printf("%d is palendrome\n");
	else
		printf("%d is not palendrome\n");
}
