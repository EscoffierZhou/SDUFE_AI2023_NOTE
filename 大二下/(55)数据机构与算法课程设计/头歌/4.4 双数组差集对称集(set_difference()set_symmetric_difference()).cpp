// 一定要记得排序!!实例2和3都需要排序(其中一个是一个没排序.一个是都没排序)
#include<iostream>
#include<algorithm>
using namespace std;

int Set_Difference(int *arr1, int n1, int *arr2, int n2, int *arr3)
// 函数功能：给定两个数组arr1和arr2，计算arr1-arr2的差集，然后存在数组arr3中，并返回差集大小
// 参数介绍：arr1数组一的首地址，n1数组一的个数，arr2数组二的首地址，n2数组二的个数，数组arr3
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    sort(arr1,arr1+n1);
    sort(arr2,arr2+n2);
    int n = set_difference(arr1, arr1 + n1, arr2, arr2 + n2, arr3) - arr3;
    return n;

    /********** End **********/
}


int Set_Symmetric_Difference(int *arr1, int n1, int *arr2, int n2, int *arr3)
// 函数功能：给定两个数组arr1和arr2，计算（arr1-arr2）U（arr2-arr1），然后存在数组arr3中，最后数组大小
// 参数介绍：arr1数组一的首地址，n1数组一的个数，arr2数组二的首地址，n2数组二的个数，数组arr3
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    sort(arr1,arr1+n1);
    sort(arr2,arr2+n2);
    int n = set_symmetric_difference(arr1, arr1 + n1, arr2, arr2 + n2, arr3) - arr3;
    return n;

    /********** End **********/
}
