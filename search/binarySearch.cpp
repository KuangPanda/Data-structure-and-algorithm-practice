#include<iostream>

using namespace std;

/*
 * array: array
 * n    : the length of array
 * value: the value you want to search in array
*/

int binarySearch(int array[], int n, int value) {
    int left  = 0;
    int right = n - 1;
    int mid   = 0;

    if(!array || n < 1) {
        return -1;
    }

    while(left <= right) {
        
        mid   = (left + right) / 2;
        cout << mid;
        if(value == array[mid]) {
            return mid;
        } else if(array[mid] > value) {
            right = mid - 1;
        } else {
            left  = mid + 1;
        }
    }

    return -1; 
}
