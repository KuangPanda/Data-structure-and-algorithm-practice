#include<iostream>
#include<cstdlib>
#include"util.h"

using namespace std;

void insertSort(int arr[], int len) {
    int j = 0;
    int temp;
    int k;

    for(int i = 1; i < len; i++) {
        k = i;
        if(arr[i] < arr[i - 1]) {
            temp = arr[i];
            j = i - 1;
            while(temp < arr[j] && j >= 0) {
                arr[k] = arr[j];
                k--;
                j--;
            }
            arr[k] = temp;
        }
    }
}

int main(int argc, char **argv)
{
    int len = atoi(argv[1]);
    int *arr = new int[len];

    generateRandArray(arr, len);
    insertSort(arr, len);

    for(int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    delete[] arr;
    return 0;
}
