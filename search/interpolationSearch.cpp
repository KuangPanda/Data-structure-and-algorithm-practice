#include<iostream>

using namespace std;

int interpolationSearch(int array[], int n, int value) {
    int left  = 0;
    int right = n - 1;
    int mid   = 0;

    if(!array || n < 0) {
        return -1;
    }

    while(left <= right) {
        mid = left + (value - array[left])/(array[right] - array[left]) * (right - left);
        cout << mid << endl;
        
        if(mid < 0 || mid >= n) {
            return -1;
        } else if(array[mid] > value) {
            right = mid - 1;
        } else if(array[mid] < value) {
            left  = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;

}
