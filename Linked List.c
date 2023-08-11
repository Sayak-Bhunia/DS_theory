#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}node;

node* create()
{
    int item;
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    printf("enter data: ");
    scanf("%d",&item);
    ptr->val = item;
    ptr->next = NULL;
    return ptr;
}

void insert_first(node **start)
{
    node *temp;
    temp = create();
    if((*start) == NULL) (*start) = temp;
    else {
        temp->next = (*start);
        (*start) = temp;
    }
}

void insert_last(node **start)
{
    node *ptr,*temp;
    temp = create();
    if((*start) == NULL) (*start) = ptr;
    else{
        ptr = (*start);
        while(ptr->next!=NULL) {
            ptr = ptr->next;
        }
     ptr->next = temp;
    }
}

void display(node **start)
{
    node *ptr,*temp;
    ptr = (*start);
    if((*start) == NULL) printf("no node present in the Linked List");
    else{
        printf("\n");
        while(ptr!=NULL) {
            printf("%d ",ptr->val);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void delete_first(node **start)
{
    node *ptr,*temp;
    if((*start) == NULL) printf("deletion is not possible");
    else{
        temp = (*start);
        (*start) = (*start)->next;
        free(temp);
    }
}

void delete_last(node **start)
{
    node *ptr,*preptr=NULL;
    if((*start) == NULL) printf("deletion is no t possible");
    else{
        ptr = (*start);
        preptr = (*start);
        while(ptr->next!=NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
        return;
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
        printf("\npress 4 to delete first node");
        printf("\npress 5 to delete last node");
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
