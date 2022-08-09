#include<stdio.h>
#include<conio.h>
#include<string.h>
#define NAMENO 10
#define NAMECH 15

int main()
{
	char name[NAMENO][NAMECH], noindex=0, n=0, max[NAMECH];
	
	printf("\n how many names you want to enter\n");
	scanf("%d",&n);
	printf("\n enter the names in the array:\n");
	for(noindex=0; noindex<n;noindex++)
	{
		fflush(stdin);
		gets(name[noindex]);
	}
	printf("\n the array entered is\n");
	
	strcpy(max,name[0]);
	for(noindex=0; noindex<n;noindex++)
	{
		if (strcmp(name[noindex],max)>0)
		     strcpy(max,name[noindex]);
		     
		printf("\nreturn value of strcmp is: %d", strcmp(name[noindex],max));
		puts(name[noindex]);
	}
	printf("\n the maximum value is: ");
	puts(max);
		puts("\n");
}
