#include<stdio.h>

#define SIZE 10

/* Program 1 of sorting Unit*/
/********** Bubble Sort ***************/
int main()
{
	int a[SIZE], index=0, jindex=0,temp=0;
	/*** a is the array used for sorting.
	 index and jindex are used for looping*/
	
	printf("\n Enter the %d element array to be sorted \n", SIZE);
	for(index = 0; index<SIZE; index ++)
	scanf("%d",&a[index]);
	
	/****** sorting logic***************/
	/** compare the jth element with (j+1)the element and move the larger element in a[j+1]*******/
	for(index=0; index < SIZE-1; index ++)
	{
		for(jindex=0; jindex < SIZE-index; jindex++)
		{
			if(a[jindex] > a[jindex+1])
				{
					temp = a[jindex]; a[jindex]= a[jindex+1]; a[jindex+1]= temp;
				}
		}
	for(jindex=0;jindex<SIZE; jindex++)
	 printf("\t%d",a[jindex]);
	 printf("\n");
	}
	
	/*** printing the sorted array */
	printf("\n the sorted array is:\n");
	for(index=0;index<SIZE; index++)
	printf("\t%d",a[index]);
	
	return 0;
}
