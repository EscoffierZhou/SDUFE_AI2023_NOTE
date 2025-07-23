/*
大数存储
    使用数组或 vector 保存大数，每个元素保存一个数字（通常按低位在前，高位在后存储）。
大数乘法
    对于从 1 到 n 的每个整数，依次将当前大数与该整数相乘。
    设当前大数存储在数组 digits 中，初始值为 1。
    对于乘数 i，从 1 到 n 执行：
    初始化进位 carry 为 0。
    遍历数组中的每一位，计算：
        temp = digits[j] * i + carry
        digits[j] = temp % 10
        carry = temp / 10
    当遍历结束后，若 carry 不为 0，则将 carry 的各位依次放入数组（扩展大数长度）。
统计数字 0 的个数
    将大数（数组）转换为字符串（或者直接遍历数组），统计所有数字中 0 的个数即可。
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int calc(int n)
{
    // 请在这里补充代码，完成本关任务
    /********* Begin *********/
    vector<int> digits;
    digits.push_back(1);

    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < digits.size(); j++) {
            int temp = digits[j] * i + carry;
            digits[j] = temp % 10;
            carry = temp / 10;
        }
        // 处理最后的进位
        while (carry > 0) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    // 统计0的个数
    int countZero = 0;
    for (int digit : digits) {
        if (digit == 0)
            countZero++;
    }
    return countZero;
    /********* End *********/
}