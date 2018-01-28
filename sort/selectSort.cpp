#include<iostream>
#include<cstdlib>
#include"util.h"

using namespace std;

void selectSort(int arr[], int len) {
    int index = 0;
    for(int i = 0; i < len; i++) {
        index = i;
        for(int j = i + 1; j < len; j++) {
            if(arr[j] < arr[index]) {
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}

int main(int argc, char **argv)
{
    int len = atoi(argv[1]);
    int* arr = new int[len];

    generateRandArray(arr, len);
    selectSort(arr, len);

    for(int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    delete []arr;

    return 0;
}