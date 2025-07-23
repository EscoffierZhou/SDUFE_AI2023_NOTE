//
//  sort_.cpp
//  Sort
//
//  Created by ljpc on 2018/4/20.
//  Copyright © 2018年 ljpc. All rights reserved.
//

//#include "sort_.h"
#include "iostream"
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

int* merge_array(int *arr1, int n1, int* arr2, int n2)
//  编程实现两个有序数组arr1和arr2合并
//  函数参数：有序数组arr1 数组arr1长度 有序数组arr2 数组arr2长度
//  函数返回值：返回从小到大排序后的合并数组
{
    /********** Begin *********/
    int* merged = (int*)malloc((n1 + n2) * sizeof(int));
    int i = 0, j = 0, k = 0;

    // 合并两个有序数组
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // 复制剩余元素
    while (i < n1) {
        merged[k++] = arr1[i++];
    }
    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    return merged;
    /********** End **********/
}
int* merge_sort(int *arr, int n)
//  基于merge_array函数编程实现归并排序：自上而下的递归方法
//  函数参数：有序数组arr 数组arr长度
//  函数返回值：返回从小到大排序后的数组
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (n <= 1) {
        int* result = (int*)malloc(n * sizeof(int));
        if (n == 1) result[0] = arr[0];
        return result;
    }

    int mid = n / 2;

    // 递归地对左右两半排序
    int* left = merge_sort(arr, mid);
    int* right = merge_sort(arr + mid, n - mid);

    // 合并排序后的左右两半
    int* result = merge_array(left, mid, right, n - mid);

    // 释放临时内存
    free(left);
    free(right);

    return result;
    /********** End **********/
}


