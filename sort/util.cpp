#include<cstdlib>
#include<ctime>
#include "util.h"

/*
 * 交换变量 
 */

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
 * 产生随机数组
 */

void generateRandArray(int *arr, int len) {
    srand((unsigned)time(NULL));
    for(int i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}
