#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *arr;
    int size;
    int top;
};

struct Stack create(int size) {
    struct Stack s;
    s.size = size;
    s.top = -1;
    s.arr = (int *)malloc(sizeof(int) * size);
    if (s.arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return s;
}

void push(struct Stack *s)
{
    int val;
    if (s->top == s->size - 1)
        printf("\nOVERFLOW!\n");
    else {
        (s->top)++;
        printf("Enter data to PUSH: \n");
        scanf("%d", &val);
        s->arr[s->top] = val;
    }
}

void pop(struct Stack *s)
{
    if (s->top == -1)
        printf("\nUNDERFLOW!\n");
    else {
        (s->top)--;
    }
}

void display(struct Stack *s)
{
    int i;
    if (s->top == -1)
        printf("\nUNDERFLOW!\n");
    else {
        for (i = s->top; i >= 0; i--) {
            printf("%d\n", s->arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    struct Stack s;
    int ch;
    printf("Enter size of Stack: ");
    scanf("%d", &s.size);

    s = create(s.size);

    while (1) {
        printf("1->PUSH\n");
        printf("2->POP\n");
        printf("3->DISPLAY\n");
        printf("4->EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        case 4:
            free(s.arr);
            exit(0);
            break;
        default:
            printf("INVALID CHOICE!\n");
        }
    }

    return 0;
}

