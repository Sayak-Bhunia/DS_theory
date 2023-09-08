#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void push(char x,char *arr, int *top)
{
    arr[++(*top)] = x;
}

char pop(char *arr, int *top)
{
    if((*top) == -1) return -1;
    else return arr[(*top)--];
}

int main()
{
    char *arr;
    char exp[20];
    printf("ENTER EXPRESSION: ");
    scanf("%s",exp);
    char *e,x;
    e = exp;
    int top = -1;
    int a,b,c,d,z=0,y=0,m;
    arr = (char*)malloc(strlen(exp)*sizeof(char));
    if(*e != '\0') {
        if(*e == '+' || *e == '-' || *e == '*' || *e == '/' || *e == '^' || *e == '$') {
            printf("NOT A POSTFIX!");
            exit(0);
        }
    }
    while(*e != '\0') {
        if(isdigit(*e)) {
            c = (*e) - 48;
            push(c,arr,&top);
            z++;
        }
        else {
            y++;
            a = pop(arr,&top);
            b = pop(arr,&top);
            switch(*e) {
                case '+': d = a + b;
                         break;
                case '-': d = a - b;
                         break;
                case '*': d = a * b;
                         break;
                case '/': d = (float)a / b;
                         break;
                case '^':case '$':
                    m = 1;
                    while(b!=0) {
                          m = m * a;
                          b--;
                    }
                    d = m;
                    break;
                default: printf("INVALID OPERATOR FOUND!");
            }
            push(d,arr,&top);
        }
        e++;
    }
    if(z == y+1) {
        printf("RESULT = %d",pop(arr,&top));
    }


    else printf("NOT A POSTFIX!");
}
