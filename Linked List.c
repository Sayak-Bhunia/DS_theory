#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

node* create()
{
    int item;
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &item);
    ptr->val = item;
    ptr->next = NULL;
    return ptr;
}

void insert_first(node **start)
{
    node *temp;
    temp = create();
    if ((*start) == NULL)
        (*start) = temp;
    else {
        temp->next = (*start);
        (*start) = temp;
    }
}

void insert_last(node **start)
{
    node *ptr, *temp;
    temp = create();
    if ((*start) == NULL)
        (*start) = temp;
    else {
        ptr = (*start);
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display(node **start)
{
    node *ptr;
    ptr = (*start);
    if ((*start) == NULL)
        printf("No nodes present in the Linked List\n");
    else {
        printf("\n");
        while (ptr != NULL) {
            printf("%d ", ptr->val);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void delete_first(node **start)
{
    node *temp;
    if ((*start) == NULL)
        printf("Deletion is not possible. The list is empty.\n");
    else {
        temp = (*start);
        (*start) = (*start)->next;
        free(temp);
    }
}

void delete_last(node **start)
{
    node *ptr, *preptr = NULL;
    if ((*start) == NULL)
    {
        printf("Deletion is not possible. The list is empty.\n");
        return;
    }
    else if ((*start)->next == NULL)
    {
        // If there is only one node in the list
        free(*start);
        *start = NULL;
        return;
    }
    else
    {
        ptr = (*start);
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
}

int main()
{
    node *start = NULL;
    int ch;
    while (1) {
        printf("\nPress 1 to insert at first");
        printf("\nPress 2 to insert at last");
        printf("\nPress 3 to display");
        printf("\nPress 4 to delete first node");
        printf("\nPress 5 to delete last node");
        printf("\nPress 6 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert_first(&start);
                break;
            case 2:
                insert_last(&start);
                break;
            case 3:
                display(&start);
                break;
            case 4:
                delete_first(&start);
                break;
            case 5:
                delete_last(&start);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
