//
//  main.cpp
//  step1
//
//  Created by ljpc on 2018/7/8.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{

    int n, m, num;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end()); // 对 vector 进行排序

    cin >> m;
    for (int j = 0; j < m; ++j) {
        cin >> num;
        bool result = binary_search(vec.begin(), vec.end(), num); // 正确使用 std::binary_search
        if (result) {
            cout << num << " in array" << std::endl;
        } else {
            cout << num << " not in array" << std::endl;
        }
    }
    return 0;
}
/*
测试输入：
7
2 5 9 5 5 3 1
3
4 7 5

预期输出：
4 not in array
7 not in array
5 in array

输入格式：
第一行：序列元素个数N
第二行：N个无序序列元素
第三行：查询次数M
第四行：M个待查询元素
 */