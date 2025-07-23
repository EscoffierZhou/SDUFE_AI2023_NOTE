//
//  sort_.cpp
//  Sort
//
//  Created by ljpc on 2018/4/20.
//  Copyright © 2018年 ljpc. All rights reserved.
//

//#include "sort_.h"
#include "cstdio"

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
//  编程实现《希尔排序算法》：将乱序序列arr转化为升序序列
//  函数参数：乱序整数数组 数组长度
//  要求输出：调用print_array(int *arr, int n)输出三遍增量排序操作后的序列，以及最终的升序序列
{
    /********** Begin *********/
    int gaps[3] = {5, 2, 1}; // 指定增量序列

    for (int g = 0; g < 4; g++) {
        int gap = gaps[g];
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        print_array(arr, n); // 输出每次增量排序后的数组
    }
    /********** End **********/
}





