#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int *arr;
    int size;
    int front;
    int rear;
}Queue;

Queue create(int size)
{
    Queue q;
    q.size = size;
    q.front = 0;
    q.rear = 0;
    q.arr = (int*)malloc(sizeof(int)*size);
    if(q.arr == NULL) {
        printf("memory allocation failed!");
        exit(1);
    }
    return q;
}

void enqueue(Queue *q)
{
    int val;
    if((q->rear+1) % (q->size+1) == q->front) printf("overflow\n");
    else {
        printf("enter element to insert: ");
        scanf("%d",&val);
        q->rear = (q->rear+1)%(q->size+1);
        q->arr[q->rear] = val;
    }
}

void dequeue(Queue *q)
{
    if(q->front == q->rear) printf("queue empty\n");
    else q->front = (q->front+1)%(q->size+1);
}

void display(Queue *q)
{
    int i,n;
    if(q->front == q->rear) printf("queue empty\n");
    else {
        printf("Queue elements:\n");
        n = (q->rear - q->front + (q->size+1))%(q->size+1);
        for(i=1;i<=n;i++) {
            printf("%d ",q->arr[(q->front+i)%(q->size+1)]);
        }
        printf("\n");
    }
}

int main()
{
    Queue q;
    int ch,val;
    printf("enter size: ");
    scanf("%d",&q.size);
    q = create(q.size);
    while(1) {
        printf("1->insert\n");
        printf("2->delete\n");
        printf("3->display\n");
        printf("4->exit");
        printf("enter your choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: enqueue(&q);
                    break;
            case 2: dequeue(&q);
                    break;
            case 3: display(&q);
                    break;
            case 4: free(q.arr);
                    exit(0);
                    break;
            default: printf("invalid choice\n");
        }
    }
}
