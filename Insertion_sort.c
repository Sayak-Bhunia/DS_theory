#include<stdio.h>
#include<stdlib.h>

int insertion_sort(int *a, int n) {
    int i,j,key;
    for(i=1;i<n;i++) {
        key = a[i];
        j = i - 1;
        while(a[j]>key && j>=0) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
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
