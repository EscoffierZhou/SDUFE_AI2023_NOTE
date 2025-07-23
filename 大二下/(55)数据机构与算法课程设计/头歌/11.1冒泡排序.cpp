//
//  sort_.cpp
//  Sort
//
//  Created by ljpc on 2018/4/20.
//  Copyright © 2018年 ljpc. All rights reserved.
//

// #include "sort_.h"
#include<algorithm>

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

{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    // Implement Bubble Sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (i < 3) {
            print_array(arr, n);
        }
    }

    // Print the final sorted array
    print_array(arr, n);

    
    /********** End **********/
}


