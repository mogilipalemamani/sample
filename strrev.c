#include<stdio.h>
#include<string.h>
#include"palen.c"
void main()
{
	char p[],temp;
	int i,j;
	palen();
	printf("enter string:");
	scanf("%s",p);
	for(i=0,j=strlen(p)-1;i<j;i++,j--)
	{
		temp=p[i];
		p[i]=p[j];
		p[j]=temp;
	}
	printf("the reversed string is:%s\n",p);
}
