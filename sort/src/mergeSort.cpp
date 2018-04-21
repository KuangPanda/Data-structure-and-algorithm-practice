#include<iostream>
#include<cstdlib>
#include"util.h"

using namespace std;


void mergeArray(int *arr, int first, int mid, int last, int *temp) {
    int i = first;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= last) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= last) {
        temp[k++] = arr[j++];
    }

    for(i = 0; i < k; i++) {
        arr[first + i] = temp[i];
    }
}

void mergeSort(int *arr, int first, int last, int *temp) {
    if(first < last) {
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid, temp);
        mergeSort(arr, mid + 1, last, temp);
        mergeArray(arr, first, mid, last, temp);
    }
}

int main(int argc, char **argv) {
    int len = atoi(argv[1]);
    int *arr = new int[len];
    int *temp = new int[len];
    
    generateRandArray(arr, len);
    mergeSort(arr, 0, len - 1, temp);

    for(int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }

    cout << endl;
    delete []arr;
    delete []temp;
    return 0;
}
