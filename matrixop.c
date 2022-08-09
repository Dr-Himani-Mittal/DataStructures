#include<stdio.h>

#define ROW 5
#define COL 5

int main()
{
	int a[ROW][COL],b[ROW][COL],c[ROW][COL] ,ri,ci, ai;
	
	printf("\n Enter two Matrix of 5*5 dimension for addition:\n");
	printf("\n Enter Matrix 1\n");
	for(ri=0;ri <ROW;ri++)
	{
		for(ci=0;ci<COL;ci++)
		{
			scanf("%d",&a[ri][ci]);
		}
	}

    printf("\n Enter Matrix 2\n");
	for(ri=0;ri <ROW;ri++)
	{
		for(ci=0;ci<COL;ci++)
		{
			scanf("%d",&b[ri][ci]);
		}
	}
    
	for(ri=0;ri <ROW;ri++)
	{
		for(ci=0;ci<COL;ci++)
		{
			c[ri][ci]= a[ri][ci] + b[ri][ci];
		}
	}
	
	printf("\n The summation of two Matrix is :\n");
	for(ri=0;ri <ROW;ri++)
	{
		for(ci=0;ci<COL;ci++)
		{
			printf("\t%d",c[ri][ci]);
		}
		printf("\n");
	}
    
	printf("\n The difference of two matrix A-B is :\n");
	for(ri=0;ri <ROW;ri++)
	{
		for(ci=0;ci<COL;ci++)
		{
			c[ri][ci]= a[ri][ci] - b[ri][ci];
			printf("\t%d",c[ri][ci]);
		}
		printf("\n");
	}
    
    printf("\n The difference of two matrix B-A is :\n");
	for(ri=0;ri <ROW;ri++)
	{
		for(ci=0;ci<COL;ci++)
		{
			c[ri][ci]= b[ri][ci] - a[ri][ci];
			printf("\t%d",c[ri][ci]);
		}
		printf("\n");
	}
    
	printf("\n The Multiplication of two matrix A*B is :\n");
	for(ri=0;ri <ROW;ri++)
	{
		for(ci=0;ci<COL;ci++)
		{   c[ri][ci]=0; 
			for(ai=0;ai<ROW;ai++)
			c[ri][ci]= c[ri][ci] + (a[ri][ai] * b[ai][ci]);
			printf("\t%d",c[ri][ci]);
		}
		printf("\n");
	}
    
	
	
	
	return 0;
}
