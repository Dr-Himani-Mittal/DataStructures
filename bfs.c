#include<stdio.h>
#include"queue.c"
#define WHITE 0
#define GREY 1
#define BLACK 2

int color[10];
int adj[10][10];
char names[10];
int n;

int bfs(int start)
{
	int u,v;
	int i,j;
	color[start]= GREY;
	enqueue(start);
	while(front != -1)
	{
		u=dequeue();
		for(i=0; i<n; i++)
		{
			if((adj[u][i]==1)&&(color[i]==WHITE))
			{
				enqueue(i); color[i]=GREY;
			}
		 } 
		 color[u]=BLACK;
		 printf("%c->",names[u]);
	}
	return 0;	
}


int dfs(int start)
{	
	int i;
	color[start]=BLACK;
	printf("%c->",names[start]);

//	printf("yes");
	for(i=0; i<n; i++)
	{
		if((adj[start][i]==1)&&(color[i]==WHITE))
		{
			color[i]=GREY;
			dfs(i);
		}
	 } 
	return 0;	
}



int main()
{
	int i,j, y;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	
	printf("\n Enter the names of the vertices:\n ");
	for(i=0;i<n;i++) { printf("\n enter the name of %d vertex:",i);
                    fflush(stdin);   scanf("%c",&names[i]);
                   }
	
	printf("\n Enter the adjacency matrix \n ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("\n Is there a edge between (%c,%c): (0-no and 1-yes)",names[i],names[j]);
		fflush(stdin);
		scanf("%d",&y);
		adj[i][j]=y;
		
        } 
    }
	
	for(i=0;i<n;i++) color[i]=WHITE;
	printf("bfs output:");bfs(0);
	for(i=0;i<n;i++) color[i]=WHITE;
	printf("dfs output:");dfs(0);

}
