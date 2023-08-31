#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node *prev;
    struct node *next;
}node;

node *create()
{
    node *temp;
    temp = (node*)malloc(sizeof(node));
    printf("Enter element for NEW node: ");
    scanf("%d",&temp->val);
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void push(node **start,node **top,node **end)
{
    node *ptr, *temp;
    temp = create();

    if((*start) == NULL)
    {
        (*start) = temp;
        (*top) = temp;
        (*end) = temp;
    }
    else {
        temp->next = (*start);
        (*start)->prev = temp;
        (*start) = temp;
        (*top) = temp;
    }
}

void pop(node **start,node **top, node **end)
{
    node *ptr,*temp;
    if((*start) == NULL) printf("\nSTACK EMPTY!\n");
    else if((*start)->next == NULL) {
        temp = (*start);
        (*start) = NULL;
        (*top) == NULL;
        (*end) == NULL;
        free(temp);
    }
    else {
        temp = (*start);
        (*start) = (*start)->next;
        (*top) = (*start);
        free(temp);
    }
}

void display(node **start,node **top,node **end)
{
    node *ptr;
    if((*start) == NULL) printf("\nSTACK EMPTY!\n");
    else {
        ptr = (*start);
        while(ptr!=(*end)) {
            printf("%d\n",ptr->val);
            ptr = ptr->next;
        }
    }
}

int main()
{
    node *start = NULL;
    node *top = start;
    node *end;

    int ch;
    while(1) {
        printf("1->PUSH\n");
        printf("2->POP\n");
        printf("3->DISPLAY\n");
        printf("4->EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1: push(&start,&top,&end);
                    break;
            case 2: pop(&start,&top,&end);
                    break;
            case 3: display(&start,&top,&end);
                    break;
            case 4: exit(0);
                    break;
            default: printf("\nINVALID CHOICE!\n");
        }
    }

}

