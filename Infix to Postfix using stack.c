#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void push(char x, char *arr, int *top)
{
    arr[++(*top)] = x;
}

char pop(char *arr, int *top)
{
    if((*top) == -1) return -1;
    else return arr[(*top)--];
}

int precedence(char x)
{
    if(x == '(') return 0;
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    if(x == '^' || x == '$') return 3;
    return 0;
}

int main()
{
    char *arr;
    char exp[] = "A+(B/C-(D*E^F)+G)*H";
    char *e,x;
    e = exp;
    int top = -1;
    arr = (char*)malloc(strlen(exp)*sizeof(char));

    while((*e)!='\0') {
        if(isalnum(*e)) printf("%c ",*e);
        else if((*e) == '(') push(*e,arr,&top);
        else if((*e) == ')') {
            while((x = pop(arr,&top)) != '(') {
                    printf("%c ",x);
            }
        }
        else {
            while(precedence(arr[top]) >= precedence(*e)) {
                printf("%c ",pop(arr,&top));
            }
            push(*e,arr,&top);
        }
        e++;
    }
    while(top != -1) {
        printf("%c ",pop(arr,&top));
    }
}
