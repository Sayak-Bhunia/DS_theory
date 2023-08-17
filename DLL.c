#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node *prev,*next;
}node;

node *create()
{
    int item;
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    printf("enter element: ");
    scanf("%d",&item);
    ptr->val = item;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}

void insert_first(node **start)
{
    node *ptr, *temp;
    temp = create();
    if((*start) == NULL) (*start) = temp;
    else{
        temp->next = (*start);
        (*start)->prev = temp;
        (*start) = temp;
    }
}

void insert_last(node **start)
{
    node *ptr,*temp;
    temp = create();
    if((*start) == NULL) (*start) = temp;
    else if((*start)->next == NULL) {
        (*start)->next = temp;
        temp->prev = (*start);
    }
    else {
        ptr = (*start);
        while(ptr->next!=NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
        temp->next = NULL;
    }
}

void delete_first(node **start)
{
    node *ptr,*temp;
    if((*start) == NULL) printf("DLL is empty");
    else {
        temp = (*start);
        (*start) = (*start)->next;
        (*start)->prev = NULL;
        free(temp);
    }
}

void delete_last(node **start)
{
    node *ptr, *temp;
    if((*start) == NULL) printf("DLL is empty");
    else {
        ptr = (*start);
        while(ptr->next!=NULL) {
            ptr = ptr->next;
        }
        temp = ptr;
        ptr->prev->next = NULL;
        free(temp);
    }
}

void display(node **start)
{
    node *ptr;
    ptr = (*start);
    if((*start) == NULL) printf("DLL empty");
    else {
        printf("\n");
        while(ptr!=NULL) {
            printf("%d\t",ptr->val);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    node *start = NULL;
    int ch;
    while(1) {
        printf("\npress 1 to insert at first");
        printf("\npress 2 to insert at last");
        printf("\npress 3 to display");
        printf("\npress 4 to delete first element");
        printf("\npress 5 to delete last element");
        printf("\npress 6 to exit");
        printf("\nenter your choice:");
        scanf("%d",&ch);

        switch(ch) {
            case 1:insert_first(&start);
                   break;
            case 2:insert_last(&start);
                   break;
            case 3:display(&start);
                   break;
            case 4:delete_first(&start);
                   break;
            case 5:delete_last(&start);
                   break;
            case 6:exit(0);
            default:printf("invalid choice");
        }
    }
}
