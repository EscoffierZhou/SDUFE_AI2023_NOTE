#include <iostream>
#include <cstdlib>
using namespace std;
#define Status int
#define OK 0
#define ERROR -2
typedef int s_Elemtype;
typedef struct StackNode {//初始化链节的结构体
    s_Elemtype data;//定义数据域
    struct StackNode* next;//定义指针域
} StackNode;//重命名链表

typedef struct {
    StackNode* top;//链表的栈需要双指针同时探测
} LinkStack;

Status Init_Stack(LinkStack& s) {//初始化链表
    s.top = NULL;//top指针指向栈的最后一个NULL指针（相当于指向节点，和base并列）
    return OK;//返回OK
}

Status Stack_Push(LinkStack& s, s_Elemtype e) {//将元素压入栈中
    StackNode* newNode = new StackNode;//创建新节点
    if (!newNode) {//如果创建失败了
        exit(ERROR);//直接退出程序
    }
    newNode->data = e;//其中将e的值赋给data
    newNode->next = s.top;//反向指针指回节点，这也是为什么输出时是反的
    //一般正向的是newNOde -> next = top -> next
    s.top = newNode;//top指针往下一个节点走
    return OK;//返回OK
}

Status Stack_Pop(LinkStack& s, s_Elemtype& e) {//将栈顶元素弹出
    if (s.top == NULL) {//如果top指针还是空的，以为此时栈内没有元素
        return ERROR;//返回错误
    };
    e = s.top->data;//使用引用将栈顶元素赋值给e
    s.top = s.top->next;//top指针向下走一位
    return OK;//返回正确值
}

Status Stack_DetTop(LinkStack& s, s_Elemtype& e) {//删除栈顶元素
    if (s.top != NULL) {//如果top指针不是NULL，意味着此时stack里面有元素
        e = s.top->data;//那么将栈顶元素赋值给e
        return OK;//返回正确
    }
    return ERROR;//否则，栈内没有元素，返回错误
}

int main() {
    LinkStack stack1, stack2;//定义两个新的栈，stcak1和stack2
    Init_Stack(stack1);//初始化栈1
    Init_Stack(stack2);//初始化栈2，目的还是保留栈1内的元素，避免释放栈1后消失
    cout << "-------------------------" << endl;
    cout << "Insert the number of elements you want to push into the stack:" << endl;//输入要插入栈元素的个数
    int num1;cin >> num1;
    cout << "-------------------------" << endl;
    cout << "Insert the elements you want to push into the stack:" << endl;//输入要插入的元素
    for (int i = 1; i <= num1; i++) {
        int ele1;cin >> ele1;
        Stack_Push(stack1, ele1);
    }
    cout << "-------------------------" << endl;
    cout << "The elements of the stack are as follows: " << endl;//输出stack1内的元素，此时栈1和栈2相互倒
    int cnt = 0;//记录输出次数，便于倒回
    s_Elemtype topElement;
    while (stack1.top != NULL) {//将stack1的元素输出完
        Stack_Pop(stack1, topElement);//将stack1的元素弹出的同时压入stack2
        Stack_Push(stack2, topElement);
        cnt++;
        cout << topElement << " ";//输出
    }
    for (int j = 0; j < cnt; j++) {//将stack2的元素再倒回stack1
        Stack_Pop(stack2, topElement);
        Stack_Push(stack1, topElement);
    }
    cout << "" << endl;
    cout << "-------------------------" << endl;
    cout << "The top element of the stack is:\n ";//输出栈顶元素
    if (Stack_DetTop(stack1, topElement) == OK) cout << topElement << endl;
    else cout << "Stack is empty!" << endl;
    cout << "-------------------------" << endl;
    return 0;
}