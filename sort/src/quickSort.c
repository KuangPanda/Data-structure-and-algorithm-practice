//快速排序
/*基本思想： 先从数列中取出一个数作为基准数。分区过程，将比这个数大的数全放到它的右边，小于或者是等于
 *它的数全放到它的左边，再对左右区间重复执行第二步，直到各区间只有一个数*/
/*
 *@arr store unsort array
 *@l => left, @r => right
*/
#include<stdio.h>

int adjustArray(int arr[], int l, int r) {
    int i = l;
    int j = r;
    int x = arr[l];
    while (i < j) {
        while (i < j && arr[j] > x) {
            j--;
        }
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }
        while (i < j && arr[i] <= x) {
            i++;
        }
        if (i < j) {
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = x;
    return i;
}

int quickSort(int arr[], int l , int r) {
    int i = 0;
    if (l < r) {
        i = adjustArray(arr, l, r);
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }
    return 0;
}

int main() 
{
    int i = 0;
    int arr[10] = {123, 45, 67, 43, 32, 3456, 43, 32, 765, 43};
    quickSort(arr, 0, 9);
    for (i = 0; i < 10; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}