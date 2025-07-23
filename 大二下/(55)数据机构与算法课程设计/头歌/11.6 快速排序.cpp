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

int partition_array(int *arr ,int l,int r)
// 编程实现arr[l, r]分区：选定一个基准，左边比基准小，右边比基准大
// 返回基准所处位置
{
    /********** Begin *********/
    int pivot = arr[r]; // 选择最右边元素作为基准
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            // 交换 arr[i] 和 arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // 将基准元素放到中间位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

    return i + 1;
    /********** End **********/
}

int* quick_sort(int *arr, int l, int r)
// 基于partition_array函数编程实现快速排序：自上而下的递归方法
{
    /********** Begin *********/
    if (l < r) {
        int p = partition_array(arr, l, r);
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
    }
    return arr;
    /********** End **********/
}
