//2017-04-09
#include<stdio.h>
#include<stdlib.h>

int insertSort1(int arr[], int n) {
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = 0;
    for (i = 1; i < n; i++) {
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                break;
            }
        }

        if (j != i - 1) {
             temp = arr[i];
             for (k = i; k > j; k--) {
                 arr[k + 1] = arr[k];
             }
             arr[k + 1] = temp;
        }
    }
    return 0;
}

int insertSort2(int arr[], int n) {
    int i, j;
    int temp = 0;
    for (i = 1; i < n; i++) {
        if(arr[i] < arr[i - 1]) {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}

int main() {
    int i = 0;
    int arr[2] = {3, 2};
    insertSort1(arr, 2);
    for (i = 0; i < 2; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}