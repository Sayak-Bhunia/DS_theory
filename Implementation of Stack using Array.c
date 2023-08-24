#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    int top;
    int capacity;
    int *arr;
}stack;

stack *create(int capacity)
{
    stack *s = (stack*)malloc(sizeof(stack));
    if(!s) return NULL;
    s->capacity = capacity;
    s->top = -1;
    s->arr = (int*)malloc((s->capacity)*sizeof(int));
    if(!s->arr) return NULL;
    return s;
}

int isempty(stack *s)
{
    return(s->top == -1);
}

int size(stack *s)
{
    return (s->top+1);
}

int isfull(stack *s)
{
    return (s->top == s->capacity-1);
}

void push(stack *s, int data)
{
    if(isfull(s)) printf("\nStack Overflow\n");
    else {
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(stack *s)
{
    int data;
    if(isempty(s)) {
        printf("\nStack Underflow\n");
        return -1;
    }
    else {
        data = s->arr[s->top];
        s->top--;
        printf("\npopped %d",data);
    }
}

int peek(stack *s)
{
    if(isempty(s)) {
        printf("\nStack Underflow\n");
        return -1;
    }
    else {
        return (s->arr[s->top]);
    }
}

void delete(stack *s)
{
    if(s){
        if(s->arr) {
            free(s->arr);
            free(s);
        }
    }
}

int main()
{
    int i=0,capacity=10,ch,data;
    stack *s = create(capacity);

    while(1) {

            printf("\npress 1 for pushing data");
            printf("\npress 2 for poping data");
            printf("\nenter choice: ");
            scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("enter element: ");
                   scanf("%d",&data);
                   push(s,data);
                   break;
            case 2:pop(s);
                   break;
            case 3:exit(0);
            default:printf("invalid choice");
        }
    }
}
