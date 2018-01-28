#include<cstdlib>
#include<ctime>
#include<iostream>
#include"util.h"

using namespace std;

/*
 * 基本的冒泡排序
 */

void bubbleSort(int arr[], int len, int option = ASCENDING) {
    for(int i = 0; i < len; i++) {
        for(int j = 1; j < len - i; j++) {
            if(option == 1 && arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
            }

            if(option == 0 && arr[j - 1] < arr[j]) {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

/*
 * 改进一: 如果一次遍历中没有交换变量, 说明已经排好序.
 */

void bubbleSort_1(int arr[], int len, int option = ASCENDING) {
    bool flag = false;

    for(int i = 0; i < len; i++) {
        flag = true;

        for(int j = 1; j < len - i; j++) {
            if(option == 1 && arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                flag = false;
            }

            if(option == 0 && arr[j - 1] < arr[j]) {
                swap(arr[j - 1], arr[j]);
                flag = false;
            }
        }

        if(flag) {
            break;
        }
    }
}

/*
 * 改进二: 记录最后一次交换变量的位置.
 */

int bubbleSort_2(int arr[], int len, int option = ASCENDING) {
    bool flag = false;
    int index = 0;
    int loc = len;

    for(int i = 0; i < len; i++) {
        flag = true;
        for(int j = 1; j < loc; j++) {
            if(option == 1 && arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
                flag = false;
                index = j;
            }

            if(option == 0 && arr[j - 1] < arr[j]) {
                swap(arr[j - 1], arr[j]);
                flag = false;
                index = j;
            }
        }
        loc = index;
        if(flag) {
            break;
        }
    }
}


int main(int argc, char **argv)
{
    int len = atoi(argv[1]);
    int* arr = new int[len];
    clock_t start, end;

    generateRandArray(arr, len);
    
    start = clock();
    bubbleSort(arr, len);
    end = clock();
    cout << "bubbleSort: " << end - start << " ms" << endl;
    
    for(int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }

    cout << endl;
    delete []arr;
    return 0;
}