#include<stdio.h>

#define SIZE 10
/** Program 4 Merger sort of sorting unit*/

int mergesort(int a[],int low, int high);
int merge(int a[],int low, int mid, int high);

int main()
{
	int a[SIZE] = {10,2,4,3,7,8,9,5,55,1}, i=0;
	/** a is the array to be sorted**/
	/* i is used for looping*/
	/*Mergersort is the function to perform sorting*/
	printf("\n the unsorted array is:\n");
	for(i=0; i<SIZE; i++)
	printf("\t %d", a[i]);
	
	mergesort(a, 0, SIZE-1);
	
	printf("\n the sorted array is:\n");
	for(i=0; i<SIZE; i++)
	printf("\t %d", a[i]);
	return 0;
}

int mergesort(int a[], int low, int high)
{
	int mid;
	// base condition of recursion, return when a single element is left in the logical division of a
	if(low >= high) return 0;
	// calculate the point of division
	mid= (low+high)/2;
	
	// recursively call mergesort and divide a logically
	mergesort(a,low,mid);
	mergesort(a, mid+1,high);
	// merge the divided array
	merge(a,low, mid, high);
	return 0; 
}

int merge(int a[],int low, int mid, int high)
{
	int i=low,k=low, j=mid+1, b[SIZE],indx;
	
	while((i<= mid) &&(j<= high))
	{
		if(a[i]<a[j]) { b[k]=a[i]; i++;}
		else { b[k]=a[j]; j++;}
		k++;	
	}
	// case when one of the arrays is empty
	if(i>mid) { for(indx=j;indx<=high;indx++,k++) { b[k] = a[indx];}
	} 
	else { for(indx=i;indx<=mid;indx++,k++) { b[k] = a[indx];}
	} 
	
	// copy all element from low to high in a
	for(indx= low; indx<= high; indx++) a[indx]=b[indx];
		
	return 0;
}
