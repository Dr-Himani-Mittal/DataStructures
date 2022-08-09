#include<stdio.h>

#define SIZE 10

/*program 7: insert in array*/

int add(int[], int*, int, int);

int main()
{
	int a[SIZE]={1,2,3,4,5,6,7}, i=0, n=7, loc=-1, item=0,ret=0;
	
	printf("\n The array is:\n");
	for(i=0; i<n; i++)
	{
		printf("%d \n", a[i]);
	 } 
	printf("\n Enter the location where insertion is to be made:\n");
	scanf("%d",&loc);
	
	printf("\n enter the item to be added:\n");
	scanf("%d",&item);
	
	ret= add(a,&n,loc,item);
	
	if(ret ==0)
	{
		printf("\n modified array is:\n");
		for(i=0; i<n; i++)
		{
			printf("%d \n", a[i]);
	 	} 
		
	}
	return 0;
}

int add(int a[], int *n, int loc, int item)
{
	int i=0;
	if (loc > *n) {return -1;}
	for( i = *n; i>loc-1; i--)
	{
		a[i]=a[i-1];
		}	
	a[i]=item;
	*n = (*n)+ 1;
	return 0;
}
