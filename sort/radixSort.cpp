#include <iostream>
#include <cstdlib>
#include "util.h"

using namespace std;

/*
 * 返回最大数的长度
 */

int getMaxValueLen(int *arr, int begin, int end) {
    int maxValue = 0;
    int length = 0;

    if(NULL == arr) {
        return 0;
    }

    for(int i = begin; i <= end; i++) {
        if(arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    while(maxValue != 0) {
        maxValue /= 10;
        length++;
    }

    return length;
}

/*
 * 返回特定位置的数字
 */

int getDigit(int value, int d) {
    int val;
    while (d--) {
        val = value % 10;
        value /= 10;
    }
    return val;
}

/*
 * 基数排序
 */

void radixSort(int *arr, int begin, int end, int radix) {
    int *bucket = new int[end - begin + 1];
    int *count = new int[radix];

    int index = 1;
    int j = 0;
    int length = getMaxValueLen(arr, begin, end);

    while(index <= length) {
        for(int i = 0; i < radix; i++) {
            count[i] = 0;
        }

        for(int i = begin; i <= end; i++) {
            j = getDigit(arr[i], index);
            count[j]++;
        }

        for(int i = 1; i < radix; i++) {
            count[i] = count[i] + count[i - 1];
        }

        for(int i = end; i >= begin; i--) {
            j = getDigit(arr[i], index);
            bucket[count[j] - 1] = arr[i];
            count[j]--;
        }

        for(int i = begin; i <= end; i++) {
            arr[i] = bucket[i - begin];
        }

        index++;
    }
}

int main(int argc, char **argv)
{
    int len = atoi(argv[1]);
    int *arr = new int[len];

    generateRandArray(arr, len);
    radixSort(arr, 0, len - 1, 10);
    
    for(int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}