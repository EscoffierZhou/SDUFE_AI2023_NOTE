#include<iostream>
#include <algorithm>
#define MAX_SIZE 10006
using namespace std;

// 给定N个整数的升序 S(a_1,a_2,\cdots,a_n)
// 给定M个查询序列  Q(b_1,b_2,\cdots,b_n)
// 求b_j在序列S中的闭区间位置
// 例如2在升序序列1，2，2，3中的闭区间位置为[1,2]

/* lower_bound
    template <class ForwardIterator, class T>
    bool binary_search (ForwardIterator first, ForwardIterator last, const T& val){
         first = std::lower_bound(first,last,val);
         return (first!=last && !(val<*first));
    }
    // 作用:查找有序区间中第一个大于或等于某给定值的元素的位置
    // int arr[5] = {1,2,2,4,5};
    // int a = lower_bound(arr, arr+5, 2) - arr; // a结果为1
        // 这里lower_bound返回的是int*即序列
 */

/* upper_bound
    // 作用:查找有序区间中第一个大于某给定值的元素的位置
    // int arr[5] = {1,2,2,4,5};
    // int b = upper_bound(arr, arr+5, 2) - arr; // b结果为3
*/

/* equal_range
    // 作用:equal_range综合了lower_bound和upper_bound的功能，
           通过内部调用这两个上下界查找函数,返回两个地址并组成pair
    // !!!!equal_range返回的是一个左闭右开的区间位置。!!!!
    // int arr[5] = {1,2,2,4,5};
    // auto bounds = equal_range(arr, arr+5, 2);
    // int a = bounds.first-arr; // a结果为1
    // int b = bounds.second-arr; // b结果为3
*/

//
//  main.cpp
//  step2
//
//  Created by ljpc on 2018/7/8.
//  Copyright © 2018年 ljpc. All rights reserved.
//

int main(int argc, const char * argv[])
{

    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int n,m,num,temp;
    cin>>n;
    int arr[MAX_SIZE];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // sort(arr, arr + n);
    cin>>m;
    for(int j=0;j<m;j++){
        cin>>temp;
        auto bounds = equal_range(arr, arr+n, temp);
        int a = bounds.first-arr;
        int b = bounds.second-arr;
        cout<<temp<<" at order array position ["<<a<<","<<b<<"]"<<endl;
    }

    /********** End **********/

    return 0;
}
