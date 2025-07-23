// 先排序后合并的时间复杂度更低

/*
    merge函数:
    int arr1[3] = {1,2,3};
    int arr2[4] = {2,3,4,5};
    int arr3[7];
    merge(arr1, arr1+n1, arr2, arr2+n2, arr3);
    \\ arr3结果为{1,2,2,3,3,4,5}
 */

//
//  code.cpp
//  step1
//
//  Created by ljpc on 2018/7/17.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include<algorithm>
#include<iostream>
using namespace std;

int* Merge_Array(int *arr1, int n1, int *arr2, int n2)
// 函数功能：合并两个数组arr1和arr2，完成升序排序，返回排序后的合并数组
// 参数介绍：arr1数组一的首地址，n1数组一的个数，arr2数组二的首地址，n2数组二的个数
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    // 动态分配新数组,将所有元素输入到一个数组中,然后排序,最后返回总数组
    int *merged_arr = new int[n1 + n2];
    for (int i = 0; i < n1; ++i) {
        merged_arr[i] = arr1[i];
    }
    for (int i = 0; i < n2; ++i) {
        merged_arr[n1 + i] = arr2[i];
    }
    sort(merged_arr, merged_arr + n1 + n2);
    return merged_arr;
    /********** End **********/
}


//int main() {
//    int arr1[] = {5, 2, 8, 1, 9};
//    int n1 = sizeof(arr1) / sizeof(arr1[0]);
//    int arr2[] = {3, 7, 4, 6};
//    int n2 = sizeof(arr2) / sizeof(arr2[0]);
//
//    int *merged_sorted_arr = Merge_Array(arr1, n1, arr2, n2);
//
//    if (merged_sorted_arr != nullptr) {
//        std::cout << "合并并排序后的数组: ";
//        for (int i = 0; i < n1 + n2; ++i) {
//            std::cout << merged_sorted_arr[i] << " ";
//        }
//        std::cout << std::endl;
//        delete[] merged_sorted_arr; // 释放动态分配的内存，避免内存泄漏
//        merged_sorted_arr = nullptr; // 良好的习惯，将指针置空
//    } else {
//        std::cout << "合并失败，输入数组可能为空或大小无效。" << std::endl;
//    }
//
//    return 0;
//}