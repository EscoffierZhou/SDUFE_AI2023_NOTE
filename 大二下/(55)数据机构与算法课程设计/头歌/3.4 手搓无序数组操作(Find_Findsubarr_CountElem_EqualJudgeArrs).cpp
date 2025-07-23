//#include "code.h"
#include <algorithm>
using namespace std;
int* Find(int *first, int *last, int x)
// 函数功能：给定数组首地址和尾地址，若x在数组中，返回第一个x所在的地址，否则返回尾地址
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    return find(first, last, x);

    /********** End **********/
}

int* Find_End(int *arr1, int n1, int *arr2, int n2)
// 函数功能：给定数组arr1，个数n1，数组arr2，个数n2，
//         若数组arr2在数组arr1中出现（连续），则返回数组arr2[0]在arr1中最后一次出现的地址
//         否则，返回数组arr1尾地址，即arr1+n1
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (n2 > n1 || n2 <= 0) {
        return arr1 + n1;
        // 如果 arr2 比 arr1 长或 arr2 为空，不可能找到，直接返回尾地址
    }
    int* result = find_end(arr1, arr1 + n1, arr2, arr2 + n2);
    return result == arr1 + n1 ? arr1 + n1 : result;

    /********** End **********/
}

int Count(int *first, int *last, int x)
// 函数功能：给定数组首地址和尾地址，统计数组中元素x的个数，并返回
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    return count(first, last, x);

    /********** End **********/
}

bool Equal(int *arr1, int n1, int *arr2)
// 函数功能：给定数组arr1，个数n1，数组arr2，(两个数组个数相同)，判断两个数组是否相等
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    return equal(arr1, arr1 + n1, arr2);
    /********** End **********/
}
