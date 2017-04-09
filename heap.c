//2017-03-31堆排序
#include<stdio.h>
#include<stdlib.h>

void heapAdjust(int arr[], int n, int i) {
    int lchild = 2 * i;
    int rchild = 2 * i + 1;
    int temp = i;
    int k;
    if (temp <= n/2) {
        if (lchild <= n && arr[lchild] > arr[temp]) {
            temp = lchild;
        }
        if (rchild <= n && arr[rchild] > arr[temp]) {
            temp = rchild;
        }
        if (temp != i) {
            k = i;
            i = arr[temp];
            arr[temp] = k;
            heapAdjust(arr, n, temp);
        }
    }
}

void buildHeap(int arr[], int n) {
    int i;
    for(i = n/2; i >= 1; i--) {
        heapAdjust(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    int i;
    int k;
    buildHeap(arr, n);
    for (i = n; i >= 1; i--) {
        k = i;
        i = arr[1];
        arr[1] = k;
        heapAdjust(arr, 1, i - 1);
    }
}

int main(int argc, char* argv[]) 
{
    int arr[10] = {12, 23, 34, 3222, 21, 23434, 5667, 78, 89, 654};
    int i = 0;
    heapSort(arr, 10);
    for (i = 0; i < 10; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}