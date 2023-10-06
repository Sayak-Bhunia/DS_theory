#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
}node;

typedef struct queue
{
    node* front;
    node* rear;
}queue;

queue q;

void enqueue(int val)
{
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->next = NULL;
    if(q.front == NULL) q.front = q.rear = temp;
    else {
        q.rear->next = temp;
        q.rear = temp;
    }
}

void dequeue()
{
    if(q.front == NULL) printf("\nQUEUE EMPTY!\n");
    else {
        node* temp = q.front;
        q.front = q.front->next;
        printf("DELETED ELEMENT = %d\n",temp->val);
        free(temp);
    }
}

void display()
{
    node* curr = q.front;
    if(curr == NULL) printf("\nQUEUE EMPTY!\n");
    else {
        printf("\nQUEUE ELEMENTS:\n");
        while(curr!=NULL) {
            printf("%d ",curr->val);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main()
{
    q.front = q.rear = NULL;
    int ch,val;
    while(1) {
        printf("1->INSERT\n");
        printf("2->DELETE\n");
        printf("3->DISPLAY\n");
        printf("4->EXIT\n");
        printf("ENTER CHOICE: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("\nENTER VAL: ");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nINVALID CHOICE!\n");
        }
    }
}
