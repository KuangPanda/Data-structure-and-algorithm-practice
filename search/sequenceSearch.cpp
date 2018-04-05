#include<iostream>

using namespace std;

/*
 * array: array
 * n    : the length of array
 * value: the value you want search in array
*/

int sequenceSearch(int array[], int n, int value) {
    if(!array || n < 1) {
        return -1;
    }

    for(int i = 0; i < n; i++) {
        if(value == array[i]) {
            return i;
        }
    }
    return -1;
}
