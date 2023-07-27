#include<stdio.h>
#include<stdlib.h>

int insertion(int *a, int *n)
{
	int i,ele,pos;

	printf("enter the position where you want to insert an element: ");
	scanf("%d",&pos);
	printf("enter element to insert: ");
	scanf("%d",&ele);

	if(pos>*n) {
		printf("invalid input");
	}
	else {
		*n=*n+1;
	    a = (int*)realloc(a,(*n)*sizeof(int));
	    for(i=*n-1;i>=pos;i--) {
		    a[i+1]=a[i];
        }
	    a[pos]=ele;
    }
}

int display(int *a, int *n)
{
	int i;
	for(i=0;i<*n;i++) {
        printf("%d\t",*(a+i));
	}

}

int deletion(int *a, int *n)
{
    int pos,i;
    printf("enter the position where you want to delete an element: ");
	scanf("%d",&pos);
	if(pos>=*n) {
        printf("invalid input");
	}
	else {
        *n=*n-1;
        for(i=pos;i<=*n;i++) {
            a[i]=a[i+1];
        }
        a = (int*)realloc(a,(*n)*sizeof(int));
	}
}


int main()
{
	int n,i,ch,c=0;
	printf("enter the size of the array: ");
	scanf("%d",&n);

	int* a=(int)malloc(n*sizeof(int));

	printf("enter the elements of the array: ");
	for(i=0;i<n;i++) {
		scanf("%d",(a+i));
	}
	while(1) {
        printf("\nPress 1 to insert");
        printf("\nPress 2 to delete");
        printf("\nPress 3 to display");
        printf("\nPress 4 to exit");
        printf("\nenter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insertion(a,&n);
                    break;

            case 2: deletion(a,&n);
                    break;
            case 3: display(a,&n);
                    break;
            case 4: exit(0);
            default: printf("invalid choice");
        }
	}
}
