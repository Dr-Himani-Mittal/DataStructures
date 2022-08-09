#include<stdio.h>
#define size 10

int deleteArray(int[], int*, int);

int main()
{
	int a[size]={1,2,3,4,5,6,7}, i=0, n=7, loc=-1, ret=0;
	printf("\n The array is:\n");
	for(i=0; i<n; i++)
	{
		printf("%d \n", a[i]);
	 } 
	printf("\n Enter the location where deletion is to be made:\n");
	scanf("%d",&loc);
	ret= add(a,&n,loc);
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

int deleteArray(int a[], int *n, int loc)
{
	int i=0;
	if (loc > *n) {return -1;}
	for( i = loc; i>(*n)-1 ; i--)
	{
		a[i]=a[i+1];
		}	
	
	*n = (*n)- 1;
	return 0;
}

