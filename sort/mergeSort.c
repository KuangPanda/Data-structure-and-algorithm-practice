//归并算法=> 分治法
/* 基本思路就是将数组分成二组A，B，然后再将数组分成二组，以此类推，
 * 当分出来的小组只有一个数据时，可认为这个小组组内已经有序，然后
 * 合并相邻的二个小组即可。先递归的分解数列，再合并数列就完成归并排序
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*merge array*/
void mergeArray(int arr[], int first, int mid, int last, int temp[]) {
    int i = first;
    int j = mid + 1;
    int m = mid;
    int n = last;
    int k = 0; //数组循环变量

    while (i <= m && j <= n) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= n) {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < k; i++) {
        arr[first + i] = temp[i];
    }
}

/*(divide and conquer)*/
int mergeTempSort(int arr[], int first, int last, int temp[]) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeTempSort(arr, first, mid, temp); //左边有序
        mergeTempSort(arr, mid + 1, last, temp); //右边有序
        mergeArray(arr, first, mid, last, temp); //合并数组使之有序
    }
    return 0;
}

/*merge sort*/
bool mergeSort(int arr[], int n) {
    int * p = malloc(n * sizeof(int));
    if (p == NULL) {
        printf("not enough room for mallocing\n");
        return false;
    }
    mergeTempSort(arr, 0, n - 1, p);
    free(p);
    return true;
}

int main()
{
    int i = 0;
    int arr[10] = {12, 23, 3, 4567, 54, 43, 31, 456, 432, 1};
    bool temp = false;
    mergeSort(arr, 10);
    for (i = 0; i < 10; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}