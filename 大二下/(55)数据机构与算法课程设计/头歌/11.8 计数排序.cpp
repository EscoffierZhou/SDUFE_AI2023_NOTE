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


void sort_array(int *arr, int n)
// 编程实现《计数排序算法》
{
    /********** Begin *********/
    if (n == 0) {
        print_array(arr, n);
        return;
    }

    // 找最大和最小值以确定计数数组范围
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;
    int* count = (int*)calloc(range, sizeof(int));

    // 计数
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    // 打印每个元素及其个数（升序）
    for (int i = 0; i < range; i++) {
        if (count[i] > 0) {
            printf("%d %d\n", i + min, count[i]);
        }
    }

    // 还原排序后的数组
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + min;
            count[i]--;
        }
    }

    free(count);
    print_array(arr, n); // 输出排序后数组
    /********** End **********/
}



