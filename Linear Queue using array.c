#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int *arr;
    int size;
    int front;
    int rear;
};

struct Queue create(int size)
{
    struct Queue q;
    q.size = size;
    q.front = 0;
    q.rear = 0;
    q.arr = (int*)malloc(sizeof(int)*size);
    if (q.arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return q;
};

void enqueue(struct Queue *q)
{
    int val;
    if(q->rear == q->size) printf("\nOVERFLOW\n");
    else {
        if(q->front == 0 && q->rear == 0) q->front = q->rear = 1; //initial case/first insertion
        else (q->rear)++; //normal case
        printf("ENTER ELEMENT TO INSERT: ");
        scanf("%d",&val);
        q->arr[q->rear] = val;
    }
}

void dequeue(struct Queue *q)
{
    if((q->front) == 0) printf("\nQUEUE EMPTY!\n");
    else if((q->front) == (q->rear)) { //QUEUE contains only one element.
        q->front = q->rear = 0;
    }
    else (q->front)++; //normal case
}

void display(struct Queue *q)
{
    int i;
    if((q->front) == 0) printf("\nQUEUE EMPTY!\n");
    else{
        printf("\nQUEUE ELEMENTS:\n");
        for(i=q->front;i<=q->rear;i++) {
            printf("%d ",q->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct Queue q;
    int ch,val;
    printf("ENTER SIZE: ");
    scanf("%d",&q.size);

    q = create(q.size);

    while (1) {
        printf("1->INSERT\n");
        printf("2->DELETE\n");
        printf("3->DISPLAY\n");
        printf("4->EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
                enqueue(&q);
                break;
        case 2: dequeue(&q);
                break;
        case 3: display(&q);
                break;
        case 4: free(q.arr);
                exit(0);
                break;
        default:
            printf("INVALID CHOICE!\n");
        }
    }
    return 0;
}
