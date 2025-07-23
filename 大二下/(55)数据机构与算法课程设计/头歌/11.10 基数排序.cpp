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


int* sort_array(int *arr, int n)
// 编程实现《基数排序算法》
{
    /********** Begin *********/
    if (n <= 0) return NULL;

    // 找最大值，决定位数
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    // 使用LSD（最低位优先）基数排序
    int exp = 1; // 位权（个位、十位、百位...）
    int* output = (int*)malloc(n * sizeof(int));

    while (maxVal / exp > 0) {
        int count[10] = {0};

        // 统计每个桶中数量
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        // 计数数组转为前缀和数组
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // 从后往前遍历原数组，将元素放入对应位置（稳定排序）
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[--count[digit]] = arr[i];
        }

        // 拷贝结果回原数组
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }

    free(output);
    return arr;
    /********** End **********/
}



