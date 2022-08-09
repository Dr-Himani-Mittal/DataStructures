#include<stdio.h>
#include<conio.h>

int main()
{
	int a[3]; int i;
	printf("\n Enter three numbers: \n");
	
	for( i =0; i<3; i++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("\n The numbers you enetered are: \n");
	for(i=0; i< 3; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n End of program. press any key to continue \n");	getch();
	return 0;
}
