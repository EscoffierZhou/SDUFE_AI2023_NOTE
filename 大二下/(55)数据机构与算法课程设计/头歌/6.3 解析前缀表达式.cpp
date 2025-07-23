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
    return 0;
}

int main() {
    string s;
    getline(cin, s);

    stack<int> stk_cal;
    for (int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];
        if (isdigit(c)) {
            stk_cal.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*') {
            int op1 = stk_cal.top(); stk_cal.pop();
            int op2 = stk_cal.top(); stk_cal.pop();
            int result = calculate(op1, op2, c);
            stk_cal.push(result);
        }
    }

    cout << stk_cal.top() << endl;
    return 0;
}
