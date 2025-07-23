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
// 编程实现《桶排序算法》
{
    /********** Begin *********/
    if (n <= 0) return NULL;

    // 找最大最小值以决定桶的分布范围
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int bucketCount = n; // 通常设置为数组长度
    int bucketRange = (max - min + 1 + bucketCount - 1) / bucketCount; // 每个桶的区间大小

    // 创建桶（每个桶用一个动态数组）
    int** buckets = (int**)malloc(bucketCount * sizeof(int*));
    int* bucketSizes = (int*)calloc(bucketCount, sizeof(int));
    int* bucketCapacities = (int*)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketCapacities[i] = 4; // 初始容量
        buckets[i] = (int*)malloc(bucketCapacities[i] * sizeof(int));
    }

    // 分配元素到桶
    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min) / bucketRange;
        if (index >= bucketCount) index = bucketCount - 1;

        // 扩容
        if (bucketSizes[index] >= bucketCapacities[index]) {
            bucketCapacities[index] *= 2;
            buckets[index] = (int*)realloc(buckets[index], bucketCapacities[index] * sizeof(int));
        }

        buckets[index][bucketSizes[index]++] = arr[i];
    }

    // 对每个桶进行排序（使用快速排序）
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 1) {
            // 使用标准库qsort对桶排序
            qsort(buckets[i], bucketSizes[i], sizeof(int), [](const void* a, const void* b) {
                return (*(int*)a - *(int*)b);
            });
        }
    }

    // 合并桶中元素
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucketSizes);
    free(bucketCapacities);

    return arr;
    /********** End **********/
}



