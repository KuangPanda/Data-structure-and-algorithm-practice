#include<iostream>
#include<cstdlib>
#include"util.h"

using namespace std;

void mergeSort(int *arr, int len) {

}

void mergeArray(int* left, int leftArrayLen, int* right, int rightArrayLength) {
    
}

int main(int argc, char **argv) {
    int len = atoi(argv[1]);
    int *arr = new int[len];

    generateRandArray(arr, len);
    mergeSort(arr, len);

    for(int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }

    cout << endl;
    delete []arr;
    return 0;
}
