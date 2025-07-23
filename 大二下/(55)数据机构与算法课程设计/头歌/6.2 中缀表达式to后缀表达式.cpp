#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
// std::stack:双端deque的数据结构(可用其它线性结构替代:list和vector)
// 一系列方法:
//  声明线性栈:stack<int>mystack;
//  栈加入元素:mystack.push(num)
//  栈大小: mystack.size()
//  判断栈非空:while(!mystack.emtpy){}
//  获取栈顶元素:mystack.top()
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // 其他情况，例如括号或非运算符字符，优先级最低
}
int main(int argc, const char * argv[]) {
    stack<char>s1;
    stack<char>s2;
    string s,last;
    vector<char>result;
    getline(cin,s);
    for(char c:s){
        if(isdigit(c)) {
            result.push_back(c);
        }else if(c=='(') {
            s1.push(c);
        }else if(c==')'){
            while(!s1.empty() && s1.top() != '(') {
                result.push_back(s1.top());
                s1.pop();
            }
            if (!s1.empty()) {
                s1.pop();
            }
        }else{
            while (!s1.empty() && s1.top() != '(' && precedence(c) <= precedence(s1.top())) {
                result.push_back(s1.top());
                s1.pop();
            }
            s1.push(c);
        }
    }
    while (!s1.empty()) {
        result.push_back(s1.top());
        s1.pop();
    }
    for (char c : result) {
        last += c;
    }
    cout<<last<<endl;
    return 0;
}
//1+((2+3)*4)-5
//123+4*+5-