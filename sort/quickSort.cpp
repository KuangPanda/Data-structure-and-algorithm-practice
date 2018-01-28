#include <iostream>
#include <cstdlib>
#include "util.h"

using namespace std;

/*
 * 分区过程
 */

int adjustArray(int arr[], int left, int right) {
    int index = arr[left];
    int i = left;
    int j = right;

    while(i < j) {
        while(arr[j] > index && i < j) {
            j--;
        }

        if(i < j) {
            arr[i] = arr[j];
            i++;
        }

        while(arr[i] < index && i < j) {
            i++;
        }

        if(i < j) {
            arr[j] = arr[i];
            j--;
        }
    }
    arr[j] = index;
    return j;
}

/*
 * 快速排序 
 */

void quickSort(int arr[], int left, int right) {
    if(left < right) {
        int index = adjustArray(arr, left, right);
        quickSort(arr, left, index - 1);
        quickSort(arr, index + 1, right);
    }
}

int main(int argc, char **argv) {
    int len = atoi(argv[1]);
    int *arr = new int[len];
    
    generateRandArray(arr, len);

    quickSort(arr, 0, len - 1);

    for(int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    
    cout << endl;
    delete []arr;
    return 0;
}
