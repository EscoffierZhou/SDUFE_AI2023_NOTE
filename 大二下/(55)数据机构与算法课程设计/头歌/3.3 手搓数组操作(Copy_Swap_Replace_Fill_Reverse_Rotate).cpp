#include <algorithm>
using namespace std;
//#include "code.h"

int* Copy_N(int *arr, int n)
// 函数功能：复制数组arr中前n个元素并作为函数返回值
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (n <= 0 || arr == nullptr) {
        return nullptr;
    }
    // 动态分配新数组
    int* new_arr = new int[n];
    std::copy(arr, arr + n, new_arr);
    return new_arr;
    /********** End **********/
}

void Swap(int &a, int &b)
// 函数功能：交换参数x和参数y
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    swap(a, b);
    /********** End **********/
}

void Replace(int *arr, int n, int x, int y)
// 函数功能：在数组arr中将元素x替换为y，其中n为数组个数
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    replace(arr, arr + n, x, y);
    /********** End **********/
}

void Fill(int *arr, int n, int z)
// 函数功能：将大小为n的数组的所有元素填充为元素z
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    fill(arr, arr + n, z);
    /********** End **********/
}

void Reverse(int *arr, int n)
// 函数功能：倒置数组arr的元素，比如1 2 3，变为3 2 1，其中n为数组个数
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    reverse(arr, arr + n);
    /********** End **********/
}

void Rotate(int *arr, int n, int m)
// 函数功能：向左边滚动m个元素，并补到数组右边，比如 1 2 3 4，滚动m=2个元素，结果为3 4 1 2，其中n=4是数组个数
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (n <= 0) return;
    m = m % n;
    if (m < 0) m += n;
    rotate(arr, arr + m, arr + n);
    /********** End **********/
}
