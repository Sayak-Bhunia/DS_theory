#include<stdio.h>
#include<stdlib.h>

int bubble_sort(int *a, int n) {
    int i,j,temp;
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(a[j]>a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int display(int *a, int n) {
    int i;
    for(i=0;i<n;i++) {
        printf("%d\t",*(a+i));
    }
}

int main()
{
    int n,i;
    printf("enter number of array elements: ");
    scanf("%d",&n);
    int* a = (int*)malloc(n*sizeof(int));
    printf("enter elements of the array:");
    for(i=0;i<n;i++) {
        scanf("%d",(a+i));
    }
    bubble_sort(a,n);
    display(a,n);
}
