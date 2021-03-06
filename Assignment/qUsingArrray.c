#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int array[5];
	int front, rear;
};
int enqueue(struct queue * myqueue, int elem)
{
    if(myqueue->rear == 5) return 0;
    myqueue->array[myqueue->rear++]=elem;
    return 1;    
}
int dequeue(struct queue *myqueue, int *status)
{
if(myqueue->front == myqueue->rear){
*status = 0;
return -1;
}
*status=1;
 return myqueue->array[myqueue->front++];
}
void init(struct queue *myqueue)
{
	myqueue -> front = 0;
	myqueue -> rear = 0;
}
int main()
{
	int elem;
	struct queue myqueue;
	init(&myqueue);
	int choice;
	int val, status;
	while(-100)
	{
		printf("\nEnter:\n\t1 - to Insert to Queue\n\t2 - to Delete from Queue\n\t0 - to Exit: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Please enter the element: ");
				scanf("%d", &elem);
				enqueue(&myqueue, elem);
				break;
			case 2:
				val = dequeue(&myqueue, &status);
				if(status  == 1)
				{
					printf("Removed element is %d: \n", val);
				}
				break;
			case 0: exit(0);
		}
	}
	printf("\n");

}
