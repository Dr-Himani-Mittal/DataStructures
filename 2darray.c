#include<stdio.h>
#include<conio.h>

#define ROW 5
#define COL 4

int main()
{
	int arr[ROW][COL], rindex=0, cindex=0, max,min;
	
	printf("\n Enter the %dX%d elements of the 2D array\n", ROW, COL);
	for(rindex=0;rindex<ROW; rindex++)
	{
		for(cindex=0; cindex<COL; cindex++)
		{
			scanf("%d",&arr[rindex][cindex]);
		}
	}
	
	printf("\n The %dX%d elements of the 2D array as entered by user\n", ROW, COL);
	
	for(cindex=0; cindex<COL; cindex++)
	{ 
	    max=min= arr[0][cindex];
		for(rindex=0;rindex<ROW; rindex++)
		{
			if( arr[rindex][cindex] > max) max = arr[rindex][cindex];
			if( arr[rindex][cindex] < min) min = arr[rindex][cindex];
			printf("\t%d",arr[rindex][cindex]);
		}
		printf("\nThe minimum element of %d row is:%d\n",rindex,min);
		printf("\nThe maximum element of %d row is:%d\n",rindex,max);

	}
	
	
	return 0;
}
