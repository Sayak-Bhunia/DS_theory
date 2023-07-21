#include<stdio.h>
#include<stdlib.h>

void insert(int *a, int n, int ele, int pos)
{
	int i;
	for(i=n-1;i>=pos;i--) {
		a[i+1]=a[i];
	}
	a[pos]=ele;
}

void display(int *a, int n)
{
	int i;
	for(i=0;i<n;i++) {
		printf("%d\t",*(a+i));
	}
}

int main()
{
	int n,i,ele,pos;
	printf("enter the size of the array: ");
	scanf("%d",&n);
	
	int* a=(int)malloc(n*sizeof(int));
	
	printf("enter the elements of the array: ");
	for(i=0;i<n;i++) {
		scanf("%d",(a+i));
	}
	
	printf("enter the position where you want to insert an element: ");
	scanf("%d",&pos);
	printf("enter element to insert: ");
	scanf("%d",&ele);
	
	if(pos>n) {
		printf("invalid input");
	}
	else {
		n=n+1;
	    realloc(a,n*sizeof(int));
		insert(a,n,ele,pos);
		display(a,n);
	}
}
