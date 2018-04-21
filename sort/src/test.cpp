/*
 * 记忆堆排序
 */
#include<iostream>
using namespace std;
/*
 * 调整堆
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
        swap(array[maxIndex], array[loc]);
        adjustHeap(array, maxIndex, len);
    }

}

/*
 * 堆排序
 */
void heapSort(int *array, int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        adjustHeap(array, i, n);
    }

    for(int i = n - 1; i >  0; i--) {
        swap(array[0], array[i]);
        adjustHeap(array, 0, i);
    }
}

int main() {
    int array[10] = {10, 15, 20, 13, 17, 89, 78, 87, 34, 56};
    heapSort(array, 10);
    for(int i = 0; i < 10; i++) {
        cout << array[i] << endl;
    }
}