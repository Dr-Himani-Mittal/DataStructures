#include<stdio.h>

#define SIZE 10

/* Program 2 in sorting Unit*/
/***************SELECTION SORT*********************/

int main()
{
	int a[SIZE],jindex, index, loc,temp;
	/** a is the array to be sorted***>
	/* index and jindex are used for looping***/
	/*** loc is used for storing the location of minimum element****/
	/**** temp is used for swaping**/
	printf("\n enetr the %d element array:\n",SIZE);
	for(index=0;index < SIZE; index++)
		scanf("%d",&a[index]);
	
	/** actual sorting logic***/
	/*** find the location of minimum element into loc and swap a[i] with a[loc]****/
	for(index=0; index < SIZE-1; index++)
	{
		loc=index;
		for(jindex=index+1; jindex<SIZE; jindex++)
		{
			if(a[jindex] <a[index])
			loc=jindex;
		}
		temp=a[index]; a[index]= a[loc]; a[loc]= temp;
	}
	
	printf("\n The sorted array is :\n");
	for(index=0;index < SIZE; index++)
		printf("\t%d",a[index]);
	
		
	return -1;
}
