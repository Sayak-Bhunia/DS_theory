#include<stdio.h>
#include<stdlib.h>

void push(int *arr, int n, int *top)
{
    int val;
    if((*top) == n-1) printf("\nOVERFLOW!\n");
    else {
        (*top)++;
        printf("Enter data to PUSH: \n");
        scanf("%d",&val);
        arr[(*top)] = val;
    }
}

void pop(int *arr, int n, int *top)
{
    if((*top) == -1) printf("\nUNDERFLOW!\n");
    else {
        (*top)--;
    }
}

void display(int *arr, int *top)
{
    int i;
    if((*top) == -1) printf("\nUNDERFLOW!\n");
    else {
        for(i=(*top);i>=0;i--) {
            printf("%d\n",arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    int *arr,n,top,ch;
    printf("Enter size of Stack: ");
    scanf("%d",&n);
    top = -1;

    arr = (int*)malloc(sizeof(int)*n);
    while(1) {
        printf("1->PUSH\n");
        printf("2->POP\n");
        printf("3->DISPLAY\n");
        printf("4->EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1: push(arr,n,&top);
                    break;
            case 2: pop(arr,n,&top);
                    break;
            case 3: display(arr,&top);
                    break;
            case 4: exit(0);
                    break;
            default: printf("INVALID CHOICE!");
        }
    }

}
