//2017-04-09
#include<stdio.h>
#include<stdlib.h>

int shellSort1(int arr[], int n) {
    int i, j, gap; //gap步长
    int temp, k;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = 0; i < gap; i++) {
            for (j = i + gap; j < n; j += gap) {
                if (arr[j] < arr[j - gap]) {
                    temp = arr[j];
                    k = j - gap;
                    while (k >= 0 && arr[k] > temp) {
                        arr[k + gap] = arr[k];
                        k -= gap;
                    }
                    arr[k + gap] = temp;
                }
            }
        }
    }
    return 0;
}

int main() {
    int i = 0;
    int arr[10] = {12, 23, 34, 32, 21, 2, 45, 6789, 54, 43};
    shellSort1(arr, 10);
    for (i = 0; i < 10; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}