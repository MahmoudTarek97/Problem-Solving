#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getMinIndex(int anArray[], int first, int last) {
    int minIndex;
    int index;
    minIndex = first;
    for (index = first + 1; index <= last; index++)
    {
        if (anArray[index]<anArray[minIndex])
        minIndex = index;
    }
    return minIndex;
}

void swap (int A[], int a, int b) {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void selectionSort(int anArray[], int size) {
    int minIndex;
    int index;
    for (index = 0; index < size -1; index++)
    {
        minIndex = getMinIndex(anArray, index, size-1);
        swap(anArray, index, minIndex);
    }
}

int main()
{
    int t,Arr[3],i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d %d",&Arr[0],&Arr[1],&Arr[2]);
        selectionSort(Arr,3);
        printf("Case %d: %d\n",i+1,Arr[1]);
    }
    return 0;
}
