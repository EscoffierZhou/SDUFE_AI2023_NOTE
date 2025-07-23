#include <iostream>
#include <stack>
#include <string>

using namespace std;

int calculate(int op1, int op2, char op) {
    if (op == '+') {
        return op1 + op2;
    } else if (op == '-') {
        return op1 - op2;
    } else if (op == '*') {
        return op1 * op2;
    }
    return 0; // 避免编译器警告
}

int main() {
    string s;
    getline(cin, s);  // 读取后缀表达式

    stack<int> stk_cal;  // 存放计算的数值
    for (char c : s) {   // 从左向右遍历
        if (isdigit(c)) {
            stk_cal.push(c - '0');  // 转换成整数并压栈
        } else if (c == '+' || c == '-' || c == '*') {  // 处理运算符
            int op2 = stk_cal.top(); stk_cal.pop();  // 先弹出的作为第二个操作数
            int op1 = stk_cal.top(); stk_cal.pop();  // 再弹出的作为第一个操作数
            int result = calculate(op1, op2, c);
            stk_cal.push(result);
        }
    }

    cout << stk_cal.top() << endl;  // 输出计算结果
    return 0;
}
