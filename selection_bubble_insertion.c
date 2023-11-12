#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int z = *a;
    *a = *b;
    *b = z;
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
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

void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++) {
        int key = arr[i];
        int j = i - 1;
        while(key<arr[j] && j>=0) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                int z = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = z;
            }
        }
    }
}

int main()
{
    int size;
    printf("enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    int ch;
    while(1) {
        printf("0->INSERT ELEMENTS:\n");
        printf("1->INSERTION SORT!\n");
        printf("2->SELECTION SORT!\n");
        printf("3->BUBBLE SORT!\n");
        printf("4->EXIT\n");
        printf("ENTER CHOICE:\n");
        scanf("%d",&ch);
        switch(ch) {
            case 0: for(int i=0;i<size;i++) {
                        scanf("%d",&arr[i]);
                    }
                    break;
            case 1: insertion_sort(arr,size);
                    print(arr,size);
                    break;
            case 2: selection_sort(arr,size);
                    print(arr,size);
                    break;
            case 3: bubble_sort(arr,size);
                    print(arr,size);
                    break;
            case 4: exit(0);
            default: printf("INVALIDE CHOICE!\n");
        }
    }
}
