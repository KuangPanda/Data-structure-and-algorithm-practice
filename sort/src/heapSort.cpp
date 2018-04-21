/*
 * 假设按照从小到大排序
 */

#include<iostream>

using namespace std;

/*
 *　调整堆, 还涉及一个移位操作
 */
void adjustHeap(int *array, int loc, int len) {
    int leftChild = 2 * loc + 1;
    int rightChild = 2 * loc + 2;
    int maxIndex = loc;

    if(leftChild < len & array[leftChild] > array[maxIndex]) {
        maxIndex = leftChild;
    }

    if(rightChild < len & array[rightChild] > array[maxIndex]) {
        maxIndex = rightChild;
    }

    if(maxIndex != loc) {
        swap(array[loc], array[maxIndex]);
        adjustHeap(array, maxIndex, len);
    }
}

/*
 * 堆排序
 */
void heapSort(int *array, int n) {
    //建立一个大顶堆
    for(int i = n / 2 - 1; i >= 0; i--) {
        adjustHeap(array, i, n);
    }   

    for(int i = n - 1; i >=0 ; i--) {
        swap(array[0], array[i]); //将最大的数移到最后

        adjustHeap(array, 0, i);
    }
}
