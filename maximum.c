#include<stdio.h>
#include<conio.h>

#define SIZE 10

int main()
{
	int arr[SIZE], index=0, max=0, n=0;
	
	printf("\nEnter the number of elements you want to read in the array\n");
	scanf("%d",&n);
	
	printf("\n Enter the %d elements: \n",n);
	for(index=0;index<n;index ++)
		scanf("%d",&arr[index]);
	max= arr[0];	
	for(index=0;index<n;index++)	
		{
			if(arr[index]>max)
				max= arr[index];
		}
	printf("\n The maximum number you entered is %d",max);
}
