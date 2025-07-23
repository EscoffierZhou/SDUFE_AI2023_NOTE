//
//  sort_.cpp
//  Sort
//
//  Created by ljpc on 2018/4/20.
//  Copyright © 2018年 ljpc. All rights reserved.
//

// #include "sort_.h"
#include <cstdio> // For printf

void print_array(int *arr, int n)
// 打印数组
{
    if(n==0){
        printf("错误：数组长度为零\n");
        return;
    }
    printf("%d", arr[0]);
    for (int i=1; i<n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void sort_array(int *arr, int n)
//  编程实现《选择排序算法》：将乱序序列arr转化为升序序列
//  函数参数：乱序整数数组（无重复元素） 数组长度
//  要求输出：调用print_array(int *arr, int n)输出前三次选择操作后的序列，以及最终的升序序列
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    // 实现选择排序
    for (int i = 0; i < n - 1; ++i) {
        // 查找剩余未排序部分的最小元素
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // 将找到的最小元素与当前位置的元素交换
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }

        // 在前三次选择操作（即前三次交换或确定位置）后打印数组
        if (i < 3) {
            print_array(arr, n);
        }
    }

    // 打印最终的升序数组
    print_array(arr, n);

    /********** End **********/
}