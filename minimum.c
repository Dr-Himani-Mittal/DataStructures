#include<stdio.h>
#include<conio.h>

#define SIZE 20

/* This program finda the minimum number in the array*/

int main()
{
	int arr[SIZE], index=0, min=0, n=0;
/* arr is the input list, n is the number of elements in the array*/
/* the output of program is min which   is the minimum number in the array*/	
	printf("\nEnter the number of elements you want to read in the array (value should be less than 10)\n");
	scanf("%d",&n);
	if(n>SIZE) return -1;
	printf("\n Enter the %d elements: \n",n);
	for(index=0;index<n;index ++)
		scanf("%d",&arr[index]);
	min= minimum(arr,n);
	printf("\n The minimum number you entered is %d",min);
}

int minimum(int arr[SIZE], int n)
{
	int index=0, min=arr[0];
	for(index=0;index<n;index++)	
		{
			if(arr[index] < min)
				min = arr[index];
		}
return min;	
}
