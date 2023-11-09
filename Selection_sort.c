#include<stdio.h>

void swap(int *a,int *b)
{
    int z = *a;
    *a = *b;
    *b = z;
}

void selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++) {
        int min = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[min]) {
                min = j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {20, 12, 15, 7, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,size);
    printf("sorted array in ascending order: ");
    print(arr,size);

}
