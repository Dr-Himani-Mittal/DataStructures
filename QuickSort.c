#include<stdio.h>

#define SIZE 10

int partition(int a[],int low, int high)
{
	int pivot=low, i=low, j=high+1, temp=0;;
	
	do{
		do{ i++; } while(a[i]<a[pivot]);
		do{ j--; } while(a[j]>a[pivot]);
		if(i<j) { temp=a[i]; a[i]=a[j]; a[j]=temp;}		
	}while(i<j);
	temp= a[pivot]; a[pivot]= a[j]; a[j]=temp;
	return j;
}

int QuickSort(int a[], int low, int high)
{
	int j;
	if(low<high)
	{
		j= partition(a,low,high);
		QuickSort(a,low,j-1);
		QuickSort(a,j+1, high);
	}
}

int main()
{
	int a[SIZE]={10,9,8,7,6,5,4,3,2,1}, i=0;
	
	QuickSort(a,0,SIZE-1);
	printf("\n the sorted array is :");
	for(i = 0; i< SIZE; i++)
	printf("\t%d",a[i]);
	return 0;
}
