#include<iostream>
#include<string>
#include<cstdlib> // For malloc and realloc
#include<cstdio>
using namespace std;

#define OK 1
#define ERROR -1
#define INIT_SIZE 100
#define EXTENSION_SIZE 10
typedef int Status;
typedef int s_Elemtype;
typedef struct {
    s_Elemtype* base; // 栈的基址
    s_Elemtype* top;  // 栈顶指针
    int stacksize;    // 当前栈的大小
} Sqstack;

// 初始化栈
Status STACK_INIT(Sqstack& s) {
    s.base = (s_Elemtype*)malloc(sizeof(s_Elemtype) * INIT_SIZE); // 为栈分配初始内存
    if (!s.base) return ERROR; // 内存分配失败
    s.top = s.base; // 栈顶指针指向栈底
    s.stacksize = INIT_SIZE; // 设置初始栈大小
    return OK;
}

// 入栈操作
Status STACK_PUSH(Sqstack& s, s_Elemtype e) {
    if (s.top - s.base == s.stacksize) { // 栈满时需要扩展内存
        s_Elemtype* newbase = (s_Elemtype*)realloc(s.base, (s.stacksize + EXTENSION_SIZE) * sizeof(s_Elemtype)); // 扩展内存
        if (!newbase) return ERROR; // 扩展失败
        s.base = newbase; // 更新栈基址
        s.top = s.base + s.stacksize; // 更新栈顶指针
        s.stacksize += EXTENSION_SIZE; // 更新栈大小
    }
    *s.top++ = e; // 将元素入栈
    return OK;
}

// 出栈操作
Status STACK_POP(Sqstack& s, s_Elemtype& e) {
    if (s.top == s.base) return ERROR; // 栈空时无法出栈
    e = *--s.top; // 将栈顶元素出栈
    return OK;
}

int main() {
    cout << "--------------------------------------" << endl;
    cout << "This is the homework from Zhouxing in AI2302" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Ok, now you can insert the numbers you want to trans" << endl;
    Sqstack stack1;
    STACK_INIT(stack1); // 初始化栈
    int x, y;
    cin >> x;
    cout << "The number required is " << x << endl;

    // 将十进制数转换为八进制数并入栈
    while (x != 0) {
        y = x % 8;
        STACK_PUSH(stack1, y); // 将余数入栈
        x /= 8; // 更新商作为下一轮计算的被除数
    }

    int e, a[100], cnt = 0;
    cout << "--------------------------------------" << endl;
    cout << "Well, the % process is as follows" << endl;
    // 依次出栈并输出各位八进制数字
    while (STACK_POP(stack1, e) != ERROR) {
        cout << e << endl;
        a[cnt] = e; // 将出栈的元素保存到数组中
        cnt++; // 统计出栈元素个数
    }

    cout << "--------------------------------------" << endl;
    cout << "The final answer is " << endl;
    // 逆序输出数组中的八进制数字，得到最终结果
    for (int j =0; j < cnt ; j++) {
        cout << a[j];
    }

    return 0;
}