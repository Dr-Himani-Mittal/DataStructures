#include<stdio.h>

#define SIZE 10

/* Program 3 of sorting Unit**/
/**************INSERTION SORT**************/

int main()
{
	int a[SIZE], jindex, index, target;
	/** a is the array to be sorted***/
	/* jindex and index are used for looping*/
	/* tatret is the lement whose position is to be found in LHS of the array***/
	
	/** taking input**/
	printf("\n enter the %d elemnt array to be sorted\n",SIZE);
	for(index=0; index<SIZE; index++)
	scanf("%d", &a[index]);
	
	/** main sorting happens here****/
	/* assument the LHS elemst to be sorted and place the ith element in the LHS elements in sorted order.*/
	for(index=1; index<SIZE; index++)
	{
		target= a[index];
		for(jindex= index-1; jindex>= 0 && a[jindex]>target; jindex--)
		{
			a[jindex + 1]=a[jindex];
		}
		a[jindex + 1]= target;
		
	
	for(jindex=0; jindex<SIZE; jindex++)
	printf("\t%d", a[jindex]);
	printf("\n");
	}
	
	
	
	/** printing the output***/
	printf("\n the sorted array is :");
	for(jindex=0; jindex<SIZE; jindex++)
	printf("\t%d", a[jindex]);
	
	
	return 0;
}
