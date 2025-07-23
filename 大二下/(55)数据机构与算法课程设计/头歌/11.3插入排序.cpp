//
//  sort_.cpp
//  Sort
//
//  Created by ljpc on 2018/4/20.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "sort_.h"
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
//  编程实现《插入排序算法》：将乱序序列arr转化为升序序列
//  函数参数：乱序整数数组（无重复元素） 数组长度
//  要求输出：调用print_array(int *arr, int n)输出前三次插入操作后的序列，以及最终的升序序列
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    // 实现插入排序
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // 当前要插入的元素
        int j = i - 1;    // 已排序部分的最后一个元素的索引

        // 将已排序部分中大于key的元素向后移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // 将key插入到正确的位置
        arr[j + 1] = key;
        // 在前三次插入操作（即 i = 1, 2, 3 时）后打印数组
        if (i <= 3) {
             print_array(arr, n);
        }
    }


    print_array(arr, n);

    /********** End **********/
}