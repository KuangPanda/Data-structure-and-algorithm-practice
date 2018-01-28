#include<iostream>
#include<cstdlib>
#include"util.h"

using namespace std;

void shellSort(int arr[], int len) {
    int temp = 0;
    int k = 0;
    int j = 0;

    for(int interval = len / 2; interval > 0; interval /= 2) {
        for(int i = interval; i < len; i++) {
            k = i;
            if(arr[i] < arr[i - interval]) {
                temp = arr[i];
                j = i - interval;
                while(temp < arr[j] && j >= 0) {
                    arr[k] = arr[j];
                    k -= interval;
                    j -= interval;
                }
                arr[k] = temp;
            }
        }  
    }
}

int main(int argc, char **argv)
{
    int len = atoi(argv[1]);
    int *arr = new int[len];

    generateRandArray(arr, len);
    shellSort(arr, len);

    for(int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    delete []arr;
    return 0;
}