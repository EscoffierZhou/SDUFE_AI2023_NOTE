//
//  sort_.cpp
//  Sort
//
//  Created by ljpc on 2018/4/20.
//  Copyright © 2018年 ljpc. All rights reserved.
//

//#include "sort_.h"
#include<iostream>
void print_array(int *arr, int n)
// 打印数组
{
    if(n==0){
        printf("ERROR: Array length is ZERO\n");
        return;
    }
    printf("%d", arr[0]);
    for (int i=1; i<n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void adjustHeap(int *arr, int i, int heapSize)
// 编程实现堆的调整（最大堆）
{
    /********** Begin *********/
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // 如果左子节点大于根
    if (left < heapSize && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于目前最大值
    if (right < heapSize && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根节点，交换并递归调整
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        adjustHeap(arr, largest, heapSize);
    }
    /********** End **********/
}

int* heap_sort(int *arr, int n)
// 基于adjustHeap函数编程实现堆排序
{
    /********** Begin *********/
    // 构建初始最大堆（自底向上）
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjustHeap(arr, i, n);
    }

    // 逐步将最大值放到末尾，并调整堆
    for (int i = n - 1; i > 0; i--) {
        // 交换根（最大值）与当前末尾元素
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 调整剩余堆结构
        adjustHeap(arr, 0, i);
    }

    return arr;
    /********** End **********/
}


