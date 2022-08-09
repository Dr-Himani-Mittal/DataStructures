//#include<stdio.h>

#define SIZE 10

int queue[SIZE], front =-1, rear=-1;

int enqueue(int val)
{
	if(rear+1 <= SIZE)
	{
		rear=rear+1;
		queue[rear] = val;
	}
	if (front ==-1) front = rear;
	return 0;
}

int dequeue()
{
	int u;
	if(front==-1) return -1;
	u= queue[front];
	queue[front]= -1;
	front ++;
	if(front >rear) front=rear=-1;
	return u;
}
/*
int main()
{
	int i;
	enqueue(1);
	
	enqueue(2);
	enqueue(3);
	printf("\n");
	for(i=front;i<=rear;i++)
	printf("\t %d",queue[i]);
	printf("\n");printf("The value dequeued is: %d",dequeue());
	printf("\n");printf("The value dequeued is: %d",dequeue());
	printf("\n");printf("The value dequeued is: %d",dequeue());
	enqueue(7);
	enqueue(8);
	printf("\n");
	for(i=front;i<=rear;i++)
	printf("\t %d",queue[i]);
	printf("\n");printf("The value dequeued is: %d",dequeue());
	printf("\n");for(i=front;i<=rear;i++)
	printf("\t %d",queue[i]);
	enqueue(9);
	enqueue(10);
	printf("\n");
	for(i=front;i<=rear;i++)
	printf("\t %d",queue[i]);
	printf("\n");printf("The value dequeued is: %d",dequeue());
	for(i=front;i<=rear;i++)
	printf("\t %d",queue[i]);
}*/
