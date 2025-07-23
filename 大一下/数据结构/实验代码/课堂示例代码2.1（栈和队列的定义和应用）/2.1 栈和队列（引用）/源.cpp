#include<iostream>  
#include<stdlib.h>
using namespace std;//标准格式化输出
#define MAX_SIZE 100
#define Status int 
#define OVERFLOW -1
#define OK 0
#define ERROR -2
#define EXTENSION_SIZE 10
typedef int s_Elemtype;
typedef struct {    //定义栈的结构体
    s_Elemtype* base;//定义基指针
    s_Elemtype* top; //定义顶指针（注：按照分配顺序，top指针在base指针后一位）

    int stacksize;//定义栈的大小
}Sqstack;//重命名为Sqstack

Status Init_Stack(Sqstack& s) {//初始化栈
    s.base = new s_Elemtype[MAX_SIZE];//使用base指针和new方法拓展一个MAX_SIZE*sizeof(s_Elemtype)的空间
    //s.base = (s_Elemtype*)malloc(MAX_SIZE * sizeof(s_Elemtype));是一样的
    if (!s.base) exit(OVERFLOW);//初始化失败，返回-1
    s.top = s.base;//将base指针的位置赋给top指针
    s.stacksize = MAX_SIZE;//定义stacksize的目的：记录栈的大小
    return OK;//返回0
}

Status Stack_Push(Sqstack& s, s_Elemtype e) {//栈元素的插入
    if (s.top - s.base == s.stacksize) { // 栈已满，进行栈的扩展
        s_Elemtype* newBase = (s_Elemtype*)realloc(s.base, (s.stacksize + EXTENSION_SIZE) * sizeof(s_Elemtype));//使用realloc函数重新分配一个size+1的位置
        if (!newBase) {//如果realloc函数分配失败（内存太小或者其他的什么东西）
            return ERROR;
        }
        s.base = newBase;//base指针到新的base域？
        s.top = s.base + s.stacksize;//top要再base的基础上加上目前栈的大小
        s.stacksize += 1;//此时栈的大小加1（目的是给新元素腾地方）
    }
    *s.top++ = e;//将e元素的值赋值给刚刚开辟的空间中
    return OK;//返回正确
}

Status Stack_Pop(Sqstack& s, s_Elemtype& e) {//栈元素的弹出
    if (s.top == s.base) return ERROR;//如果没有元素，返回错误
    e = *--s.top;//将删除的元素赋值给e，因为是引用，原e直接对应赋值
    return OK;//返回成功
}

Status Stack_DetTop(Sqstack& s, s_Elemtype& e) {//栈顶元素的弹出
    if (s.top != s.base) {//如果栈内存在元素才执行此操作
        e = *(s.top - 1);//将栈顶元素的值赋给e
        return OK;//返回完成
    }
    return ERROR;//否则未完成操作
}

int main() {
    Sqstack stack1, stack2;//新建两个栈，目的是后面调换的时候用，避免栈1元素的丢失
    Init_Stack(stack1);//初始化栈1
    Init_Stack(stack2);//初始化栈2
    cout << "-------------------------" << endl;
    cout << "Insert the number of elements you want to push into the stack:" << endl;
    int num1; cin >> num1;//定义num1，然后插入num1
    cout << "-------------------------" << endl;
    cout << "Insert the elements you want to push into the stack:" << endl;
    for (int i = 1; i <= num1; i++) {//插入num1个元素
        int ele1; cin >> ele1;
        Stack_Push(stack1, ele1);
    }
    cout << "-------------------------" << endl;
    cout << "The elements of the stack are as follows: " << endl;//输出栈1的所有元素（此时会发现都是倒着输出的）
    int cnt = 0;
    s_Elemtype topElement;//删除栈顶元素
    while (stack1.top != stack1.base) {//将栈1的所有元素输出，同时压入栈2
        Stack_Pop(stack1, topElement);
        Stack_Push(stack2, topElement);
        cnt++;
        cout << topElement << " ";//输出栈1的元素
    }
    for (int j = 0; j < cnt; j++) {//再将刚刚栈2压入的元素导入回栈1，此时栈1相当于没有变化
        Stack_Pop(stack2, topElement);
        Stack_Push(stack1, topElement);
    }
    cout << "" << endl;
    cout << "-------------------------" << endl;
    cout << "The top element of the stack is: "<<endl;//输出栈顶元素
    if (Stack_DetTop(stack1, topElement) == OK) {//看返回值如果是OK对应的值就输出栈顶元素
        cout << topElement << endl;
    }
    else {//否则栈就是空的
        cout << "Stack is empty!" << endl;
    }
    cout << "-------------------------" << endl;

    return 0;//结束程序
}